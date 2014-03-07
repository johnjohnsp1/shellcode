
#include <windows.h>
#include <stdio.h>

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

int main (int argc, char* argv[]) {
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
  
  if (argc != 2) {
    printf ("\nUsage: load64_test <DLL name/path>");
    printf ("\nExample: load64_test ws2_32\n");
    return 0;
  }
  
  char *path = argv[1];
  size_t path_len = strlen (path);
  
  if (path_len > MAX_PATH) {
    printf ("\nPath exceeds MAX_PATH limit of %i bytes", MAX_PATH);
    return 0;
  }
  
  void *exec = VirtualAlloc(0, strlen (load64) + MAX_PATH, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, load64, strlen (load64));
  strcat ((char*)exec, path);
  printf ("\nAssembly : %i\nFinal Size : %i", 
    strlen (load64), 
    path_len + strlen (load64));
  //DebugBreak();
  printf ("\nBase Address returned : 0x%016llX\n", ((__int64(*)())exec)());
  VirtualFree (exec, 0, MEM_RELEASE);
  return 0;
}

