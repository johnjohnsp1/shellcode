;;
;; MD5 MACRO v1.0 BY DRIZZ
;;
IFNDEF __JWASM__
.ERR <JWASM IS REQUIRED>
ENDIF

if @WordSize eq 8

.x64p
option frame:auto
option win64:0;disable autosaving of register params to shadow space

@WordType equ <QWORD>
__X86_64__ equ <>

else

.686p
.xmm
.model flat
FRAME equ <>
@WordType equ <DWORD>
rax EQU <EAX>
rbx EQU <EBX>
rcx EQU <ECX>
rdx EQU <EDX>
rsi EQU <ESI>
rdi EQU <EDI>
rbp EQU <EBP>
rsp EQU <ESP>
__X86_32__ equ <>

endif

option language:c
option dotname
option casemap:none
option procalign:16

ifndef SIZE_T
SIZE_T typedef @WordType
endif

ifndef size_t
size_t typedef @WordType
endif

option procalign:16
option renamekeyword:<c>,cdecl

@ArrayLength MACRO arglist:VARARG
    LOCAL count
    count = 0
    FOR arg, <arglist>
        count = count + 1       ;; Count the arguments
    ENDM
    EXITM %count
ENDM

@ArrayValue MACRO index:REQ, arglist:VARARG
    LOCAL count, retstr
    retstr TEXTEQU <>            ;; Initialize count
    count  = 0                   ;; Initialize return string
    FOR arg, <arglist>
        count = count + 1
        IF count EQ index        ;; Item is found
            retstr TEXTEQU <arg> ;; Set return string
            EXITM                ;;   and exit IF
        ENDIF
    ENDM
    EXITM retstr                 ;; Exit function
ENDM

; for int:
;myArr textequ @ArrayAppend(@CatStr(%(__INTEGER__)), %myArr )
; text:
;myArr textequ @ArrayAppend(__TEXT__, %myArr )
@ArrayAppend MACRO value:REQ, arglist:VARARG
    LOCAL count, retstr
    count = @ArrayLength(arglist)
    retstr TEXTEQU <>
    IF count eq 0
retstr CatStr <value>
    ELSE
retstr CatStr <arglist>, <,>, <value>
    ENDIF
    EXITM retstr                 ;; Exit function
ENDM

FFConArr textequ <0D76AA478H, 0E8C7B756H, 0242070DBH, 0C1BDCEEEH, 0F57C0FAFH, 04787C62AH, 0A8304613H, 0FD469501H, 0698098D8H, 08B44F7AFH, 0FFFF5BB1H, 0895CD7BEH, 06B901122H, 0FD987193H, 0A679438EH, 049B40821H>
FFRolArr textequ <7,12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22>
FFIdxArr textequ <0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>
GGConArr textequ <0F61E2562H, 0C040B340H, 0265E5A51H, 0E9B6C7AAH, 0D62F105DH, 002441453H, 0D8A1E681H, 0E7D3FBC8H, 021E1CDE6H, 0C33707D6H, 0F4D50D87H, 0455A14EDH, 0A9E3E905H, 0FCEFA3F8H, 0676F02D9H, 08D2A4C8AH>
GGRolArr textequ <5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20>
GGIdxArr textequ <1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12>
HHConArr textequ <0FFFA3942H, 08771F681H, 06D9D6122H, 0FDE5380CH, 0A4BEEA44H, 04BDECFA9H, 0F6BB4B60H, 0BEBFBC70H, 0289B7EC6H, 0EAA127FAH, 0D4EF3085H, 004881D05H, 0D9D4D039H, 0E6DB99E5H, 01FA27CF8H, 0C4AC5665H>
HHRolArr textequ <4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23>
HHIdxArr textequ <5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2>
IIConArr textequ <0F4292244H, 0432AFF97H, 0AB9423A7H, 0FC93A039H, 0655B59C3H, 08F0CCC92H, 0FFEFF47DH, 085845DD1H, 06FA87E4FH, 0FE2CE6E0H, 0A3014314H, 04E0811A1H, 0F7537E82H, 0BD3AF235H, 02AD7D2BBH, 0EB86D391H>
IIRolArr textequ <6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21>
IIIdxArr textequ <0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9>


md5sum macro message:req
local A,B,C,D,T,i,j,k,val,msgArr,bufval,rolc,constval

;%echo message

