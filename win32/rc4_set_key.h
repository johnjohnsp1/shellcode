
/* Copyright (c) 2014 Kevin Devine */
/* Size = 49 bytes */

char rc4_set_key[] = {
  /* 0000 */  "\x8B\xC4"      /*  mov eax, esp                 */
  /* 0002 */  "\x60"          /*  pushad                       */
  /* 0003 */  "\x8B\x78\x04"  /*  mov edi, dword ptr [eax+04h] */
  /* 0006 */  "\x8B\xE9"      /*  mov ebp, ecx                 */
  /* 0008 */  "\x8B\xF2"      /*  mov esi, edx                 */
  /* 000A */  "\x33\xC0"      /*  xor eax, eax                 */
  /* 000C */  "\x99"          /*  cdq                          */
  /* 000D */  "\xAB"          /*  stosd                        */
  /* 000E */  "\xAB"          /*  stosd                        */
  /* 000F */  "\x88\x04\x38"  /*  mov byte ptr [eax+edi], al   */
  /* 0012 */  "\xFE\xC0"      /*  inc al                       */
  /* 0014 */  "\x75\xF9"      /*  jne 0000000Fh                */
  /* 0016 */  "\x3B\xCD"      /*  cmp ecx, ebp                 */
  /* 0018 */  "\x75\x02"      /*  jne 0000001Ch                */
  /* 001A */  "\x33\xC9"      /*  xor ecx, ecx                 */
  /* 001C */  "\x8A\x1C\x38"  /*  mov bl, byte ptr [eax+edi]   */
  /* 001F */  "\x02\xD3"      /*  add dl, bl                   */
  /* 0021 */  "\x02\x14\x31"  /*  add dl, byte ptr [ecx+esi]   */
  /* 0024 */  "\x86\x1C\x3A"  /*  xchg byte ptr [edx+edi], bl  */
  /* 0027 */  "\x88\x1C\x38"  /*  mov byte ptr [eax+edi], bl   */
  /* 002A */  "\x41"          /*  inc ecx                      */
  /* 002B */  "\xFE\xC0"      /*  inc al                       */
  /* 002D */  "\x75\xE7"      /*  jne 00000016h                */
  /* 002F */  "\x61"          /*  popad                        */
  /* 0030 */  "\xC3"          /*  ret                          */
};
