 ;  The MIT License:
 ;
 ;  Copyright (c) 2004, 2013 Kevin Devine
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

    .386
    .model flat

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
  
    .code
    
    assume fs:nothing
_code_start:
    pushad
    jmp   init_path
load_library:
    ; obtain kernel32.dll base from PEB
    push  30h
    pop   ecx
    mov   esi, [fs:ecx]
    mov   esi, [esi+0ch]
    mov   esi, [esi+0ch]
    lodsd
    mov   esi, [eax]
    mov   ebp, [esi+18h]
    ; get offset of export table
    mov   eax, [ebp+3ch]
    mov   eax, [ebp+eax+78h]
    lea   esi, [ebp+eax+1ch]
    ; calculate RVA of exported api
    mov   cl, 3
load_rva:
    lodsd
    add   eax, ebp
    push  eax
    loop  load_rva
    ; init search
    pop   edi
    pop   esi
    pop   ebx
    ; find LoadLibraryA
find_loop:
    movzx edx, word ptr[edi+2*ecx]
    inc   ecx
    lodsd
    cmp   dword ptr[ebp+eax], 'daoL'
    jne   find_loop
    cmp   byte ptr[ebp+eax+0bh], 'A'
    jne   find_loop
    
    ; found? call it
    add   ebp, [ebx+4*edx]
    call  ebp
    mov   dword ptr[esp][PUSHAD_STRUCT._eax], eax
    popad
    ret
init_path:
    call  load_library
ifdef TEST_CODE
    db 'ws2_32', 00h
endif
    end _code_start
