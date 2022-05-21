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
	byte Rezerv[2];
	byte FAT;
	byte Skip[15];
	byte TotalSector[4];
	byte FATSize[4];


} FAT32_BootRecord;

#pragma pack(pop)

#endif