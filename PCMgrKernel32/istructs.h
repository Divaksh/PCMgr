#pragma once
#ifdef TASKMGRCORE_EXPORTS
#include "ntdef.h"
#else
#include <ntdef.h>
#endif

typedef struct tag_NTOS_EPROCESS_OFF_DATA {
	ULONG_PTR EPROCESS_RundownProtectOffest;
	ULONG_PTR EPROCESS_ThreadListHeadOffest;
	ULONG_PTR EPROCESS_FlagsOffest;
	ULONG_PTR ETHREAD_TcbOffest;
	ULONG_PTR ETHREAD_CrossThreadFlagsOffest;
}NTOS_EPROCESS_OFF_DATA, *PNTOS_EPROCESS_OFF_DATA;

typedef struct tag_NTOS_PDB_DATA {
	NTOS_EPROCESS_OFF_DATA StructOffestData;
	ULONG_PTR PspTerminateThreadByPointer_;
	ULONG_PTR PspExitThread_;
	ULONG_PTR PsGetNextProcessThread_;
	ULONG_PTR PsTerminateProcess_;
	ULONG_PTR PsGetNextProcess_;
	ULONG_PTR KeForceResumeThread_;
}NTOS_PDB_DATA, *PNTOS_PDB_DATA;

typedef struct tag_FCLOSE_HANDLE_DATA {
	ULONG_PTR ProcessId;
	HANDLE HandleValue;
}FCLOSE_HANDLE_DATA, *PFCLOSE_HANDLE_DATA;

typedef struct tag_DBGVIEW_SENDER {
	ULONG_PTR ProcessId;
	HANDLE EventHandle;
}DBGVIEW_SENDER, *PDBGVIEW_SENDER;

typedef struct tag_DBGPRT_DATA_TRA {
	BOOLEAN HasData;
	BOOLEAN HasMoreData;
	CHAR Data[128];
}DBGPRT_DATA_TRA, *PDBGPRT_DATA_TRA;

typedef struct tag_KTHREADINFO {
	ULONG_PTR EThread;
	ULONG_PTR TebAddress;
}KTHREADINFO, *PKTHREADINFO;

typedef struct tag_KPROCINFO {
	ULONG_PTR EProcess;
	ULONG_PTR PebAddress;
	ULONG_PTR JobAddress;
	int PriorityClass;
	UCHAR FullPath[260];
}KPROCINFO, *PKPROCINFO;

typedef struct tag_KDAAGRS {
	ULONG_PTR StartAddress;
	ULONG_PTR Size;
}KDAAGRS, *PKDAAGRS;

typedef struct tag_KNTOSVALUE {
	ULONG_PTR NtostAddress;
	WCHAR NtosModuleName[32];
	BOOLEAN KernelDataInited;
}KNTOSVALUE, *PKNTOSVALUE;

typedef struct tag_WindowsVer {
	ULONG VerSimple;
	ULONG WinBulidVerl;
}WINVERS, *PWINVERS;

typedef struct tag_KINITAGRS {
	WINVERS WinVer;
	BOOLEAN NeedNtosVaule;

}KINITAGRS, *PKINITAGRS;




#ifdef _AMD64_
typedef struct tag_KERNEL_MODULE
{
	WCHAR BaseDllName[64];
	WCHAR FullDllPath[260];
	ULONG_PTR EntryPoint;
	ULONG SizeOfImage;
	ULONG_PTR DriverObject;
	ULONG_PTR Base;
	ULONG Order;
}KERNEL_MODULE, *PKERNEL_MODULE;
#else
typedef struct tag_KERNEL_MODULE
{
	WCHAR BaseDllName[64];
	WCHAR FullDllPath[260];
	ULONG EntryPoint;
	ULONG SizeOfImage;
	ULONG_PTR DriverObject;
	ULONG_PTR Base;
	ULONG Order;
}KERNEL_MODULE, *PKERNEL_MODULE;
#endif