#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>

#include<NTFS.cpp>
#include<FAT32.cpp>

void ViewBuffer(FileSystem file){
	unsigned int numCluster;
    byte *dataBuffer = new byte[file.clusterSize];
	std::wcout<<L"Введите номер кластера для просмотра: ";
	std::wcin>>numCluster;
	if(numCluster<=file.clusterSize)
	{file.ReedCluster(numCluster,dataBuffer);
		for(int i=0;i<file.clusterSize; i++){
			 std::wcout<<std::hex<<dataBuffer[i]<<" ";
			 if(i%15==0 && i!=0)
				std::wcout<<std::endl;
		}
	}

	delete[] dataBuffer;
}

int main()
{
	setlocale (LC_ALL, ".866");
	int flag;

	std::wcout<<L"1. Тест ФС NTFS на диске C:\n";
	std::wcout<<L"2. Тест ФС FAT32 на диске D:\nВыбор: ";
	std::wcin>>flag;

	if(flag==1){

	wchar_t *fileName=L"\\\\.\\C:";
	NTFS file=NTFS(fileName);
	file.ViewInfo();
	ViewBuffer(file);

	}
	else if(flag==2){

	wchar_t *fileName=L"\\\\.\\D:";
	FAT32 file=FAT32(fileName);
	file.ViewInfo();
	ViewBuffer(file);
	}
	else{
	 std::wcout<<L"Ошибка выбора.\n";
     system("pause");
     return 0;
    }

	system("pause");
	return 0;
}
