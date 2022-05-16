#pragma once
class FileSystem {
protected:
int GetDec(byte vBootRecord[],int size)
{
	long sum=0;
	for (int i = 0; i < size; i++)
	{
		sum+=vBootRecord[i]*std::pow(16,i*2);
	}
	return sum;
}
HANDLE fileHander;
public:
	int size;
	int countCluster;
	int clusterSize;
	virtual void ReedCluster(int number, BYTE *outBuffer)=0;
	void ViewInfo(){
	std::wcout<<L"Размер: "<< size<<L" байт"<<std::endl;
	std::wcout<<L"Количество кластеров: "<< countCluster<<std::endl;
	std::wcout<<L"Размер кластера: "<< clusterSize<<L" байт"<<std::endl;
	}
};
