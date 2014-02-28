I've tested these on Windows 7 and Windows Server 2012.
If you discover any problems on other 64-bit systems, please let me know.
Crashes usually occur due to misaligned stack but of course, there's no error
checking of each call to API so the TCP code could crash for various other reasons.

test directory contains CPP files you can compile to test out the code.
I'm using Visual Studio 64-bit compilers and JWASM [1]
Required are also Windows Include headers for Masm/Jwasm [2] if you want to assemble binarys.

exec64         - Executes a command
load64         - Loads a DLL
rev_overlap64  - Reverse connecting command prompt
bind_overlap64 - Binds to local address and port, spawns command prompt upon receiving connection


[1] JWasm
  http://www.japheth.de/JWasm.html

[2] WinInc - Masm/JWasm include files for Win32 and Win64
  http://www.japheth.de/WinInc.html
