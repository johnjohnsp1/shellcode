
; ml64 /c aes128.asm

.code

expand:
    pshufd   xmm1, xmm1, 255
    shufps   xmm4, xmm0, 16
    pxor     xmm0, xmm4
    shufps   xmm4, xmm0, 140
    pxor     xmm0, xmm4
    pxor     xmm0, xmm1
    movdqa   [rdx], xmm0
    add      rdx, 16
    ret
    
  public aes_set_key128

aes_set_key128:
    movdqa   xmm0, [rcx]          ; input
    movdqa   [rdx], xmm0          ; output
    add      rdx, 16
    
    aeskeygenassist xmm1, xmm0, 1
    call     expand
    
    aeskeygenassist xmm1, xmm0, 2
    call     expand
    
    aeskeygenassist xmm1, xmm0, 4
    call     expand
    
    aeskeygenassist xmm1, xmm0, 8
    call     expand
    
    aeskeygenassist xmm1, xmm0, 16
    call     expand
    
    aeskeygenassist xmm1, xmm0, 32
    call     expand
    
    aeskeygenassist xmm1, xmm0, 64
    call     expand
    
    aeskeygenassist xmm1, xmm0, 128
    call     expand
    
    aeskeygenassist xmm1, xmm0, 27
    call     expand
    
    aeskeygenassist xmm1, xmm0, 54
    call     expand
    
    ret
  
  
blks textequ <rcx>
buf  textequ <rdx>
key  textequ <r8>
iv   textequ <r9>

  public aes_encrypt_cbc128

aes_encrypt_cbc128:
    movdqa     xmm0, [iv]
    movdqa     xmm1, [key+ 0*16]
    movdqa     xmm2, [key+ 1*16]
    movdqa     xmm3, [key+ 2*16]
    movdqa     xmm4, [key+ 3*16]
    movdqa     xmm5, [key+ 4*16]
    movdqa     xmm6, [key+ 5*16]
    movdqa     xmm7, [key+ 6*16]
    movdqa     xmm8, [key+ 7*16]
    movdqa     xmm9, [key+ 8*16]
    movdqa     xmm10,[key+ 9*16]
    movdqa     xmm11,[key+10*16]
    xor        eax, eax
encrypt_blocks:
    pxor       xmm0, [buf+rax]
    pxor       xmm0, xmm1
    aesenc     xmm0, xmm2
    aesenc     xmm0, xmm3
    aesenc     xmm0, xmm4
    aesenc     xmm0, xmm5
    aesenc     xmm0, xmm6
    aesenc     xmm0, xmm7
    aesenc     xmm0, xmm8
    aesenc     xmm0, xmm9
    aesenc     xmm0, xmm10
    aesenclast xmm0, xmm11
    movdqa     [buf+rax], xmm0
    add        eax, 16
    loop       encrypt_blocks
    ret
    
    
  public aes_decrypt_cbc128

aes_decrypt_cbc128:
    movdqa     xmm1, [key+ 0*16]
    movdqa     xmm2, [key+ 1*16]
    aesimc     xmm2, xmm2 
    movdqa     xmm3, [key+ 2*16]
    aesimc     xmm3, xmm3
    movdqa     xmm4, [key+ 3*16]
    aesimc     xmm4, xmm4
    movdqa     xmm5, [key+ 4*16]
    aesimc     xmm5, xmm5
    movdqa     xmm6, [key+ 5*16]
    aesimc     xmm6, xmm6
    movdqa     xmm7, [key+ 6*16]
    aesimc     xmm7, xmm7
    movdqa     xmm8, [key+ 7*16]
    aesimc     xmm8, xmm8
    movdqa     xmm9, [key+ 8*16]
    aesimc     xmm9, xmm9
    movdqa     xmm10,[key+ 9*16]
    aesimc     xmm10, xmm10
    movdqa     xmm11,[key+10*16]
    movdqa     xmm12, [iv]
    xor        eax, eax
decrypt_blocks:
    movdqa     xmm0, [buf+rax]
    movdqa     xmm13, xmm0
    pxor       xmm0, xmm11
    aesdec     xmm0, xmm10
    aesdec     xmm0, xmm9
    aesdec     xmm0, xmm8
    aesdec     xmm0, xmm7
    aesdec     xmm0, xmm6
    aesdec     xmm0, xmm5
    aesdec     xmm0, xmm4
    aesdec     xmm0, xmm3
    aesdec     xmm0, xmm2
    aesdeclast xmm0, xmm1
    pxor       xmm0, xmm12
    movdqa     xmm12, xmm13
    movdqa     [buf+rax], xmm0
    add        eax, 16
    loop       decrypt_blocks
    ret
    
    end

