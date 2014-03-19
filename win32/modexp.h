
/* Copyright (c) 2014 Kevin Devine */
/* Size = 204 bytes */

char modexp32[] = {
  /* 0000 */  "\x60"                  /*  pushad                         */
  /* 0001 */  "\x0F\x42\xDF"          /*  cmovb ebx, edi                 */
  /* 0004 */  "\xC1\xE1\x05"          /*  shl ecx, 05h                   */
  /* 0007 */  "\x0F\xA3\x0B"          /*  bt dword ptr [ebx], ecx        */
  /* 000A */  "\x72\x02"              /*  jc 0000000Eh                   */
  /* 000C */  "\xE2\xF9"              /*  loop 00000007h                 */
  /* 000E */  "\x89\x4C\x24\x14"      /*  mov dword ptr [esp+14h], ecx   */
  /* 0012 */  "\x61"                  /*  popad                          */
  /* 0013 */  "\xC3"                  /*  ret                            */
  /* 0014 */  "\x60"                  /*  pushad                         */
  /* 0015 */  "\x8B\xFD"              /*  mov edi, ebp                   */
  /* 0017 */  "\x72\x0F"              /*  jc 00000028h                   */
  /* 0019 */  "\x60"                  /*  pushad                         */
  /* 001A */  "\xFD"                  /*  std                            */
  /* 001B */  "\x49"                  /*  dec ecx                        */
  /* 001C */  "\x8D\x34\x8E"          /*  lea esi, dword ptr [esi+ecx*4] */
  /* 001F */  "\x8D\x3C\x8F"          /*  lea edi, dword ptr [edi+ecx*4] */
  /* 0022 */  "\xF3\xA7"              /*  rep cmpsd                      */
  /* 0024 */  "\xFC"                  /*  cld                            */
  /* 0025 */  "\x61"                  /*  popad                          */
  /* 0026 */  "\x72\x0C"              /*  jc 00000034h                   */
  /* 0028 */  "\xF8"                  /*  clc                            */
  /* 0029 */  "\xAD"                  /*  lodsd                          */
  /* 002A */  "\x1B\x07"              /*  sbb eax, dword ptr [edi]       */
  /* 002C */  "\x89\x46\xFC"          /*  mov dword ptr [esi-04h], eax   */
  /* 002F */  "\x8D\x7F\x04"          /*  lea edi, dword ptr [edi+04h]   */
  /* 0032 */  "\xE2\xF5"              /*  loop 00000029h                 */
  /* 0034 */  "\x61"                  /*  popad                          */
  /* 0035 */  "\xC3"                  /*  ret                            */
  /* 0036 */  "\x60"                  /*  pushad                         */
  /* 0037 */  "\x8B\xC4"              /*  mov eax, esp                   */
  /* 0039 */  "\x8B\xDF"              /*  mov ebx, edi                   */
  /* 003B */  "\x0F\x43\xDE"          /*  cmovnb ebx, esi                */
  /* 003E */  "\xC1\xE1\x02"          /*  shl ecx, 02h                   */
  /* 0041 */  "\x2B\xE1"              /*  sub esp, ecx                   */
  /* 0043 */  "\xC1\xE9\x02"          /*  shr ecx, 02h                   */
  /* 0046 */  "\x8B\xFC"              /*  mov edi, esp                   */
  /* 0048 */  "\x60"                  /*  pushad                         */
  /* 0049 */  "\x33\xC0"              /*  xor eax, eax                   */
  /* 004B */  "\xF3\xAB"              /*  rep stosd                      */
  /* 004D */  "\x61"                  /*  popad                          */
  /* 004E */  "\x87\xF7"              /*  xchg edi, esi                  */
  /* 0050 */  "\xF9"                  /*  stc                            */
  /* 0051 */  "\xE8\xAA\xFF\xFF\xFF"  /*  call 00000000h                 */
  /* 0056 */  "\xF8"                  /*  clc                            */
  /* 0057 */  "\x60"                  /*  pushad                         */
  /* 0058 */  "\xD1\x16"              /*  rcl dword ptr [esi], 1         */
  /* 005A */  "\xAD"                  /*  lodsd                          */
  /* 005B */  "\xE2\xFB"              /*  loop 00000058h                 */
  /* 005D */  "\x61"                  /*  popad                          */
  /* 005E */  "\xE8\xB1\xFF\xFF\xFF"  /*  call 00000014h                 */
  /* 0063 */  "\x0F\xA3\x17"          /*  bt dword ptr [edi], edx        */
  /* 0066 */  "\x73\x13"              /*  jnc 0000007Bh                  */
  /* 0068 */  "\xF8"                  /*  clc                            */
  /* 0069 */  "\x60"                  /*  pushad                         */
  /* 006A */  "\xAD"                  /*  lodsd                          */
  /* 006B */  "\x13\x03"              /*  adc eax, dword ptr [ebx]       */
  /* 006D */  "\x89\x46\xFC"          /*  mov dword ptr [esi-04h], eax   */
  /* 0070 */  "\x8D\x5B\x04"          /*  lea ebx, dword ptr [ebx+04h]   */
  /* 0073 */  "\xE2\xF5"              /*  loop 0000006Ah                 */
  /* 0075 */  "\x61"                  /*  popad                          */
  /* 0076 */  "\xE8\x99\xFF\xFF\xFF"  /*  call 00000014h                 */
  /* 007B */  "\x4A"                  /*  dec edx                        */
  /* 007C */  "\x79\xD8"              /*  jns 00000056h                  */
  /* 007E */  "\x8B\xFB"              /*  mov edi, ebx                   */
  /* 0080 */  "\xF3\xA5"              /*  rep movsd                      */
  /* 0082 */  "\x8B\xE0"              /*  mov esp, eax                   */
  /* 0084 */  "\x61"                  /*  popad                          */
  /* 0085 */  "\xC3"                  /*  ret                            */
  /* 0086 */  "\x8B\xC4"              /*  mov eax, esp                   */
  /* 0088 */  "\x60"                  /*  pushad                         */
  /* 0089 */  "\x8B\xF2"              /*  mov esi, edx                   */
  /* 008B */  "\x8B\x58\x04"          /*  mov ebx, dword ptr [eax+04h]   */
  /* 008E */  "\x8B\x68\x08"          /*  mov ebp, dword ptr [eax+08h]   */
  /* 0091 */  "\x8B\x40\x0C"          /*  mov eax, dword ptr [eax+0Ch]   */
  /* 0094 */  "\xC1\xE9\x03"          /*  shr ecx, 03h                   */
  /* 0097 */  "\x2B\xE1"              /*  sub esp, ecx                   */
  /* 0099 */  "\x8B\xFC"              /*  mov edi, esp                   */
  /* 009B */  "\xC1\xE9\x02"          /*  shr ecx, 02h                   */
  /* 009E */  "\x60"                  /*  pushad                         */
  /* 009F */  "\xF3\xA5"              /*  rep movsd                      */
  /* 00A1 */  "\x61"                  /*  popad                          */
  /* 00A2 */  "\x8B\xF4"              /*  mov esi, esp                   */
  /* 00A4 */  "\x97"                  /*  xchg eax, edi                  */
  /* 00A5 */  "\x33\xC0"              /*  xor eax, eax                   */
  /* 00A7 */  "\x60"                  /*  pushad                         */
  /* 00A8 */  "\xF3\xAB"              /*  rep stosd                      */
  /* 00AA */  "\x61"                  /*  popad                          */
  /* 00AB */  "\xFF\x07"              /*  inc dword ptr [edi]            */
  /* 00AD */  "\xF8"                  /*  clc                            */
  /* 00AE */  "\xE8\x4D\xFF\xFF\xFF"  /*  call 00000000h                 */
  /* 00B3 */  "\x0F\xA3\x03"          /*  bt dword ptr [ebx], eax        */
  /* 00B6 */  "\x73\x06"              /*  jnc 000000BEh                  */
  /* 00B8 */  "\xE8\x79\xFF\xFF\xFF"  /*  call 00000036h                 */
  /* 00BD */  "\xF8"                  /*  clc                            */
  /* 00BE */  "\xE8\x73\xFF\xFF\xFF"  /*  call 00000036h                 */
  /* 00C3 */  "\x40"                  /*  inc eax                        */
  /* 00C4 */  "\x4A"                  /*  dec edx                        */
  /* 00C5 */  "\x79\xEC"              /*  jns 000000B3h                  */
  /* 00C7 */  "\x8D\x24\x8C"          /*  lea esp, dword ptr [esp+ecx*4] */
  /* 00CA */  "\x61"                  /*  popad                          */
  /* 00CB */  "\xC3"                  /*  ret                            */
};
