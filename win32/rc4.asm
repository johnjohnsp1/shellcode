 ;
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
 ; To test with rc4_test.cpp:
 ;   jwasm -coff -Cp -c rc4.asm
 ;
 ; Create a binary:  
 ;   jwasm -bin rc4.asm
 ;
 ; The calling convention is fastcall
 ;
  
.686
.model flat

option prologue:none
option epilogue:none

.data

; structure used to keep state, x and y
RC4_KEY struct
    x dword ?
    y dword ?
    s byte 256 dup (?)
RC4_KEY ends

.code

; extern "C" void __fastcall rc4_set_key (size_t key_len, void *key, RC4_KEY_ASM *rc4key);
rc4_set_key proc fastcall key_len:dword, key:dword, rc4key:dword
    mov   eax, esp
    pushad
    mov   edi, [eax+4]           ; rc4_key
    mov   ebp, ecx               ; key_len
    mov   esi, edx               ; key
    xor   eax, eax               ; i=0
    cdq                          ; j=0
    stosd                        ; x=0
    stosd                        ; y=0
init_sbox:
    mov   byte ptr[edi+eax], al  ; s[i] = i
    inc   al                     ; i++
    jnz   init_sbox
init_key:
    cmp   ecx, ebp               ; if (key_idx == key_len)
    jne   $+4
    xor   ecx, ecx               ; key_idx = 0
    mov   bl, [edi+eax]          ; s[i]
    add   dl, bl                 ; j += s[i]
    add   dl, [esi+ecx]          ; j += key[key_idx]
    xchg  bl, [edi+edx]          ; s[j] = s[i]
    mov   [edi+eax], bl          ; s[i] = s[j]
    inc   ecx                    ; key_idx++
    inc   al                     ; i++
    jnz   init_key               ; 
    popad
    ret
rc4_set_key endp
    
; extern "C" void __fastcall rc4 (size_t data_len, void *data, RC4_KEY_ASM *rc4key);
rc4 proc fastcall data_len:dword, data:dword, rc4key:dword
    mov   eax, esp
    pushad
    mov   esi, [eax+4]      ; rc4key
    mov   edi, edx          ; uint8_t *p = data
    push  esi               ; save pointer to rc4key
    lodsd                   ; eax = x
    xchg  eax, ebx      
    lodsd                   ; ebx = y
    xchg  eax, ebx
    cdq
crypt_loop:
    inc   al                ; x++
    mov   dl, [esi+eax]     ; dl = s[x]
    add   bl, dl            ; y += dl
    xchg  dl, [esi+ebx]     ; swap s[y], s[x]
    mov   [esi+eax], dl     ; s[x] = s[y]
    add   dl, [esi+ebx]     ; dl = s[x] + s[y]
    mov   dl, [esi+edx]     ; dl = s[ dl ]
    xor   byte ptr[edi], dl ; *p ^= (s[ s[x] + s[y] ])
    inc   edi               ; p++    
    loop  crypt_loop
    pop   edi               ; edi = rc4key
    stosd                   ; save x
    xchg  eax, ebx 
    stosd                   ; save y
    popad
    ret
rc4 endp

    end
