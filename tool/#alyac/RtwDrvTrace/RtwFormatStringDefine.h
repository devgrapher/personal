// 실시간 드라이버 스트링 포맷 정의
#pragma once

// filter 0 : 공용 (CF)
#define		CF_NEWLINE						0x00000001	 // "\n"
#define		CF_UNICODE_STRING				0x00000002	 // "%S\n"
#define		CF_ASCII_STRING					0x00000003	 // "%s\n"

// filter 1 : 후킹무력화 관련 (HD : Hooking Defense)
#define		HD_ON_CALLED					0x00000100	 // "HD HookDefenseOn()    Called\n"
#define		HD_ON_LEAVED					0x00000101	 // "HD HookDefenseOn()    Leaved (status = %08X)\n"
#define		HD_OFF_CALLED					0x00000102	 // "HD HookDefenseOff()   Called\n"
#define		HD_OFF_LEAVED					0x00000103	 // "HD HookDefenseOff()   Leaved\n"
#define		HD_MY_SERVICE_TABLE				0x00000104	 // "My ServiceTable : %p\n"
#define		HD_MY_SERVICE_TABLE_ENTRY		0x00000105	 // "%3d : %p\n"
#define		HD_FAILED_IN_DUPLICATION		0x00000106	 // "HD HookDefenseOn()::Failed in duplication\n"
#define		HD_DUPLICATION_EXISTS			0x00000107	 // "HD HookDefenseOn()::Duplicate Function exists\n"
#define		HD_ENABLE_HOOK_DEFENSE			0x00000108	 // "HD EnableHookDefense\n"
#define		HD_DISABLE_HOOK_DEFENSE			0x00000109	 // "HD DisableHookDefense\n"

// filter 2 : 자가보호 관련 (SP : Self Protection)
#define		SP_MESSAGE_ON_BLOCK			    0x00000200	 // "SP Host(Name: %s, PID: %4d, TID: %4d) ---> Target(Name: %s, PID: %4d, AccessRight: 0x%06X, ObjectType: %s)\n"
#define		SP_VM_IS_ALLOWED                0x00000201	 // "SP VM_OPERATION is allowed\n"
#define		SP_OB_POINTER_IS_RESTRICTED	    0x00000202	 // "SP ObOpenObjectByPointer() is restricted\n"
#define		SP_OB_POINTER_IS_DENIED		    0x00000203	 // "SP ObOpenObjectByPointer() is denied\n"
#define		SP_OB_REFERNCE_IS_DENIED		0x00000204	 // "SP ObReferenceObjectByHandle() is denied or is resticted\n"
#define		SP_INSTALL_CALLED				0x00000205	 // "SP InstallProtectionHook()      Called\n" 
#define		SP_INSTALL_LEAVED				0x00000206	 // "SP InstallProtectionHook()      Leaved with %d\n" 
#define		SP_UNINSTALL_CALLED			    0x00000207	 // "SP UninstallProtectionHook()    Called\n" 
#define		SP_UNINSTALL_LEAVED			    0x00000208	 // "SP UninstallProtectionHook()    Leaved with %d\n" 
#define     SP_PROCESS_PROTECT_STATUS       0x00000209   // "SP Process Protection Status (Enable: %d, Action: 0x%08X)\n"
#define     SP_THREAD_PROTECT_STATUS        0x0000020A   // "SP Thread Protection Status (Enable: %d, Action: 0x%08X)\n"
#define     SP_FILE_PROTECT_STATUS          0x0000020B   // "SP File Protection Status (Enable: %d, Action: 0x%08X)\n"
#define     SP_FILE_NOTIFY_STATUS           0x0000020C   // "SP File Notification Status (Enable: %d, Action: 0x%08X)\n"


// filter 4 : 프로세스 테이블관련 (PT : Process Table)
#define		PT_PROCESS_POLICY				0x00000401	 // "PT processType : 0x%04X productType : 0x%04X\n"
#define		PT_PROCESS_TABLE_ENTRY_INFO		0x00000402	 // "PT PID: %4d(%X) Crc32: %08X, Length: %d\n    Path: %wZ\n"
#define     PT_PROCESS_CREATE_NOTIFY        0x00000403   // "PT Process created (pid: %4d(0x%08X), parent: %4d(0x%08X))\n"
#define     PT_PROCESS_DELETE_NOTIFY        0x00000404   // "PT Process terminated (pid: %4d(0x%08X), parent: %4d(0x%08X))\n"
#define     PT_THREAD_CREATE_NOTIFY         0x00000405   // "PT Thread created (pid: %4d(0x%08X), tid: %4d(0x%08X))\n"
#define     PT_THREAD_DELETE_NOTIFY         0x00000406   // "PT Thread terminated (pid: %4d(0x%08X), tid: %4d(0x%08X))\n"
#define     PT_LOAD_IMAGE_NOTIFY            0x00000407   // "PT Image loaded (pid: %4d(0x%08X), path: %wZ)\n"