T = @SizeStr(message)
IF (T GE 56) OR (T EQ 0)
echo message length must be less than 56 characters or not blank
.err
ENDIF

msgArr textequ <>
i = 0
k = 0
val = 0
forc c,message
j = i and 3
val = val or ('&c' shl (j*8))
if j eq 3
msgArr textequ @ArrayAppend(@CatStr(%(val)), %msgArr )
val = 0
k = k + 1; dwords
endif
i = i + 1
endm

;%echo msgArr

j = i and 3
if j eq 0
; store val, 80h
msgArr textequ @ArrayAppend(@CatStr(%(80h)), %msgArr )
else
val = val + (80h shl (j*8))
msgArr textequ @ArrayAppend(@CatStr(%(val)), %msgArr )
endif

;%echo msgArr

while k lt 15
if k eq 13
msgArr textequ @ArrayAppend(@CatStr(%(i*8)), %msgArr )
else
msgArr textequ @ArrayAppend(@CatStr(%(0)), %msgArr )
endif
k = k + 1; dwords
endm

;%echo msgArr

A = 067452301h
B = 0EFCDAB89h
C = 098BADCFEh
D = 010325476h
T = 0

FFmacro macro
T = C
T = T xor D
T = T and B
T = T xor D
A = (A + bufval) and 0FFFFFFFFh
A = (A + T) and 0FFFFFFFFh
A = (A + constval) and 0FFFFFFFFh
A = ((A shl rolc) and 0FFFFFFFFh) or (A shr (32-rolc))
A = (A + B) and 0FFFFFFFFh
endm

GGmacro macro
T = C
T = T xor B
T = T and D
T = T xor C
A = (A + bufval) and 0FFFFFFFFh
A = (A + T) and 0FFFFFFFFh
A = (A + constval) and 0FFFFFFFFh
A = ((A shl rolc) and 0FFFFFFFFh) or (A shr (32-rolc))
A = (A + B) and 0FFFFFFFFh
endm

HHmacro macro
T = C
T = T xor D
T = T xor B
A = (A + bufval) and 0FFFFFFFFh
A = (A + T) and 0FFFFFFFFh
A = (A + constval) and 0FFFFFFFFh
A = ((A shl rolc) and 0FFFFFFFFh) or (A shr (32-rolc))
A = (A + B) and 0FFFFFFFFh
endm

IImacro macro
T = not D
T = T or B
T = T xor C
A = (A + bufval) and 0FFFFFFFFh
A = (A + T) and 0FFFFFFFFh
A = (A + constval) and 0FFFFFFFFh
A = ((A shl rolc) and 0FFFFFFFFh) or (A shr (32-rolc))
A = (A + B) and 0FFFFFFFFh
endm

; FF
for func,<FF,GG,HH,II>
i = 0
rept 16
j = @ArrayValue(i+1, % @CatStr(func,<IdxArr>))
constval = @ArrayValue(i+1, % @CatStr(func,<ConArr>))
rolc = @ArrayValue(i+1, % @CatStr(func,<RolArr>))
bufval = @ArrayValue(j+1, % msgArr)

func&macro

T = D
D = C
C = B
B = A
A = T
i = i + 1
endm
endm

A = (A + 067452301h) and 0FFFFFFFFh
B = (B + 0EFCDAB89h) and 0FFFFFFFFh
C = (C + 098BADCFEh) and 0FFFFFFFFh
D = (D + 010325476h) and 0FFFFFFFFh

;.radix 16
;%echo @CatStr(%(A))&@CatStr(%(B))@CatStr(%(C))@CatStr(%(D))
;.radix 10

exitm <@CatStr(%(A)),@CatStr(%(B)),@CatStr(%(C)),@CatStr(%(D))>
endm

.data
mystr equ <abc>
mymd5 dd md5sum(%mystr)
vals textequ md5sum(%mystr)

bswapm macro x:req
exitm %((x SHR 24) or ((x SHR 8) and 0FF00h) or ((x SHL 8) and 0FF0000h) or ((x SHL 24) and 0FF000000h))
endm

A = bswapm ( @ArrayValue(1, % vals) )
B = bswapm ( @ArrayValue(2, % vals) )
C = bswapm ( @ArrayValue(3, % vals) )
D = bswapm ( @ArrayValue(4, % vals) )

.radix 16
%echo @CatStr(%(A))&@CatStr(%(B))@CatStr(%(C))@CatStr(%(D))
.radix 10


.code
end
