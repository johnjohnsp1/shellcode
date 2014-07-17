/**
 *   Hidden Server component v0.1
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

#define APP_NAME     "Hidden Server"
#define APP_VERSION  "0.1"
#define AUTHOR_EMAIL "Kevin Devine @cmpxchg8"

#define _WIN32_WINNT 0x0501

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <wincrypt.h>
 
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "kernel32.lib")

#define SOCKET_EVENT 0
#define CTRL_EVENT   1
#define STDIN_EVENT  2

typedef struct _INPUT_DATA {
  DWORD  len;
  char   buf[BUFSIZ];
  HANDLE evt, evtbck;
} INPUT_DATA, *PINPUT_DATA;

#define in_addr_t unsigned long
 
HCRYPTPROV hProvider   = 0; 
HCRYPTKEY  hPrivateKey = 0;
HCRYPTKEY  hSessionKey = 0;

BOOL       bFinalize=TRUE;
SOCKET     s;
HANDLE     evt[MAXIMUM_WAIT_OBJECTS];
DWORD      len, evt_cnt=0;
BYTE       buf[BUFSIZ+64], ip[64];
int        af=AF_INET, secure=0;
BYTE       public_key[BUFSIZ];
DWORD      cbPublic;
INPUT_DATA input;

struct sockaddr_in sin_ipv4;
struct sockaddr_in6 sin_ipv6;

int ai_addrlen;
struct sockaddr *ai_addr;

BOOL WINAPI HandlerRoutine (DWORD dwCtrlType)
{
  if (dwCtrlType != CTRL_C_EVENT) return FALSE;
  SetEvent (evt[CTRL_EVENT]);
  return TRUE;
}

void start_handler (void)
{
  evt[CTRL_EVENT] = CreateEvent (NULL, FALSE, FALSE, NULL);
  SetConsoleCtrlHandler (HandlerRoutine, TRUE);
  evt_cnt++;
}

void stop_handler (void)
{
  SetConsoleCtrlHandler (HandlerRoutine, FALSE);
  CloseHandle (evt[CTRL_EVENT]);
  evt_cnt--;
}
/**
 * Function to resolve host or IP address
 *
 * @param host is IP address or host name
 * @return
 *
 */
void xstrerror (const char fmt[], ...) 
{
  char    *error;
  va_list arglist;
  char    buffer[2048];
  
  va_start (arglist, fmt);
  vsnprintf (buffer, sizeof(buffer) - 1, fmt, arglist);
  va_end (arglist);
  
  FormatMessage (
      FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
      NULL, GetLastError (), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
      (LPSTR)&error, 0, NULL);

  printf ("\n[ %s : %s", buffer, error);
  LocalFree (error);
}

char *addr2ip (void)
{
  DWORD ip_size=64;
  WSAAddressToString (ai_addr, ai_addrlen, NULL, (char*)ip, &ip_size);
  return (char*)ip;
}
/**
 * Function to handle incoming connections
 *
 */
bool resolvex (char host[], char port[])
{
  struct addrinfo *list;
  struct addrinfo hints;
  BOOL bStatus=FALSE;
  
  ZeroMemory (&hints, sizeof (hints));

  hints.ai_family   = af;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  
  // get all resolvable addresses for this machine name
  if (getaddrinfo (host, port, &hints, &list) == 0) 
  {
    for (struct addrinfo *pEntry=list; pEntry!=NULL; pEntry=pEntry->ai_next) 
    {
      if (af==AF_INET) {
        memcpy (&sin_ipv4, pEntry->ai_addr, pEntry->ai_addrlen);
        ai_addr     = (sockaddr*)&sin_ipv4;        
      } else {
        memcpy (&sin_ipv6, pEntry->ai_addr, pEntry->ai_addrlen);
        ai_addr     = (sockaddr*)&sin_ipv6;
      }
      ai_addrlen = pEntry->ai_addrlen;
      bStatus=TRUE;
      break;
    }
    freeaddrinfo (list);
  }
  return bStatus;
}
/**
 * Function to send data to remote system, encrypted if required
 *
 */
