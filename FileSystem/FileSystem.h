#pragma once
class FileSystem {
protected:

	HANDLE fileHander;

	long GetDec(byte vBootRecord[],int size);
	bool ReedBootRecord(wchar_t* path, byte *dataBuffer);


public:
	unsigned long long size;
	unsigned long long countCluster;
	int clusterSize;
	bool ReedCluster(int number, BYTE *outBuffer);
	void ViewInfo(TLabel *Label);

};


long FileSystem::GetDec(byte vBootRecord[],int size){

	long sum=0;
	for (int i = 0; i < size; i++)
	{
		sum+=vBootRecord[i]*std::pow(16,i*2);
	}
	return sum;
}

bool FileSystem::ReedBootRecord(wchar_t* path, byte *dataBuffer){

    fileHander=CreateFileW(path,
	GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
		SendMessageW(L"Ошибка чтения файла. Используйте права администратора.");
		CloseHandle(fileHander);
		return false;
	}

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=0;


	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
		 CloseHandle(fileHander);
		 delete[] dataBuffer;
		 return false;
	 }

	 DWORD bytesToRead=512;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		CloseHandle(fileHander);
		delete[] dataBuffer;
		return false;
	 }
	 return true;
	}

bool FileSystem::ReedCluster(int number, BYTE *outBuffer){
	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=clusterSize*number;

	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
	 SendMessageW(L"Ошибка установки курсора.");
	 return false;
	 }

	 DWORD bytesToRead=clusterSize;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,outBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		 SendMessageW(L"Ошибка чтения кластера.");
		 return false;
	 }
     return true;
	}

void FileSystem::ViewInfo(TLabel *Label){

		Label->Caption="Размер: ";
		Label->Caption+=size;
		Label->Caption+="\nКоличество кластеров: ";
		Label->Caption+=countCluster;
		Label->Caption+="\nРазмер кластера: ";
		Label->Caption+=clusterSize;
	}



