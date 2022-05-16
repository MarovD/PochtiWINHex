#include <iostream>

 #include<FAT32.h>

class FAT32 : public FileSystem
{
private:

public:
	FAT32(wchar_t* path)
	{
	byte *dataBuffer = new byte[512];

    ReedBootRecord(path,dataBuffer);

	FAT32_BootRecord* pFAT32_BootRecord = (FAT32_BootRecord*)dataBuffer;

	int BPS=GetDec(pFAT32_BootRecord->BPS,sizeof(pFAT32_BootRecord->BPS));
	int SPC=GetDec(&pFAT32_BootRecord->SPC,sizeof(pFAT32_BootRecord->SPC));
	unsigned long long TotalSector=GetDec(pFAT32_BootRecord->TotalSector,sizeof(pFAT32_BootRecord->TotalSector));

	clusterSize=BPS*SPC;
	countCluster=TotalSector/SPC;
	size=countCluster*clusterSize;

	delete[] dataBuffer;
	}

	~FAT32(){
	 CloseHandle(fileHander);
	}
};


