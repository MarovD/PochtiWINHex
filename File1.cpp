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
#include<FAT.cpp>


int main()
{
    setlocale (LC_ALL, ".866");

	wchar_t *fileName =L"\\\\.\\C:";

	NTFS file=NTFS(fileName);
	file.ViewInfo();
	byte *dataBuffer = new byte[file.clusterSize];
	file.ReedCluster(2,dataBuffer);

	for(int i=0; i <file.clusterSize;i++){
	std::wcout<<std::hex<<dataBuffer[i]<<" ";
	if(i%15==0 && i!=0)
    	std::wcout<<std::endl;
	}

	system("pause");

	delete[] dataBuffer;

	return 0;
}
