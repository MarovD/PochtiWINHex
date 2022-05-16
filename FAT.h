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
	byte ReservedS[2];
	byte Zero1[5];
	byte MediaDescription;
	byte Zero2[2];
	byte SectorPerTrack[2];
	byte NOH[2];
	byte HidenSector[4];
	byte NotUse[8];
	byte TotalSector[8];
	byte LogClustNumbMFT[8];
	byte LogClustNumbMFTMirr[8];
	byte ClusPFRS[4];
	byte ClusPIB;
	byte notUsed[3];
	byte VolumeSerNum[8];
	byte Checksum[4];

} FAT_BootRecord;

#pragma pack(pop)

#endif