#pragma once
#include "Unit1.h"
#include <iostream>

class FileSystem {
protected:

	HANDLE fileHander;
	long GetDec(byte vBootRecord[],int size);

public:
	unsigned long long size=512;
	unsigned long long countCluster=1;
	int clusterSize=512;
    String name;

    bool ReedBootRecord(wchar_t* path,BYTE *dataBuffer);
    bool ReedFileHander(wchar_t* path);
	bool ReedCluster(unsigned long long number, BYTE *dataBuffer);
	void ViewInfo(TLabel *Label);
	void ClosedHandle();

};



