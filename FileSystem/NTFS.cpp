#include "NTFS.h"

NTFS::NTFS(wchar_t* path)
	{
	byte *dataBuffer = new byte[512];

	if(ReedBootRecord(path,dataBuffer))
	{
		NTFS_BootRecord* pNTFS_BootRecord = (NTFS_BootRecord*)dataBuffer;

		int BPS=GetDec(pNTFS_BootRecord->BPS,sizeof(pNTFS_BootRecord->BPS));
		int SPC=GetDec(&pNTFS_BootRecord->SPC,sizeof(pNTFS_BootRecord->SPC));
		unsigned long long TotalSector=GetDec(pNTFS_BootRecord->TotalSector,sizeof(pNTFS_BootRecord->TotalSector));

        name="NTFS";
		clusterSize=BPS*SPC;
		countCluster=TotalSector/SPC;
		size=countCluster*clusterSize;

	}

	delete[] dataBuffer;
	}


