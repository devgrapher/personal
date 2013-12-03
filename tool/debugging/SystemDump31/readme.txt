1. Command line syntax:

SystemDump.exe <message in double quotes> <interval in minutes>

For example, to make a scheduled bug check effective after 3 minutes and include “Hello World!” in a dump:

SystemDump.exe "Hello World!" 3

Note: to bug check a server immediately specify time interval: 0

To abort scheduled bug check run the following command:

SystemDump.exe abort

2. Remote execution example using PsExec.exe tool from www.sysinternals.com

C:\tools\PsExec>psexec \\SERVER -u Administrator -p <password> -w c:\SystemDump\x86 c:\SystemDump\x86\SystemDump.exe "Hello World!" 3

PsExec v1.72 - Execute processes remotely
Copyright (C) 2001-2006 Mark Russinovich
Sysinternals - www.sysinternals.com

c:\SystemDump\x86\SystemDump.exe exited on SERVER with error code 0.

How to interpret dumps forced by SystemDump

If you open that dump in WinDbg.exe you get the following output where you can du the second bug check argument to get the message. Below is !analyze –v output from 32-bit and 64-bit dumps generated with a three-minute delay:

32-bit dump:

kd> !analyze –v

MANUALLY_INITIATED_CRASH (e2)
The user manually initiated this crash dump.
Arguments:
Arg1: cccccccc
Arg2: 824c7434
Arg3: 000001a4
Arg4: 000000b4

Debugging Details:
------------------


BUGCHECK_STR: MANUALLY_INITIATED_CRASH

DEFAULT_BUCKET_ID: DRIVER_FAULT

LAST_CONTROL_TRANSFER: from f7e695a3 to 8053331e

STACK_TEXT: 
f2522d84 f7e695a3 000000e2 cccccccc 824c7434 nt!KeBugCheckEx+0x1b
f2522dac 8057be15 824c7338 00000000 00000000 SystemDump!BSODThread+0x51
f2522ddc 804fa4da f7e69552 824c7338 00000000 nt!PspSystemThreadStartup+0x300000000 00000000 00000000 00000000 00000000 nt!KiThreadStartup+0x16


FOLLOWUP_IP:
SystemDump!BSODThread+51
f7e695a3 57 push edi

SYMBOL_STACK_INDEX: 1

FOLLOWUP_NAME: MachineOwner

SYMBOL_NAME: SystemDump!BSODThread+51

MODULE_NAME: SystemDump

IMAGE_NAME: SystemDump.sys

DEBUG_FLR_IMAGE_TIMESTAMP: 44a6ca55

STACK_COMMAND: kb

FAILURE_BUCKET_ID: MANUALLY_INITIATED_CRASH_SystemDump!BSODThread+51

BUCKET_ID: MANUALLY_INITIATED_CRASH_SystemDump!BSODThread+51

Followup: MachineOwner
---------

kd> du 824c7434
824c7434 "The server is slow and all conne"
824c7474 "ctions are refused...I'm generat"
824c74b4 "ing this dump from the console s"
824c74f4 "ession and ..scheduled it in 3 m"
824c7534 "inutes. Please look at it and..s"
824c7574 "ee if you can find anything susp"
824c75b4 "icious in it!"

64-bit dump:

kd> !analyze –v

MANUALLY_INITIATED_CRASH (e2)
The user manually initiated this crash dump.
Arguments:
Arg1: 00000000cccccccc
Arg2: fffffadfe653c7a8
Arg3: 00000000000001a8
Arg4: 00000000000000b4

Debugging Details:
------------------


BUGCHECK_STR: MANUALLY_INITIATED_CRASH

DEFAULT_BUCKET_ID: DRIVER_FAULT

CURRENT_IRQL: 0

LAST_CONTROL_TRANSFER: from fffffadfe0eb6162 to fffff80001041690

STACK_TEXT: 
fffffadf`e3a18d28 fffffadf`e0eb6162 : 00000000`000000e2 00000000`cccccccc fffffadf`e653c7a8 00000000`000001a8 : nt!KeBugCheckEx
fffffadf`e3a18d30 fffff800`012b331e : fffffadf`00000000 fffffadf`e649f5f0 fffffadf`e669f890 fffffadf`e6fad040 : SystemDump64!BSODThread+0x72
fffffadf`e3a18d70 fffff800`01044196 : fffff800`01176180 fffffadf`e669f890 fffffadf`e6fad040 fffff800`0117abc0 : nt!PspSystemThreadStartup+0x3e
fffffadf`e3a18dd0 00000000`00000000 : 00000000`00000000 00000000`00000000 00000000`00000000 00000000`00000000 : nt!KxStartSystemThread+0x16


STACK_COMMAND: kb

FOLLOWUP_IP: 
SystemDump64!BSODThread+72
fffffadf`e0eb6162 cc int 3

SYMBOL_STACK_INDEX: 1

FOLLOWUP_NAME: MachineOwner

SYMBOL_NAME: SystemDump64!BSODThread+72

MODULE_NAME: SystemDump64

IMAGE_NAME: SystemDump64.sys

DEBUG_FLR_IMAGE_TIMESTAMP: 44a6b998

FAILURE_BUCKET_ID: X64_MANUALLY_INITIATED_CRASH_SystemDump64!BSODThread+72

BUCKET_ID: X64_MANUALLY_INITIATED_CRASH_SystemDump64!BSODThread+72

Followup: MachineOwner
---------

kd> du fffffadfe653c7a8
fffffadf`e653c7a8 "The server is slow and all conne"
fffffadf`e653c7e8 "ctions are refused. ..I'm genera"
fffffadf`e653c828 "ting this dump from the console "
fffffadf`e653c868 "session and ..scheduled it in 3 "
fffffadf`e653c8a8 "minutes. Please look at it and ."
fffffadf`e653c8e8 ".see if you can find anything su"
fffffadf`e653c928 "spicious in it!"

Uninstalling SystemDump
To uninstall this utility, delete the executable file and driver.

Disclaimer

These software applications are provided to you as is with no representations, warranties or conditions of any kind. You may use and distribute it at your own risk. CITRIX DISCLAIMS ALL WARRANTIES WHATSOEVER, EXPRESS, IMPLIED, WRITTEN, ORAL OR STATUTORY, INCLUDING WITHOUT LIMITATION WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NONINFRINGEMENT. Without limiting the generality of the foregoing, you acknowledge and agree that (a) the software application may exhibit errors, design flaws or other problems, possibly resulting in loss of data or damage to property; (b) it may not be possible to make the software application fully functional; and (c) Citrix may, without notice or liability to you, cease to make available the current version and/or any future versions of the software application. In no event should the code be used to support of ultra-hazardous activities, including but not limited to life support or blasting activities. NEITHER CITRIX NOR ITS AFFILIATES OR AGENTS WILL BE LIABLE, UNDER BREACH OF CONTRACT OR ANY OTHER THEORY OF LIABILITY, FOR ANY DAMAGES WHATSOEVER ARISING FROM USE OF THE SOFTWARE APPLICATION, INCLUDING WITHOUT LIMITATION DIRECT, SPECIAL, INCIDENTAL, PUNITIVE, CONSEQUENTIAL OR OTHER DAMAGES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. You agree to indemnify and defend Citrix against any and all claims arising from your use, modification or distribution of the code.



This document applies to:
Presentation Server 4.0 for Microsoft Windows 2000
Presentation Server 4.0 for Microsoft Windows 2003
Presentation Server 4.0 x64 Edition
Presentation Server 4.5 for Windows Server 2003
Presentation Server 4.5 for Windows Server 2003 x64 Edition