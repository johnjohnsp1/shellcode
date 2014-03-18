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
 ; Binary:  jwasm -bin rc4.asm
 ;
 ;
  
.686
.model flat, C

.data

; structure used to keep state, x and y
RC4_KEY struct
    x dword ?
    y dword ?
    s byte 256 dup (?)
RC4_KEY ends

.code
    
    public _rc4_set_key
    public rc4_set_key

_rc4_set_key:
rc4_set_key:    
    mov   eax, esp
    pushad
    mov   edi, [eax+4]           ; rc4_key
    mov   ebp, [eax+8]           ; key_len
    mov   esi, [eax+12]          ; key
    mov   ecx, ebp               ; key_idx = key_len
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
    
    public _rc4
    public rc4
    
_rc4:
rc4:
    mov   eax, esp
    pushad
    mov   esi, [eax+4]      ; rc4key
    mov   ecx, [eax+8]      ; data_len
    mov   edi, [eax+12]     ; uint8_t *p = data
    push  esi               ; save pointer to rc4key
    lodsd                   ; eax = x
    xchg  eax, ebx      
    lodsd                   ; ebx = y
    xchg  eax, ebx
    cdq
crypt_loop:
    inc   al                ; x++
    mov   dl, [esi+eax]     ; cl = s[x]
    add   bl, dl            ; y += cl
    xchg  dl, [esi+ebx]     ; s[y] = s[x]
    mov   [esi+eax], dl     ; s[x] = s[y]
    add   dl, [esi+ebx]     ; cl = s[x] + s[y]
    mov   dl, [esi+edx]     ; dl = s[ cl ]
    xor   byte ptr[edi], dl ; *p ^= (s[ s[x] + s[y] ])
    inc   edi               ; p++    
    loop  crypt_loop
    pop   edi               ; edi = rc4key
    stosd                   ; save x
    xchg  eax, ebx 
    stosd                   ; save y
    popad
    ret

    end
