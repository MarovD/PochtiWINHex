#pragma once
#include "Unit1.h"
class FileSystem {
protected:

	HANDLE fileHander;
	long GetDec(byte vBootRecord[],int size);

public:
	unsigned long long size=0;
	unsigned long long countCluster=1;
	int clusterSize=512;

    bool ReedBootRecord(wchar_t* path,BYTE *dataBuffer);
    bool ReedFileHander(wchar_t* path);
	bool ReedCluster(int number, BYTE *outBuffer);
	void ViewInfo(TLabel *Label);

};



