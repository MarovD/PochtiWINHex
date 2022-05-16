#include <iostream>

 #include<FAT.h>

class FAT : public FileSystem
{
private:
public:
	FAT()
	{
	}
	void ReedCluster(int number, BYTE *outBuffer) override
	{

	const char* str="Privet FAT";
	std::cout<<str;


	}
	~FAT(){


	}
};


