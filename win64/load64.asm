 ;  The MIT License:
 ;
 ;  Copyright (c) 2014 Kevin Devine
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
 ;
 ; Current Size = 94 bytes
 
    .x64
    ifndef TEST_CODE
      .model flat, fastcall
    endif
    .code
entrypoint:
    push   rbx
    push   rsi
    push   rdi
    push   rbp
    mov    r15, rsp
    and    rsp, -16
    sub    rsp, 28h
    jmp    init_param
calc_pos:
    push   60h
    pop    rcx
    mov    rsi, [gs:rcx]
    mov    esi, [rsi+18h]
    mov    esi, [rsi+10h]              ; InLoadOrderModuleList
    lodsd                              ; skip ntdll.dll
    mov    esi, [rax]                  ; kernel32.dll
    mov    edi, [rsi+30h]              ; LDR_DATA_TABLE_ENTRY.DllBase    
    add    ecx, dword ptr[rdi+3ch]
    mov    ebx, dword ptr[rdi+rcx+28h]
    
    mov    esi, dword ptr[rdi+rbx+20h]
    add    esi, edi
    
    mov    ecx, dword ptr[rdi+rbx+24h]
    add    ecx, edi
    cdq
find_loop:
    movzx  ebp, word ptr[rcx+2*rdx]
    inc    edx
    lodsd
    cmp    dword ptr[rdi+rax], 'daoL'   ; LoadLibraryA
    jne    find_loop
    cmp    byte ptr[rdi+rax+0bh], 'A'
    jne    find_loop
    
    mov    esi, dword ptr[rdi+rbx+1ch]
    add    esi, edi
    add    edi, [rsi+4*rbp]  
    pop    rcx
    call   rdi
    mov    rsp, r15
    
    pop    rbp
    pop    rdi
    pop    rsi
    pop    rbx
    ret
init_param:
    call  calc_pos
dll_path:
ifdef TEST_CODE
    db 'ws2_32.dll', 00h
endif
    end entrypoint
