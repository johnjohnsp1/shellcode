
/* Copyright (c) 2014 Kevin Devine */
/* Size = 53 bytes */

char rc4[] = {
  /* 0000 */  "\x8B\xC4"      /*  mov eax, esp                 */
  /* 0002 */  "\x60"          /*  pushad                       */
  /* 0003 */  "\x8B\x70\x04"  /*  mov esi, dword ptr [eax+04h] */
  /* 0006 */  "\x8B\x68\x08"  /*  mov ebp, dword ptr [eax+08h] */
  /* 0009 */  "\x8B\x78\x0C"  /*  mov edi, dword ptr [eax+0Ch] */
  /* 000C */  "\x56"          /*  push esi                     */
  /* 000D */  "\xAD"          /*  lodsd                        */
  /* 000E */  "\x93"          /*  xchg eax, ebx                */
  /* 000F */  "\xAD"          /*  lodsd                        */
  /* 0010 */  "\x93"          /*  xchg eax, ebx                */
  /* 0011 */  "\x33\xC9"      /*  xor ecx, ecx                 */
  /* 0013 */  "\x99"          /*  cdq                          */
  /* 0014 */  "\xFE\xC0"      /*  inc al                       */
  /* 0016 */  "\x8A\x0C\x30"  /*  mov cl, byte ptr [eax+esi]   */
  /* 0019 */  "\x02\xD9"      /*  add bl, cl                   */
  /* 001B */  "\x8A\x14\x33"  /*  mov dl, byte ptr [ebx+esi]   */
  /* 001E */  "\x88\x0C\x33"  /*  mov byte ptr [ebx+esi], cl   */
  /* 0021 */  "\x88\x14\x30"  /*  mov byte ptr [eax+esi], dl   */
  /* 0024 */  "\x02\xCA"      /*  add cl, dl                   */
  /* 0026 */  "\x8A\x14\x31"  /*  mov dl, byte ptr [ecx+esi]   */
  /* 0029 */  "\x30\x17"      /*  xor byte ptr [edi], dl       */
  /* 002B */  "\xAE"          /*  scasb                        */
  /* 002C */  "\x4D"          /*  dec ebp                      */
  /* 002D */  "\x75\xE5"      /*  jne 00000014h                */
  /* 002F */  "\x5F"          /*  pop edi                      */
  /* 0030 */  "\xAB"          /*  stosd                        */
  /* 0031 */  "\x93"          /*  xchg eax, ebx                */
  /* 0032 */  "\xAB"          /*  stosd                        */
  /* 0033 */  "\x61"          /*  popad                        */
  /* 0034 */  "\xC3"          /*  ret                          */
};