int send_pkt (void) 
{
  if (secure) 
  {
    if (!CryptEncrypt (hSessionKey, 0, bFinalize, 0, buf, &len, sizeof (buf))) 
    {
      xstrerror ("CryptEncrypt()");
      return 0;
    }
  }
  // send length first
  send (s, (char*)&len, 4, 0);
  // then the data
  send (s, (char*)buf, len, 0);
  return 1;
}

/**
 * Function to receive data and decrypt if required
 *
 */
int recv_pkt (void)
{
  DWORD pkt_len=0;
  
  // get the length first
  len=recv (s, (char*)&pkt_len, 4, 0);
  // if error, return
  if (len<=0 || len!=4) return 0;
  pkt_len=(pkt_len>sizeof(buf)) ? sizeof(buf) : pkt_len;
  
  // receive the data
  len=recv (s, (char*)buf, pkt_len, 0);
  if (len<=0) return 0;
  
  // decrypt if required
  if (secure) 
  {
    if (!CryptDecrypt (hSessionKey, 0, bFinalize, 0, buf, &len)) {
      xstrerror ("CryptDecrypt()");
      return 0;
    }
  }
  return 1;
}

/**
 * Function to wait for events from hStdInput or socket (FD_READ | FD_CLOSE)
 *
 */
DWORD wait_evt (void)
{
  WSANETWORKEVENTS ne;
  u_long           off=0;
  DWORD            e;
  
  WSAEventSelect (s, evt[0], FD_CLOSE | FD_READ | FD_ACCEPT);
  e=WaitForMultipleObjects (evt_cnt, evt, FALSE, INFINITE);
  
  WSAEnumNetworkEvents (s, evt[0], &ne);    
  WSAEventSelect (s, evt[0], 0);
  
  ioctlsocket (s, FIONBIO, &off);
  
  if (ne.lNetworkEvents & FD_CLOSE) {
    e=-1;
  }
  return e;
}

/**
 * Function to read data from hStdInput of cmd.exe
 *
 */
static DWORD WINAPI read_thread (void *param) 
{
  BOOL bStatus;
  HANDLE stdinput=GetStdHandle (STD_INPUT_HANDLE);
  
  while (1) 
  {
    bStatus=ReadFile (stdinput, input.buf, BUFSIZ, &input.len, NULL);
    if (!bStatus) break;
    
    if (input.len>0) 
    {
      SetEvent (input.evt);
      WaitForSingleObject (input.evtbck, INFINITE);
    }
  }

  input.len = 0;
  SetEvent (input.evt);
  return 0;
}

/**
 * Function to handle incoming connections
 *
 */
void session (void)
{
  HANDLE hThread;
  DWORD  e;
  
  input.evt    = CreateEvent (NULL, FALSE, FALSE, NULL);
  input.evtbck = CreateEvent (NULL, FALSE, FALSE, NULL);
  
  // event for input
  evt[STDIN_EVENT] = input.evt; 
  evt_cnt++;
  
  // create thread for input
  hThread=CreateThread (NULL, 0, read_thread, NULL, 0, NULL);
            
  // keep going until CTRL+C or disconnection of peer
  while (1) 
  {
    e=wait_evt();

    // read from socket?
    if (e==SOCKET_EVENT) {
      // receive packet
      if (!recv_pkt ()) {
        printf ("\nrecv_pkt() error");
        break;
      }
      // write to output
      WriteConsole (GetStdHandle (STD_OUTPUT_HANDLE), buf, len, &len, 0);
    } 
    else if (e==STDIN_EVENT) 
    {
      len=input.len;
      memcpy (buf, input.buf, input.len);
      if (!send_pkt ())
      {
        printf ("\nsend_pkt() error");
        break;
      }
      // start reading user input again
      SetEvent (input.evtbck);
    } else {
      // some other event, like CTRL+C
      // send CTRL+C code to remote hStdInput?
      break;
    }
  }
  CloseHandle (hThread);
  CloseHandle (input.evtbck);
  
  CloseHandle (evt[STDIN_EVENT]);
  evt_cnt--;
}
/**
 * Function to export key
 *
 */
