
;
; using intel crc32 instruction
;
; Macro: 53556B06
; CRC32: 53556B06

  .686
  .xmm
  .model flat, stdcall

  includelib ws2_32.lib
  includelib kernel32.lib

  option casemap:none

  .nolist
  .nocref

  WIN32_LEAN_AND_MEAN equ 1

  include windows.inc
  include stdio.inc
  
  includelib msvcrt.lib
  
  .list
  .cref
  
  ; Reversed Castagnoli polynomial (0x1edc6f41)
  ; which crc32 instruction uses
  CRC32C_POLY equ 082F63B78h

  mcrc32 macro crc:req, v:req
    crc = crc xor v
    rept 8
      crc = (crc shr 1) xor (CRC32C_POLY and -(crc and 1))
    endm
    exitm <crc>
  endm
  
  hash macro s:req
    local crc
    
    crc = 0
    forc x, <s>
      if @InStr(1, <x>, <!">) eq 0
        crc = mcrc32 (crc, '&x')
      endif
    endm
    
    crc = mcrc32 (crc, 0)
    
    ifdef USE_16
      dw (crc and 0FFFFh)
    else
      dd (crc and 0FFFFFFFFh)
    endif
  endm
  
  CStr macro s:vararg
    local sLabel
    .data
    sLabel db s,0
    .code
    exitm <offset sLabel>
  endm
  
  .data
  api_array label dword
    hash <"WSASocketA">
    
    s db "WSASocketA",0
  .code
  
_code_start:
    
    xor eax, eax
    cdq
    lea esi, [s]
crc32_api:
    lodsb
    crc32 edx, al
    dec eax
    jns crc32_api
    
print_value:
    lea esi, [api_array]
    mov eax, [esi]
    
    invoke printf, CStr(10,"Macro: %08X",10, "CRC32: %08X", 10), eax, edx
    invoke ExitProcess, 0
    
    end _code_start
    
    
