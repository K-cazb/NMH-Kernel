#pragma once
#include <ntdef.h>
#include <ntifs.h>

NTKERNELAPI PVOID PsGetProcessSectionBaseAddress(__in PEPROCESS Process);
NTKERNELAPI PUCHAR PsGetProcessImageFileName(__in PEPROCESS Process);

typedef struct _IOBUFFER
{
	ULONGLONG Destination;
	ULONGLONG Source;
	ULONGLONG Length;
	ULONG     DestinationPid;
	ULONG     SourcePid;
} IOBUFFER, *PIOBUFFER;

#define TARGET_IMAGENAME	L"\\TslGame\\Binaries\\Win64\\TslGame.exe"
#define TARGET_PROCESSNAME	"TslGame.exe"
#define DEVICE_NAME			L"\\Device\\NMH1313"
#define LINK_NAME			L"\\DosDevices\\NMH1313"
#define LINK_GLOBAL_NAME	L"\\DosDevices\\Global\\NMH1313"

#define IOCTL_IO_READ		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8001, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define IOCTL_IO_WRITE		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8012, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define IOCTL_IO_PID		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8023, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define IOCTL_IO_MOUDLE		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8034, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define IOCTL_IO_IMAGESIZE	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8045, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)


LONGLONG lMoudleBase;
HANDLE hPid;
PVOID DriverBuffer;
SIZE_T dImageSize;