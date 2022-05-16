#ifdef _WIN32
#include <tchar.h>
#include <windows.h>


#include<FileSystem.h>

#pragma pack(push,1)

typedef struct
{
	byte Text[0x0B];
	byte BPS[2];
	byte SPC;
	byte Skip[26];
	byte TotalSector[8];
} NTFS_BootRecord;

#pragma pack(pop)

#endif