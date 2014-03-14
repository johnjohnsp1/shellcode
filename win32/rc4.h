
/* Copyright (c) 2014 Kevin Devine */
/* Size = 106 bytes */

char rc4[] = {
  /* 0000 */  "\x8B\xC4"      /*  mov eax, esp                 */
  /* 0002 */  "\x60"          /*  pushad                       */
  /* 0003 */  "\x8B\x78\x04"  /*  mov edi, dword ptr [eax+04h] */
  /* 0006 */  "\x8B\x68\x08"  /*  mov ebp, dword ptr [eax+08h] */
  /* 0009 */  "\x8B\x70\x0C"  /*  mov esi, dword ptr [eax+0Ch] */
  /* 000C */  "\x8B\xCD"      /*  mov ecx, ebp                 */
  /* 000E */  "\x33\xC0"      /*  xor eax, eax                 */
  /* 0010 */  "\xAB"          /*  stosd                        */
  /* 0011 */  "\xAB"          /*  stosd                        */
  /* 0012 */  "\x99"          /*  cdq                          */
  /* 0013 */  "\x88\x04\x38"  /*  mov byte ptr [eax+edi], al   */
  /* 0016 */  "\xFE\xC0"      /*  inc al                       */
  /* 0018 */  "\x75\xF9"      /*  jne 00000013h                */
  /* 001A */  "\x3B\xCD"      /*  cmp ecx, ebp                 */
  /* 001C */  "\x75\x02"      /*  jne 00000020h                */
  /* 001E */  "\x33\xC9"      /*  xor ecx, ecx                 */
  /* 0020 */  "\x8A\x1C\x38"  /*  mov bl, byte ptr [eax+edi]   */
  /* 0023 */  "\x02\xD3"      /*  add dl, bl                   */
  /* 0025 */  "\x02\x14\x31"  /*  add dl, byte ptr [ecx+esi]   */
  /* 0028 */  "\x86\x1C\x3A"  /*  xchg byte ptr [edx+edi], bl  */
  /* 002B */  "\x88\x1C\x38"  /*  mov byte ptr [eax+edi], bl   */
  /* 002E */  "\x41"          /*  inc ecx                      */
  /* 002F */  "\xFE\xC0"      /*  inc al                       */
  /* 0031 */  "\x75\xE7"      /*  jne 0000001Ah                */
  /* 0033 */  "\x61"          /*  popad                        */
  /* 0034 */  "\xC3"          /*  ret                          */
  /* 0035 */  "\x8B\xC4"      /*  mov eax, esp                 */
  /* 0037 */  "\x60"          /*  pushad                       */
  /* 0038 */  "\x8B\x70\x04"  /*  mov esi, dword ptr [eax+04h] */
  /* 003B */  "\x8B\x68\x08"  /*  mov ebp, dword ptr [eax+08h] */
  /* 003E */  "\x8B\x78\x0C"  /*  mov edi, dword ptr [eax+0Ch] */
  /* 0041 */  "\x56"          /*  push esi                     */
  /* 0042 */  "\xAD"          /*  lodsd                        */
  /* 0043 */  "\x93"          /*  xchg eax, ebx                */
  /* 0044 */  "\xAD"          /*  lodsd                        */
  /* 0045 */  "\x93"          /*  xchg eax, ebx                */
  /* 0046 */  "\x33\xC9"      /*  xor ecx, ecx                 */
  /* 0048 */  "\x99"          /*  cdq                          */
  /* 0049 */  "\xFE\xC0"      /*  inc al                       */
  /* 004B */  "\x8A\x0C\x30"  /*  mov cl, byte ptr [eax+esi]   */
  /* 004E */  "\x02\xD9"      /*  add bl, cl                   */
  /* 0050 */  "\x8A\x14\x33"  /*  mov dl, byte ptr [ebx+esi]   */
  /* 0053 */  "\x88\x0C\x33"  /*  mov byte ptr [ebx+esi], cl   */
  /* 0056 */  "\x88\x14\x30"  /*  mov byte ptr [eax+esi], dl   */
  /* 0059 */  "\x02\xCA"      /*  add cl, dl                   */
  /* 005B */  "\x8A\x14\x31"  /*  mov dl, byte ptr [ecx+esi]   */
  /* 005E */  "\x30\x17"      /*  xor byte ptr [edi], dl       */
  /* 0060 */  "\xAE"          /*  scasb                        */
  /* 0061 */  "\x4D"          /*  dec ebp                      */
  /* 0062 */  "\x75\xE5"      /*  jne 00000049h                */
  /* 0064 */  "\x5F"          /*  pop edi                      */
  /* 0065 */  "\xAB"          /*  stosd                        */
  /* 0066 */  "\x93"          /*  xchg eax, ebx                */
  /* 0067 */  "\xAB"          /*  stosd                        */
  /* 0068 */  "\x61"          /*  popad                        */
  /* 0069 */  "\xC3"          /*  ret                          */
};
