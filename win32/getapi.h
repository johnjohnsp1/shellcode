
/* Copyright (c) 2014 Kevin Devine */
/* Size = 88 bytes */

char getapi[] = {
  /* 0000 */  "\x60"              /*  pushad                             */
  /* 0001 */  "\x6A\x30"          /*  push 00000030h                     */
  /* 0003 */  "\x5E"              /*  pop esi                            */
  /* 0004 */  "\x64\xAD"          /*  lodsd                              */
  /* 0006 */  "\x8B\x40\x0C"      /*  mov eax, dword ptr [eax+0Ch]       */
  /* 0009 */  "\x8B\x70\x1C"      /*  mov esi, dword ptr [eax+1Ch]       */
  /* 000C */  "\x8B\x6E\x08"      /*  mov ebp, dword ptr [esi+08h]       */
  /* 000F */  "\xAD"              /*  lodsd                              */
  /* 0010 */  "\x50"              /*  push eax                           */
  /* 0011 */  "\x8B\x45\x3C"      /*  mov eax, dword ptr [ebp+3Ch]       */
  /* 0014 */  "\x8B\x44\x28\x78"  /*  mov eax, dword ptr [eax+ebp+78h]   */
  /* 0018 */  "\x8D\x74\x28\x18"  /*  lea esi, dword ptr [eax+ebp+18h]   */
  /* 001C */  "\xAD"              /*  lodsd                              */
  /* 001D */  "\x91"              /*  xchg eax, ecx                      */
  /* 001E */  "\xE3\xEC"          /*  jecxz 0000000Ch                    */
  /* 0020 */  "\xAD"              /*  lodsd                              */
  /* 0021 */  "\x03\xC5"          /*  add eax, ebp                       */
  /* 0023 */  "\x50"              /*  push eax                           */
  /* 0024 */  "\xAD"              /*  lodsd                              */
  /* 0025 */  "\x8D\x3C\x28"      /*  lea edi, dword ptr [eax+ebp]       */
  /* 0028 */  "\xAD"              /*  lodsd                              */
  /* 0029 */  "\x8D\x1C\x28"      /*  lea ebx, dword ptr [eax+ebp]       */
  /* 002C */  "\x8B\x74\x8F\xFC"  /*  mov esi, dword ptr [edi+ecx*4-04h] */
  /* 0030 */  "\x03\xF5"          /*  add esi, ebp                       */
  /* 0032 */  "\x33\xC0"          /*  xor eax, eax                       */
  /* 0034 */  "\x99"              /*  cdq                                */
  /* 0035 */  "\xAC"              /*  lodsb                              */
  /* 0036 */  "\x03\xD0"          /*  add edx, eax                       */
  /* 0038 */  "\xC1\xC2\x07"      /*  rol edx, 07h                       */
  /* 003B */  "\x33\xD0"          /*  xor edx, eax                       */
  /* 003D */  "\x48"              /*  dec eax                            */
  /* 003E */  "\x79\xF5"          /*  jns 00000035h                      */
  /* 0040 */  "\x3B\x54\x24\x1C"  /*  cmp edx, dword ptr [esp+1Ch]       */
  /* 0044 */  "\xE0\xE6"          /*  loopne 0000002Ch                   */
  /* 0046 */  "\x58"              /*  pop eax                            */
  /* 0047 */  "\x5E"              /*  pop esi                            */
  /* 0048 */  "\x75\xC2"          /*  jne 0000000Ch                      */
  /* 004A */  "\x0F\xB7\x14\x4B"  /*  movzx edx, word ptr [ebx+ecx*2]    */
  /* 004E */  "\x03\x2C\x90"      /*  add ebp, dword ptr [eax+edx*4]     */
  /* 0051 */  "\x89\x6C\x24\x1C"  /*  mov dword ptr [esp+1Ch], ebp       */
  /* 0055 */  "\x61"              /*  popad                              */
  /* 0056 */  "\xFF\xE0"          /*  jmp eax                            */
};