// 파일 타입 검사 관련 (FTC : File Type Checker)

// filter 8 : 파일 스캔 관련 (FS : File Scanner)
#define		FS_STATUS_STRING1				0x00000801	 // "FS File Scanner Status\ng_fileScannerEnabled = %d\ng_unknownFileScanEnabled = %d\ng_archiveFileScanEnabled = %d\n"
#define		FS_STATUS_STRING2				0x00000802	 // "FS g_archiveFileLimitSize = %I64d\ng_setupFileScanEnabled = %d\ng_setupFileLimitSize = %I64d\ng_oleFileScanEnabled = %d\ng_heuristicFileScanEnabled = %d\ng_scanableFileAction = %d\n"
#define     FS_ENABLE_FILE_SCANNER          0x00000803   // "FS Enable file scanner (ScanAction: 0x%08X)\n"
#define     FS_DISABLE_FILE_SCANNER         0x00000804   // "FS Disable file scanner\n"
#define     FS_PUSH_PENDED_CALLBACK         0x00000805   // "FS Push pended callback %wZ\n"
#define     FS_POP_PENDED_CALLBACK          0x00000806   // "FS Pop pended callback %wZ\n"
#define     FS_INSERT_BACKGROUND_SCAN_FILE  0x00000807   // "FS Insert Background ScanFile (%wZ)\n"
#define     FS_REMOVE_BACKGROUND_SCAN_FILE  0x00000808   // "FS Remove Background ScanFile (%wZ)\n"
#define     FS_REQUEST_SCAN                 0x00000809   // "FS Request Scan(%S, pid: %4d, engine: 0x%08X, operation: 0x%08X, handle: 0x%08X, type: 0x%08X)\n"
#define     FS_RESULT_SCAN                  0x0000080A   // "FS Result  Scan(%S, pid: %4d, result: 0x%08X)\n"
#define     FS_START_OPEN_FILE              0x0000080B   // "FS Start openning file(%wZ flags: 0x%08X, busy: %d, lock: %d)\n"
#define     FS_END_OPEN_FILE                0x0000080C   // "FS End openning file(%wZ, status: 0x%08X, fileObject: 0x%08X, handle: 0x%08X)\n"
#define     FS_START_CLOSE_FILE_HANDLE      0x0000080D   // "FS Start closing file(fileHandle: 0x%08X, fileObject:0x%08X)\n"
#define     FS_END_CLOSE_FILE_HANDLE        0x0000080E   // "FS End closing file(fileHandle: 0x%08X, fileObject:0x%08X)\n"
#define     FS_START_CANCEL_FILE_OPEN       0x0000080F   // "FA Start cancel file open(status: 0x%08X, flags: 0x%08X, instance: 0x%08X, fileObject: 0x%08X)\n"
#define     FS_END_CANCEL_FILE_OPEN         0x00000810   // "FA End cancel file open(result: 0x%08X, instance: 0x%08X, fileObject: 0x%08X)\n"

// filter 10 : 파일 보호 관련 (FP : File Protector)
#define     FP_ENABLE_FILE_PROTECTOR        0x00001001   // "FP Enable file protector (FileAction: 0x%08X)\n"
#define     FP_DISABLE_FILE_PROTECTOR       0x00001002   // "FP Disable file protector\n"

// filter 20 : 볼륨 매니저 (VM : Volume Manager)	
#define		VM_LIST_TITLE					0x00002001	 // "VM === Volume Data List ===\n"
#define		VM_LIST							0x00002002	 // "VM volume : %p\nSectorSize = %u\nClusterSize = %u\nDeviceType = %u\nName = %S\nDosName = %S\n"

