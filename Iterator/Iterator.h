#include <tchar.h>
#include <windows.h>

#include "FileSystem.h"

class Iterator
{
private:
    unsigned int Position;
	unsigned long long Done;
	unsigned long long end;
    FileSystem File;
public:

	Iterator(FileSystem file);
	void SetPosition(unsigned long position);
	void SetDone(unsigned long count);
	void First();
    void End();
	void Next();
	bool IsDone();
	bool GetCurrent(byte *dataBuffer);
};


