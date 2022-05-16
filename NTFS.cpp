#include <iostream>

#include<NTFS.h>

class NTFS : public FileSystem
{
public:
	NTFS(wchar_t* path)
	{

	fileHander=CreateFileW(path,
	GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
		std::wcout<<L"Ошибка чтения файла. Используйте права администратора.\n";
		CloseHandle(fileHander);
		system("pause");
	}

	byte *dataBuffer = new byte[512];

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=0;


	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
		 CloseHandle(fileHander);
		 delete[] dataBuffer;
	 }

	 DWORD bytesToRead=512;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		CloseHandle(fileHander);
		delete[] dataBuffer;
	 }


	NTFS_BootRecord* pNTFS_BootRecord = (NTFS_BootRecord*)dataBuffer;

	int BPS=GetDec(pNTFS_BootRecord->BPS,sizeof(pNTFS_BootRecord->BPS));
	int SPC=GetDec(&pNTFS_BootRecord->SPC,sizeof(pNTFS_BootRecord->SPC));
	int TotalSector=GetDec(pNTFS_BootRecord->TotalSector,sizeof(pNTFS_BootRecord->TotalSector));


	size=TotalSector*BPS;
	countCluster=TotalSector/SPC;
	clusterSize=BPS*SPC;
	delete[] dataBuffer;
	}

	void ReedCluster(int number, BYTE *outBuffer) override
	{
    	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=clusterSize*number;

	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
	 std::wcout<<L"Ошибка установки курсора.\n";
	 }

	 DWORD bytesToRead=clusterSize;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,outBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
     	 std::wcout<<L"Ошибка чтения кластера.\n";
	 }
	}
	~NTFS(){

	 CloseHandle(fileHander);
	}
};


