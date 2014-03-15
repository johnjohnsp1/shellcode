#include <windows.h>
#include <stdio.h>

// IsWow64 returns -1 (TRUE) if under Wow64, else 0 (FALSE)

/* Copyright (c) 2014 Kevin Devine */
/* Size = 4 bytes */

char IsWow64[] = {
  /* 0000 */  "\x33\xC0"  /*  xor eax, eax */
  /* 0002 */  "\x48"      /*  dec eax      */
  /* 0003 */  "\xC3"      /*  ret          */
};

int main( void )
{
  void *exec = VirtualAlloc(0, strlen (IsWow64) + MAX_PATH, 
    MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, IsWow64, strlen (IsWow64));
  printf ("\nRunning under Wow64? : %s\n", ((BOOL(*)())exec)() ? "Yes" : "No");
  VirtualFree (exec, 0, MEM_RELEASE);
}


