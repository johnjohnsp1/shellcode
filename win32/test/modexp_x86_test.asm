

; jwasm -I C:\JWasm210bw\WinInc208\include -coff -c -Cp dhx.asm

.686
.model flat, c

    option casemap:none
    .nolist
    .nocref
    WIN32_LEAN_AND_MEAN equ 1
    include <windows.inc>
    include <stdio.inc>
    include <stdlib.inc>
    
    ;includelib <msvcrt.lib>
    includelib <kernel32.lib>
    .list
    .cref
.data

MAX_NUM equ 256 ; 2048 bytes

CStr macro szText:VARARG
  local dbText
.data
dbText db szText, 0
.code
exitm <offset dbText>
endm

modexp32 proto fastcall bitlen:dword, base:dword, exponent:dword, modulus:dword, result:dword

.code

dump_hex proc uses esi edi ebx txt:DWORD, buf:DWORD, len:DWORD
    mov   esi, [buf]
    mov   ebx, [len]
    invoke printf, txt
    .while ebx > 0
      mov eax, [esi+ebx-4]
      invoke printf, CStr("%08X"), eax
      sub ebx, 4
    .endw
    ret
dump_hex endp

do_keyxchg_asm proc uses esi ebx edi p1:DWORD, p_len:DWORD, 
    g1:DWORD, g_len:DWORD, x1:DWORD, x_len:DWORD, y1:DWORD, y_len:DWORD
    
    local A[MAX_NUM+1]:BYTE
    local B[MAX_NUM+1]:BYTE
    local s1[MAX_NUM+1]:BYTE
    local s2[MAX_NUM+1]:BYTE
    local p[MAX_NUM+1]:BYTE
    local g[MAX_NUM+1]:BYTE
    local x[MAX_NUM+1]:BYTE
    local y[MAX_NUM+1]:BYTE
    local maxbits:DWORD
    local maxbytes:DWORD
    
    invoke memset, addr p, 0, MAX_NUM
    invoke memset, addr g, 0, MAX_NUM
    invoke memset, addr x, 0, MAX_NUM
    invoke memset, addr y, 0, MAX_NUM
    
    invoke memcpy, addr p, [p1], [p_len]
    invoke memcpy, addr g, [g1], [g_len]
    invoke memcpy, addr x, [x1], [x_len]
    invoke memcpy, addr y, [y1], [y_len]
    
    invoke printf, CStr(10, "Bitlen = %i"), dword ptr[p_len]
    
    mov   eax, [p_len] ; maxbits = p_len
    mov   ebx, [g_len]
    mov   ecx, [x_len]
    mov   edx, [y_len]
    
    cmp   eax, ebx ; if (maxbits < g_len) maxbits = g_len
    cmovb eax, ebx 
    
    cmp   eax, ecx ; if (maxbits < x_len) maxbits = x_len
    cmovb eax, ecx
    
    cmp   eax, edx ; if (maxbits < y_len) maxbits = y_len
    cmovb eax, edx
    
    mov   [maxbytes], eax
    
    shl   eax, 3   ; eax *= 8
    mov   [maxbits], eax
    
    invoke puts, CStr(10, 10, 
        "*************************************", 10,
        "*** Testing x86 version of modexp ***", 10,
        "*************************************")
        
    ; Alice does g ^ x mod p
    invoke modexp32, [maxbits], addr g, addr x, addr p, addr A
    add   esp, 3*4
    
    ; Bob does g ^ y mod p
    invoke modexp32, [maxbits], addr g, addr y, addr p, addr B
    add   esp, 3*4
    
    ; *************************************
    ; Bob and Alice exchange A and B values
    ; *************************************
    
    ; Alice computes session key
    invoke modexp32, [maxbits], addr B, addr x, addr p, addr s1
    add   esp, 3*4
    
    ; Bob computes session key
    invoke modexp32, [maxbits], addr A, addr y, addr p, addr s2
    add   esp, 3*4
    
    ; s1 + s2 should be equal
    invoke memcmp, addr s1, addr s2, [maxbytes]
    .if eax == 0
      ; use a KDF to generate symmetric key using s1 as input
      invoke printf, CStr(10, 10, "Key exchange succeeded")
      invoke dump_hex, CStr(10, 10, "Session key = "), addr s1, [maxbytes]
    .else
      ; something went wrong..
      invoke printf, CStr(10, "Key exchange failed")
    .endif
    ret
do_keyxchg_asm endp

    end
  
