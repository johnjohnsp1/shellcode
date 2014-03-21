
/* Copyright (c) 2014 Kevin Devine */
/* Size = 205 bytes */

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
  /* 0017 */  "\x72\x10"              /*  jc 00000029h                   */
  /* 0019 */  "\x60"                  /*  pushad                         */
  /* 001A */  "\xFD"                  /*  std                            */
  /* 001B */  "\xAD"                  /*  lodsd                          */
  /* 001C */  "\xAF"                  /*  scasd                          */
  /* 001D */  "\x8D\x34\x8E"          /*  lea esi, dword ptr [esi+ecx*4] */
  /* 0020 */  "\x8D\x3C\x8F"          /*  lea edi, dword ptr [edi+ecx*4] */
  /* 0023 */  "\xF3\xA7"              /*  rep cmpsd                      */
  /* 0025 */  "\xFC"                  /*  cld                            */
  /* 0026 */  "\x61"                  /*  popad                          */
  /* 0027 */  "\x72\x0C"              /*  jc 00000035h                   */
  /* 0029 */  "\xF8"                  /*  clc                            */
  /* 002A */  "\xAD"                  /*  lodsd                          */
  /* 002B */  "\x1B\x07"              /*  sbb eax, dword ptr [edi]       */
  /* 002D */  "\x89\x46\xFC"          /*  mov dword ptr [esi-04h], eax   */
  /* 0030 */  "\x8D\x7F\x04"          /*  lea edi, dword ptr [edi+04h]   */
  /* 0033 */  "\xE2\xF5"              /*  loop 0000002Ah                 */
  /* 0035 */  "\x61"                  /*  popad                          */
  /* 0036 */  "\xC3"                  /*  ret                            */
  /* 0037 */  "\x60"                  /*  pushad                         */
  /* 0038 */  "\x8B\xC4"              /*  mov eax, esp                   */
  /* 003A */  "\x8B\xDF"              /*  mov ebx, edi                   */
  /* 003C */  "\x0F\x43\xDE"          /*  cmovnb ebx, esi                */
  /* 003F */  "\xC1\xE1\x02"          /*  shl ecx, 02h                   */
  /* 0042 */  "\x2B\xE1"              /*  sub esp, ecx                   */
  /* 0044 */  "\xC1\xE9\x02"          /*  shr ecx, 02h                   */
  /* 0047 */  "\x8B\xFC"              /*  mov edi, esp                   */
  /* 0049 */  "\x60"                  /*  pushad                         */
  /* 004A */  "\x33\xC0"              /*  xor eax, eax                   */
  /* 004C */  "\xF3\xAB"              /*  rep stosd                      */
  /* 004E */  "\x61"                  /*  popad                          */
  /* 004F */  "\x87\xF7"              /*  xchg edi, esi                  */
  /* 0051 */  "\xF9"                  /*  stc                            */
  /* 0052 */  "\xE8\xA9\xFF\xFF\xFF"  /*  call 00000000h                 */
  /* 0057 */  "\xF8"                  /*  clc                            */
  /* 0058 */  "\x60"                  /*  pushad                         */
  /* 0059 */  "\xD1\x16"              /*  rcl dword ptr [esi], 1         */
  /* 005B */  "\xAD"                  /*  lodsd                          */
  /* 005C */  "\xE2\xFB"              /*  loop 00000059h                 */
  /* 005E */  "\x61"                  /*  popad                          */
  /* 005F */  "\xE8\xB0\xFF\xFF\xFF"  /*  call 00000014h                 */
  /* 0064 */  "\x0F\xA3\x17"          /*  bt dword ptr [edi], edx        */
  /* 0067 */  "\x73\x13"              /*  jnc 0000007Ch                  */
  /* 0069 */  "\xF8"                  /*  clc                            */
  /* 006A */  "\x60"                  /*  pushad                         */
  /* 006B */  "\xAD"                  /*  lodsd                          */
  /* 006C */  "\x13\x03"              /*  adc eax, dword ptr [ebx]       */
  /* 006E */  "\x89\x46\xFC"          /*  mov dword ptr [esi-04h], eax   */
  /* 0071 */  "\x8D\x5B\x04"          /*  lea ebx, dword ptr [ebx+04h]   */
  /* 0074 */  "\xE2\xF5"              /*  loop 0000006Bh                 */
  /* 0076 */  "\x61"                  /*  popad                          */
  /* 0077 */  "\xE8\x98\xFF\xFF\xFF"  /*  call 00000014h                 */
  /* 007C */  "\x4A"                  /*  dec edx                        */
  /* 007D */  "\x79\xD8"              /*  jns 00000057h                  */
  /* 007F */  "\x8B\xFB"              /*  mov edi, ebx                   */
  /* 0081 */  "\xF3\xA5"              /*  rep movsd                      */
  /* 0083 */  "\x8B\xE0"              /*  mov esp, eax                   */
  /* 0085 */  "\x61"                  /*  popad                          */
  /* 0086 */  "\xC3"                  /*  ret                            */
  /* 0087 */  "\x8B\xC4"              /*  mov eax, esp                   */
  /* 0089 */  "\x60"                  /*  pushad                         */
  /* 008A */  "\x8B\xF2"              /*  mov esi, edx                   */
  /* 008C */  "\x8B\x58\x04"          /*  mov ebx, dword ptr [eax+04h]   */
  /* 008F */  "\x8B\x68\x08"          /*  mov ebp, dword ptr [eax+08h]   */
  /* 0092 */  "\x8B\x40\x0C"          /*  mov eax, dword ptr [eax+0Ch]   */
  /* 0095 */  "\xC1\xE9\x03"          /*  shr ecx, 03h                   */
  /* 0098 */  "\x2B\xE1"              /*  sub esp, ecx                   */
  /* 009A */  "\x8B\xFC"              /*  mov edi, esp                   */
  /* 009C */  "\xC1\xE9\x02"          /*  shr ecx, 02h                   */
  /* 009F */  "\x60"                  /*  pushad                         */
  /* 00A0 */  "\xF3\xA5"              /*  rep movsd                      */
  /* 00A2 */  "\x61"                  /*  popad                          */
  /* 00A3 */  "\x8B\xF4"              /*  mov esi, esp                   */
  /* 00A5 */  "\x97"                  /*  xchg eax, edi                  */
  /* 00A6 */  "\x33\xC0"              /*  xor eax, eax                   */
  /* 00A8 */  "\x60"                  /*  pushad                         */
  /* 00A9 */  "\xF3\xAB"              /*  rep stosd                      */
  /* 00AB */  "\x61"                  /*  popad                          */
  /* 00AC */  "\xFF\x07"              /*  inc dword ptr [edi]            */
  /* 00AE */  "\xF8"                  /*  clc                            */
  /* 00AF */  "\xE8\x4C\xFF\xFF\xFF"  /*  call 00000000h                 */
  /* 00B4 */  "\x0F\xA3\x03"          /*  bt dword ptr [ebx], eax        */
  /* 00B7 */  "\x73\x06"              /*  jnc 000000BFh                  */
  /* 00B9 */  "\xE8\x79\xFF\xFF\xFF"  /*  call 00000037h                 */
  /* 00BE */  "\xF8"                  /*  clc                            */
  /* 00BF */  "\xE8\x73\xFF\xFF\xFF"  /*  call 00000037h                 */
  /* 00C4 */  "\x40"                  /*  inc eax                        */
  /* 00C5 */  "\x4A"                  /*  dec edx                        */
  /* 00C6 */  "\x79\xEC"              /*  jns 000000B4h                  */
  /* 00C8 */  "\x8D\x24\x8C"          /*  lea esp, dword ptr [esp+ecx*4] */
  /* 00CB */  "\x61"                  /*  popad                          */
  /* 00CC */  "\xC3"                  /*  ret                            */
};
