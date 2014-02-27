
#include <windows.h>
#include <stdio.h>

//
// 104 bytes LoadLibraryA code for windows 64
//
// Copyright (c) 2014 Kevin Devine
//
// cl load64_test.cpp
//
char code[] = {
    /* 0000 */    "\x53"                                 /* push rbx */
    /* 0001 */    "\x56"                                 /* push rsi */
    /* 0002 */    "\x57"                                 /* push rdi */
    /* 0003 */    "\x55"                                 /* push rbp */
    /* 0004 */    "\x4C\x8B\xFC"                         /* mov r15, rsp */
    /* 0007 */    "\x48\x83\xE4\xF0"                     /* and rsp, FFFFFFFFFFFFFFF0h */
    /* 000B */    "\x48\x83\xEC\x28"                     /* sub rsp, 28h */
    /* 000F */    "\xEB\x52"                             /* jmp 0063h */
    /* 0011 */    "\x6A\x60"                             /* push 0060h */
    /* 0013 */    "\x59"                                 /* pop rcx */
    /* 0014 */    "\x65\x48\x8B\x31"                     /* mov rsi, qword ptr [rcx] */
    /* 0018 */    "\x8B\x76\x18"                         /* mov esi, dword ptr [rsi+18h] */
    /* 001B */    "\x8B\x76\x10"                         /* mov esi, dword ptr [rsi+10h] */
    /* 001E */    "\xAD"                                 /* lodsd  */
    /* 001F */    "\x8B\x30"                             /* mov esi, dword ptr [rax] */
    /* 0021 */    "\x8B\x7E\x30"                         /* mov edi, dword ptr [rsi+30h] */
    /* 0024 */    "\x03\x4F\x3C"                         /* add ecx, dword ptr [rdi+3Ch] */
    /* 0027 */    "\x8B\x5C\x39\x28"                     /* mov ebx, dword ptr [rcx+rdi+28h] */
    /* 002B */    "\x8B\x74\x3B\x20"                     /* mov esi, dword ptr [rbx+rdi+20h] */
    /* 002F */    "\x03\xF7"                             /* add esi, edi */
    /* 0031 */    "\x8B\x4C\x3B\x24"                     /* mov ecx, dword ptr [rbx+rdi+24h] */
    /* 0035 */    "\x03\xCF"                             /* add ecx, edi */
    /* 0037 */    "\x99"                                 /* cdq  */
    /* 0038 */    "\x0F\xB7\x2C\x51"                     /* movzx ebp, word ptr [rcx+rdx*2] */
    /* 003C */    "\xFF\xC2"                             /* inc edx */
    /* 003E */    "\xAD"                                 /* lodsd  */
    /* 003F */    "\x81\x3C\x38\x4C\x6F\x61\x64"         /* cmp dword ptr [rax+rdi], 64616F4Ch */
    /* 0046 */    "\x75\xF0"                             /* jne 0038h */
    /* 0048 */    "\x80\x7C\x38\x0B\x41"                 /* cmp byte ptr [rax+rdi+0Bh], 41h */
    /* 004D */    "\x75\xE9"                             /* jne 0038h */
    /* 004F */    "\x8B\x74\x3B\x1C"                     /* mov esi, dword ptr [rbx+rdi+1Ch] */
    /* 0053 */    "\x03\xF7"                             /* add esi, edi */
    /* 0055 */    "\x03\x3C\xAE"                         /* add edi, dword ptr [rsi+rbp*4] */
    /* 0058 */    "\x59"                                 /* pop rcx */
    /* 0059 */    "\xFF\xD7"                             /* call rdi */
    /* 005B */    "\x49\x8B\xE7"                         /* mov rsp, r15 */
    /* 005E */    "\x5D"                                 /* pop rbp */
    /* 005F */    "\x5F"                                 /* pop rdi */
    /* 0060 */    "\x5E"                                 /* pop rsi */
    /* 0061 */    "\x5B"                                 /* pop rbx */
    /* 0062 */    "\xC3"                                 /* ret  */
    /* 0063 */    "\xE8\xA9\xFF\xFF\xFF"                 /* call 0011h */
};

int main (int argc, char* argv[]) {
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
  
  if (argc != 2) {
    printf ("\nUsage: load64_test <DLL name/path>\n");
    return 0;
  }
  
  char *path = argv[1];
  size_t path_len = strlen (path);
  
  if (path_len > MAX_PATH) {
    printf ("\nPath exceeds MAX_PATH limit of %i bytes", MAX_PATH);
    return 0;
  }
  
  void *exec = VirtualAlloc(0, strlen (code) + MAX_PATH, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, code, strlen (code));
  strcat ((char*)exec, path);
  printf ("\nAssembly : %i\nFinal Size : %i", 
    strlen (code), 
    path_len + strlen (code));
  //DebugBreak();
  printf ("\nBase Address returned : 0x%016llX\n", ((__int64(*)())exec)());
  
  VirtualFree (exec, 0, MEM_RELEASE);
  return 0;
}

