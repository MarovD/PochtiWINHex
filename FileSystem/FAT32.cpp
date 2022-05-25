#include "FAT32.h"

FAT32::FAT32(wchar_t* path)
{
	byte *dataBuffer = new byte[512];

	if(ReedBootRecord(path,dataBuffer))
	{
		FAT32_BootRecord* pFAT32_BootRecord = (FAT32_BootRecord*)dataBuffer;

		int BPS=GetDec(pFAT32_BootRecord->BPS,sizeof(pFAT32_BootRecord->BPS));
		int SPC=GetDec(&pFAT32_BootRecord->SPC,sizeof(pFAT32_BootRecord->SPC));
		unsigned long long TotalSector=GetDec(pFAT32_BootRecord->TotalSector,sizeof(pFAT32_BootRecord->TotalSector));

		int Rezerv=GetDec(pFAT32_BootRecord->Rezerv,sizeof(pFAT32_BootRecord->Rezerv));
		int FAT=GetDec(&pFAT32_BootRecord->FAT,sizeof(pFAT32_BootRecord->FAT));
		unsigned long long FATSize=GetDec(pFAT32_BootRecord->FATSize,sizeof(pFAT32_BootRecord->FATSize));


        name="FAT32";
		clusterSize=BPS*SPC;
		countCluster=(TotalSector-Rezerv-FAT*FATSize)/SPC;
		size=countCluster*clusterSize;
	}
	delete[] dataBuffer;
}




