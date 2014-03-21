; ********************************************************* 
; Modular Exponentiation routine in 205 bytes
; Derived from work by Z0MBiE/29a in 2001
; Size optimized by ~20%.
;
; Last modified by Kevin Devine in 2014
; For bug reports, contact me on twitter @cmpxchg8
; *********************************************************
.686
.model flat

option epilogue:none
option prologue:none

.code

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
; 
; Find the most significant bit in big number
; Return value in edx
;
bitscan:
    pushad
    cmovc  ebx, edi      ; ebx = (CF==1) ? p : e
    shl    ecx, 5        ; ecx *= 32 to get number of bits
get_msb:
    bt     [ebx], ecx    ; test until bit found
    jc     return_msb
    loop   get_msb
return_msb:
    mov    [esp][PUSHAD_STRUCT._edx], ecx
    popad
    ret
; ******************* *******************************
; if (t >= m) t -= m;
; **************************************************
cmpsub:
    pushad
    mov    edi, ebp             ; edi = m
    jb     init_sub             ; we don't need to compare, subtract m
    
    pushad                      ; save registers
    std                         ; move backward
    lodsd                       ; subtract 4
    scasd                       ; subtract 4
    lea    esi, [esi+4*ecx]     ;
    lea    edi, [edi+4*ecx]     ;
    repz   cmpsd                ; compare while equal
    cld                         ; move forward
    popad
    jb     exit_cmpsub          ; exit if esi < edi
init_sub:                       ; t >= m
    clc                         ; clear carry flag
sub_loop:
    lodsd                       ; load word
    sbb    eax, [edi]           ; t -= m
    mov    [esi-4], eax         ; save word
    lea    edi, [edi+4]
    loop   sub_loop             ; word_len--
exit_cmpsub:
    popad
    ret
    
; if CF:1 do x = mulmod (x, p, m)
; if CF:0 do p = mulmod (p, p, m)
mulmod:
    pushad
    mov    eax, esp            ; save esp
    mov    ebx, edi            ; ebx = x
    cmovnc ebx, esi            ; ebx = (CF==1) ? x : p

    ; t = 0
    shl    ecx, 2              ; ecx *= 4 for bytes
    sub    esp, ecx            ; reserve space on stack
    shr    ecx, 2              ; ecx /= 4 for dwords
    mov    edi, esp            ; edi = esp
    pushad
    xor    eax, eax
    rep    stosd               ; zero fill
    popad
    
    xchg   esi, edi            ; edi = p, esi = t
    
    stc
    call   bitscan             ; get bits of p, now in edi
mul_loop:
    clc                        ; clear
    pushad
rcl_loop:                      ; t *= 2
    rcl    dword ptr [esi], 1  
    lodsd
    loop   rcl_loop
    popad
    
    call   cmpsub              ; if (t >= m) t -= m
    
    bt     [edi], edx          ; if (p & bits)
    jnc    dec_bits
    
    clc
    pushad
add_loop:                      ; t += CF ? x : p
    lodsd
    adc    eax, [ebx]
    mov    [esi-4], eax  
    lea    ebx, [ebx+4]
    loop   add_loop
    popad
    
    call   cmpsub              ; if (t >= m) t -= m;
dec_bits:
    dec    edx                 ; --bits
    jns    mul_loop
    
    ; x = t
    mov    edi, ebx
    rep    movsd               ; x = t
    mov    esp, eax            ; restore esp
    popad
    ret
    
modexp32 proc fastcall bitlen:dword, base:dword, exponent:dword, modulus:dword, result:dword
    mov    eax, esp
    pushad
    
    mov    esi, edx          ; base
    mov    ebx, [eax+4]      ; exponent
    mov    ebp, [eax+8]      ; modulus
    mov    eax, [eax+12]     ; result
    
    shr    ecx, 3            ; ecx /= 8 for bytes
    sub    esp, ecx          ; reserve space for copy of b
    mov    edi, esp          ; edi = p
    shr    ecx, 2            ; ecx /= 4 for dwords
    pushad                   ; save
    rep    movsd             ; p = b
    popad                    ; restore
    mov    esi, esp          ; esi = p
    xchg   eax, edi          ; edi = x
    
    ; x = 1
    xor    eax, eax
    pushad
    rep    stosd
    popad
    inc    dword ptr[edi]

    clc                      ; get highest bit of e
    call   bitscan           ; scan ebx
exp_loop:
    bt     [ebx], eax        ; e & 1
    jnc    sqr_mod
    
    call   mulmod            ; x=(x*p) mod m
    clc                      ; load p instead of x
sqr_mod:
    call   mulmod            ; p=(p*p) mod m
    
    inc    eax
    dec    edx
    jns    exp_loop
 
    lea    esp, [esp+4*ecx]  ; free stack
    popad
    ret
modexp32 endp
   
    end
