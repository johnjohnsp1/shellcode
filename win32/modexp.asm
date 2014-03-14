; ********************************************************* 
; Modular Exponentiation routine, 209 bytes
; Derived from work originally by Z0MBiE/29a in 2001
; Size optimized by ~17%.
;
; Last modified by Kevin Devine in 2014
; For bug reports, contact me on twitter @cmpxchg8
; *********************************************************
.686
.model flat, C
.code

    public _modexp
    public modexp
; 
; Find the most significant bit in big number
; Return value in edx
;
bitscan:
    push   ebx
    cmovc  ebx, edi      ; ebx = (CF==1) ? p : e
    mov    edx, ecx
    shl    edx, 5        ; edx *= 32
    dec    edx
get_msb:
    bt     [ebx], edx    ; test until bit found
    jc     return_msb
    dec    edx           ; or no more bits left
    jnz    get_msb
return_msb:
    pop    ebx
    ret
; **************************************************
; if (t >= m) t -= m;
; **************************************************
cmpsub:
    pushad
    mov    edi, ebp     ; edi = m
    jc     init_sub
    
    pushad
    std
    dec    ecx
    lea    esi, [esi+4*ecx]
    lea    edi, [edi+4*ecx]
    repz   cmpsd
    cld
    popad
    jc     exit_cmpsub
init_sub:                       ; t == m
    clc
sub_loop:
    lodsd
    sbb    eax, [edi]           ; t -= m
    mov    [esi-4], eax
    lea    edi, [edi+4]
    loop   sub_loop
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
add_loop:                      ; t += x or p
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
    
_modexp:
modexp:
    mov    eax, esp
    pushad
    
    mov    ecx, [eax+4]      ; l
    mov    esi, [eax+12]     ; modify b instead of copying?
    mov    ebx, [eax+16]     ; e
    mov    ebp, [eax+20]     ; m
    mov    eax, [eax+8]      ; x
    
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
    bt     [ebx], eax        ; e & eax
    jnc    sqr_mod
    
    call   mulmod            ; x=(x*p) mod m
    clc
sqr_mod:
    call   mulmod            ; p=(p*p) mod m
    
    inc    eax
    cmp    eax, edx
    jbe    exp_loop
 
    lea    esp, [esp+4*ecx]
    popad
    ret
    
    end