// filter 40 : 경로 정책 (PP : Path Policy)
#define		PP_PATH_POLICY_ENTRY_INFO		0x00004001	 // "PP  CRC : %X\n"
#define		PP_PATH_POLICY					0x00004002	 // "PP Type : 0x%02X, PathPolicy : 0x%02X, NamePolicy : 0x%02X, ExtPolicy : 0x%02X\n"

// filter 80 : 파일 감시 (FM : File Monitor)
#define		FM_MESSAGE_ON_BLOCK1			0x00008001	 // "FM Subject  Name : %15s,  PID : %4d,  TID : %4d\n"
#define		FM_MESSAGE_ON_BLOCK2			0x00008002	 // "FM TargetFile : %wZ\nFileAction : %08X, ProtectedAction : %08X\n"
#define     FM_PRINT_PROTECTOR_STATUS       0x00008003   // "FM FileProtector (Status: %d, FileAction: 0x%08X)\n"

// filter 100 : 유저 통신 (UC : User Communication)
#define     UC_SEND_MESSAGE_TO_USER         0x00010001   // "UC SendMessageToUser......(filter: 0x%08X, client: 0x%08X, message: 0x%08X, inBuffer: 0x%08X, bufferSize: %d)\n"
#define     UC_RETURN_RESULT_FROM_USER      0x00010002   // "UC ReturnResultFromUser...(filter: 0x%08X, client: 0x%08X, status: 0x%08X, outBuffer: 0x%08X, bufferSize: %d)\n"
#define		UC_ON_MESSAGE_TIMEOUT			0x00010003	 // "UC HandleSendMessageFailed()::Timeout, TimeoutLimitCount %d\n"
#define     UC_ON_MESSAGE_SET_TIMEOUT_EVENT 0x00010004   // "UC HandleSendMessageFailed()::Set Timeout event (event: 0x%08X)\n"
#define		UC_ON_MESSAGE_DISCONNECT		0x00010005	 // "UC HandleSendMessageFailed()::Client has been already Disconnected\n"
#define		UC_ON_MESSAGE_FAULT				0x00010006	 // "UC HandleSendMessageFailed()::Failed (status = %08X)\n"
#define     UC_CREATE_SERVER_PORT           0x00010007   // "UC Create Server Port(port: 0x%08X)\n"
#define     UC_CLOSE_SERVER_PORT            0x00010008   // "UC Close Server Port(0x%08X)\n"
#define     UC_CLIENT_PORT_CONNECTED        0x00010009   // "UC Client was connected(pid: %4d(0x%08X), port: 0x%08X)\n"
#define     UC_CLIENT_PORT_DISCONNECTED     0x0001000A   // "UC Client was disconnected(pid: %4d(0x%08X), port: 0x%08X)\n"
#define     UC_CREATE_USER_TIMEOUT          0x0001000B   // "UC Create User Timeout Event(event: 0x%08X)\n"
#define     UC_CLOSE_USER_TIMEOUT           0x0001000C   // "UC Close User Timeout Event(event: 0x%08X)\n"
#define     UC_CLIENT_PROCESS_TERMINATED    0x0001000D   // "UC Client process was terminated(pid: %4d(0x%08X))\n"
#define     UC_CLIENT_THREAD_TERMINATED     0x0001000E   // "UC Client thread was terminated(pid: %4d(0x%08X), tid: %4d(0x%08X))\n"
#define     UC_WORKER_THREAD_CREATED        0x0001000F   // "UC Worker thread was created(order: %d, tid: %4d(0x%08X))\n"

// filter 200 : 드라이버 작동 (DO : Driver Operation)
#define		DO_DRIVER_ENTRY_CALLED			0x00020001	 // "DO DriverEntry()  Called (ClientID : %u:%u)\n"
#define		DO_DRIVER_ENTRY_LEAVED			0x00020002	 // "DO DriverEntry()  Leaved (status = %08X, ClientID : %u:%u)\n"
#define		DO_DRIVER_EXIT_CALLED			0x00020003	 // "DO DriverExit()  Called (ClientID : %u:%u)\n"
#define		DO_DRIVER_EXIT_LEAVED			0x00020004	 // "DO DriverExit()  Leaved (status = %08X, ClientID : %u:%u)\n"

// filter 400 : 드라이버 작동 (FN : File Notifier)
#define     FN_ENABLE_FILE_NOTIFIER         0x00040001   // "FN Enable file notifier (FileAction: 0x%08X)\n"
#define     FN_DISABLE_FILE_NOTIFIER        0x00040002   // "FN Disable file notifier\n"