BOOL export_key (HCRYPTKEY hKey, DWORD dwFlags)
{
  DWORD keyLen;
  BOOL  bStatus=FALSE;
  DWORD cbKey=sizeof (keyLen);
  
  CryptGetKeyParam (hKey, KP_KEYLEN, (PBYTE)&keyLen, &cbKey, 0);
  
  printf ("[ Public RSA key is %i-bits\n", keyLen);
  cbPublic=0;
  if (CryptExportKey (hKey, NULL, dwFlags, 0, NULL, &cbPublic))
  {
    if (cbPublic<=BUFSIZ) 
    {
      bStatus=CryptExportKey (hKey, NULL, dwFlags, 0, public_key, &cbPublic);      
      if (!bStatus) {
        xstrerror ("CryptExportKey");
      }
    } else {
      printf ("[ Public key exceeds BUFSIZ\n");
    }
  } else {
    xstrerror ("CryptExportKey");
  }
  return bStatus;
}
/**
 * Function to handle incoming connections
 *
 */
BOOL genkeys (DWORD keyLen) 
{
  BOOL bStatus=FALSE;
  
	if (CryptAcquireContext (&hProvider, NULL, NULL, PROV_RSA_AES, 
      CRYPT_VERIFYCONTEXT | CRYPT_SILENT)) 
  {
    if (CryptGenKey (hProvider, CALG_RSA_KEYX, keyLen<<16 | CRYPT_EXPORTABLE, &hPrivateKey))
    {
      bStatus=export_key (hPrivateKey, PUBLICKEYBLOB);
    } else {
      xstrerror ("CryptGenKey");
    }
  } else {
    xstrerror ("CryptAcquireContext");
  }
  return bStatus;
}
/**
 * Convert ALG_ID to string
 *
 */
char* id2str (ALG_ID dwAlgId)
{
  switch (dwAlgId)
  {
    case CALG_RC2:
      return "RC2";
      break;
    case CALG_RC4:
      return "RC4";
      break;
    case CALG_RC5:
      return "RC5";
      break;
    case CALG_DESX:
      return "DESX";
      break;
    case CALG_DES:
      return "DES";
      break;
    case CALG_3DES_112:
    case CALG_3DES:
      return "3DES";
      break;
    case CALG_AES:
    case CALG_AES_128:
    case CALG_AES_192:
    case CALG_AES_256:
      return "AES";
      break;
  }
  return "UNKNOWN";
}

/**
 * Function to handle incoming connections
 *
 */
BOOL start_secure (void)
{
  BOOL bStatus=FALSE;
  DWORD dwAlgId, dwLen, dwKeyLen;
  
  printf ("[ Enabling security\n");
  
  // send public key
  len=cbPublic;
  memcpy (buf, public_key, cbPublic);
  printf ("[ Sending public key of %i bytes\n", len);
  send_pkt ();
  
  // wait for session key
  printf ("[ Waiting for session key\n");
  if (recv_pkt ())
  {
    // try import it
    printf ("[ Importing session key of %i bytes\n", len);
    bStatus=CryptImportKey (hProvider, buf, len, hPrivateKey, 0, &hSessionKey);
  
    if (bStatus) 
    {
      dwLen=sizeof (DWORD);
      if (CryptGetKeyParam (hSessionKey, KP_ALGID, (PBYTE)&dwAlgId, &dwLen, 0))
      {
        dwLen=sizeof (DWORD);
        if (CryptGetKeyParam (hSessionKey, KP_KEYLEN, (PBYTE)&dwKeyLen, &dwLen, 0))
        { 
          secure=1;
          printf ("[ Encryption algorithm is %s-%i\n", id2str(dwAlgId), dwKeyLen);
        }
      }
    } else {
      xstrerror ("CryptImportKey");
    }
  } else {
    printf ("[ recv_pkt() failed\n");
  }
  return bStatus;
}
/**
 * Function to handle incoming connections
 *
 */
