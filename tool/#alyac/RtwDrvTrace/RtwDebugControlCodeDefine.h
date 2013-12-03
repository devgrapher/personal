// 실시간 드라이버 컨트롤 코드 정의
#pragma once

// 일반
#define		CF_CTRL							0x0000
#define		CF_CTRL_BSOD_NOW				0x0001 // ALIAS="BSOD 발생"

// 후킹무력화 관련
#define		HD_CTRL							0x0100
#define		HD_CTRL_ON						0x0101 // ALIAS="후킹무력화 활성화"
#define		HD_CTRL_OFF						0x0102 // ALIAS="후킹무력화 비활성화"
#define		HD_CTRL_STATUS					0x0103 // ALIAS="후킹무력화 상태 표시"

// 자가보호 관련
#define		SP_CTRL						    0x0200
#define		SP_CTRL_PROCESS_PROTECT_ON  	0x0201 // ALIAS="프로세스 자가보호 활성화"
#define		SP_CTRL_PROCESS_PROTECT_OFF 	0x0202 // ALIAS="프로세스 자가보호 비활성화"
#define		SP_CTRL_PROCESS_PROTECT_STATUS	0x0203 // ALIAS="프로세스 자가보호 상태 표시"
#define		SP_CTRL_PROCESS_PROTECT_BSOD    0x0204 // ALIAS="프로세스 접근 차단 시 BSOD"
#define		SP_CTRL_THREAD_PROTECT_ON		0x0205 // ALIAS="스레드 자가보호 활성화"
#define		SP_CTRL_THREAD_PROTECT_OFF      0x0206 // ALIAS="스레드 자가보호 비활성화"
#define		SP_CTRL_THREAD_PROTECT_STATUS   0x0207 // ALIAS="스레드 자가보호 상태 표시"
#define		SP_CTRL_FILE_PROTECT_ON			0x0208 // ALIAS="파일 자가보호 활성화"
#define		SP_CTRL_FILE_PROTECT_OFF        0x0209 // ALIAS="파일 자가보호 비활성화"
#define		SP_CTRL_FILE_PROTECT_STATUS     0x020A // ALIAS="파일 자가보호 상태 표시"
#define		SP_CTRL_FILE_NOTIFY_ON			0x020B // ALIAS="파일 접근 알림 활성화"
#define		SP_CTRL_FILE_NOTIFY_OFF         0x020C // ALIAS="파일 접근 알림 비활성화"
#define		SP_CTRL_FILE_NOTIFY_STATUS      0x020D // ALIAS="파일 접근 알림 상태 표시"


// 프로세스 테이블관련
#define		PT_CTRL							0x0300
#define		PT_CTRL_DISPLAY_PROCESS_TABLE	0x0301 // ALIAS="프로세스 테이블 표시"

// 파일 타입 검사
#define		FTC_CTRL						0x0400
#define		FTC_CTRL_DISPLAY_EXTENSION_LIST	0x0401 // ALIAS="검사대상 확장자 목록 표시"

// 파일 스캔
#define		FS_CTRL							0x0500
#define		FS_CTRL_STATUS					0x0501 // ALIAS="파일 스캔 설정 표시"

// 볼륨 매니져
#define		VM_CTRL							0x0600
#define		VM_CTRL_LIST					0x0601 // ALIAS="볼륨 목록 표시"

// 파일 스캔 결과
#define		FSR_CTRL						0x0700
#define		FSR_CTRL_CLEAR_TABLE			0x0701 // ALIAS="스캔 해쉬 테이블 클리어"

// 경로 정책
#define		PP_CTRL							0x0800
#define		PP_CTRL_POLICY_LIST				0x0801 // ALIAS="경로 정책 리스트 표시"

// 파일 감시
#define		FM_CTRL							0x0900
#define		FM_CTRL_BSOD_ON_BLOCK			0x0901 // ALIAS="파일보호 접근 차단시 BSOD"
#define     FM_CTRL_PROTECTOR_STATUS        0x0902 // ALIAS="파일보호 상태 표시"