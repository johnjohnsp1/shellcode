
/* Copyright (c) 2014 Kevin Devine */
/* Size = 211 bytes */

char modexp[] = {
  /* 0000 */  "\x53"                  /*  push ebx                       */
  /* 0001 */  "\x0F\x42\xDF"          /*  cmovb ebx, edi                 */
  /* 0004 */  "\x8B\xD1"              /*  mov edx, ecx                   */
  /* 0006 */  "\xC1\xE2\x05"          /*  shl edx, 05h                   */
  /* 0009 */  "\x4A"                  /*  dec edx                        */
  /* 000A */  "\x0F\xA3\x13"          /*  bt dword ptr [ebx], edx        */
  /* 000D */  "\x72\x03"              /*  jc 00000012h                   */
  /* 000F */  "\x4A"                  /*  dec edx                        */
  /* 0010 */  "\x75\xF8"              /*  jne 0000000Ah                  */
  /* 0012 */  "\x5B"                  /*  pop ebx                        */
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
  /* 0089 */  "\x8B\x48\x04"          /*  mov ecx, dword ptr [eax+04h]   */
  /* 008C */  "\x8B\x70\x0C"          /*  mov esi, dword ptr [eax+0Ch]   */
  /* 008F */  "\x8B\x58\x10"          /*  mov ebx, dword ptr [eax+10h]   */
  /* 0092 */  "\x8B\x68\x14"          /*  mov ebp, dword ptr [eax+14h]   */
  /* 0095 */  "\x8B\x40\x08"          /*  mov eax, dword ptr [eax+08h]   */
  /* 0098 */  "\xC1\xE9\x03"          /*  shr ecx, 03h                   */
  /* 009B */  "\x2B\xE1"              /*  sub esp, ecx                   */
  /* 009D */  "\x8B\xFC"              /*  mov edi, esp                   */
  /* 009F */  "\xC1\xE9\x02"          /*  shr ecx, 02h                   */
  /* 00A2 */  "\x60"                  /*  pushad                         */
  /* 00A3 */  "\xF3\xA5"              /*  rep movsd                      */
  /* 00A5 */  "\x61"                  /*  popad                          */
  /* 00A6 */  "\x8B\xF4"              /*  mov esi, esp                   */
  /* 00A8 */  "\x97"                  /*  xchg eax, edi                  */
  /* 00A9 */  "\x33\xC0"              /*  xor eax, eax                   */
  /* 00AB */  "\x60"                  /*  pushad                         */
  /* 00AC */  "\xF3\xAB"              /*  rep stosd                      */
  /* 00AE */  "\x61"                  /*  popad                          */
  /* 00AF */  "\xFF\x07"              /*  inc dword ptr [edi]            */
  /* 00B1 */  "\xF8"                  /*  clc                            */
  /* 00B2 */  "\xE8\x49\xFF\xFF\xFF"  /*  call 00000000h                 */
  /* 00B7 */  "\x0F\xA3\x03"          /*  bt dword ptr [ebx], eax        */
  /* 00BA */  "\x73\x06"              /*  jnc 000000C2h                  */
  /* 00BC */  "\xE8\x75\xFF\xFF\xFF"  /*  call 00000036h                 */
  /* 00C1 */  "\xF8"                  /*  clc                            */
  /* 00C2 */  "\xE8\x6F\xFF\xFF\xFF"  /*  call 00000036h                 */
  /* 00C7 */  "\x40"                  /*  inc eax                        */
  /* 00C8 */  "\x3B\xC2"              /*  cmp eax, edx                   */
  /* 00CA */  "\x76\xEB"              /*  jbe 000000B7h                  */
  /* 00CC */  "\xC1\xE1\x02"          /*  shl ecx, 02h                   */
  /* 00CF */  "\x03\xE1"              /*  add esp, ecx                   */
  /* 00D1 */  "\x61"                  /*  popad                          */
  /* 00D2 */  "\xC3"                  /*  ret                            */
};