void end_secure (void)
{
  secure=0;
  CryptDestroyKey (hPrivateKey);
  CryptReleaseContext (hProvider, 0);
}

/**
 * Function to handle incoming connections
 *
 */
void inbound (char host[], char port[])
{
  struct sockaddr_in peer;
  in_addr_t          ip;
  SOCKET             s1, ret;
  u_long             on=1;
  socklen_t          plen;
  int                quit=0;
  DWORD              e;
  
  if (!resolvex (host, port)) {
    printf ("[ Unable to resolve address for host %s\n", host);
    return;
  }
   
  s1 = socket (af, SOCK_STREAM, IPPROTO_TCP);
  
  if (s1 < 0) {
    xstrerror ("socket()");
    return;
  }
  
  ret = setsockopt (s1, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof (on));
  
  // bind to local address and port
  if (!bind (s1, ai_addr, ai_addrlen)) 
  {
    // listen for inbound connection
    if (!listen (s1, 1)) 
    {
      evt[0]=WSACreateEvent();
      evt_cnt++;
      
      while (!quit) {
        printf ("[ Waiting for incoming connections on %s\n", addr2ip());
        
        s=s1;
        e=wait_evt();
        
        if (e==SOCKET_EVENT)
        {
          s = accept (s1, ai_addr, (int*)&ai_addrlen);
              
          if (s<0) continue;
        
          printf ("[ Connection from %s\n", addr2ip());
          if (start_secure ())
          {
            printf ("[ Running session handler\n\n");
            session ();
            // destroy session key
            if (hSessionKey!=0) {
              CryptDestroyKey (hSessionKey);
              secure=0;
              hSessionKey=0;
            }
          } else {
            printf ("[ Security failed\n");
          }
          shutdown (s, SD_BOTH);
          closesocket (s);
          printf ("[ Disconnecting\n\n");
        } else {
          printf ("[ CTRL+C interrupt\n");
          quit=1;
        }
      }
    } else {
      xstrerror ("listen()");
    }
  } else {
    xstrerror ("bind()");
  }
  closesocket (s1);
}

/**
 * Function to handle incoming connections
 *
 */
void usage (char *argv[]) 
{  
  printf ("\n  Usage: %s <host> <port>\n", argv[0]);
      
  printf ("\nPress any key to continue . . .");
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

int main (int argc, char *argv[])
{
  char    *host=NULL, *port="80";   // default is 80
  int     i, n, bitlen=1024;        // default is 1024-bit
  char    opt;
  WSADATA wsa;
  
  ConsoleSetBufferWidth (300);
  
  puts ("\n  "APP_NAME" component "APP_VERSION
       "\n  Copyright (c) 2014 "AUTHOR_EMAIL"\n");
       
  for (i=1; i<argc; i++) {
    if (argv[i][0]=='/' || argv[i][0]=='-') {
      opt=argv[i][1];
      switch (opt) {
        case '6' : { af=AF_INET6; break; }
        case 'k' :
        {
          if ((i+1) <= argc) {
            bitlen=atoi(argv[++i]);
          } else {
            printf ("\n-k requires parameter\n");
            exit(0);
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
  
  printf ("[ Generating keys . . . \n");
  
  // try generate keys first
  if (!genkeys (bitlen)) {
    printf ("[ Generating keys failed\n");
    return 0;
  }
  // now listen for incoming connections
  WSAStartup (MAKEWORD (2, 0), &wsa);
  start_handler ();
  inbound (host, port);
  stop_handler ();
  WSACleanup();
  return 0;
}
