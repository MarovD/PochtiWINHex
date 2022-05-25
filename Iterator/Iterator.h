#include <tchar.h>
#include <windows.h>

#include "FileSystem.h"

class Iterator
{
protected:
	unsigned int Position;
	unsigned long long Done;
	unsigned long long end;
public:
	Iterator();
	Iterator(FileSystem file);

	FileSystem File;

	void SetPosition(unsigned long position);
    unsigned int GetPosition();
	void SetDone(unsigned long count);
	void First();
	void End();
	void Next();
	bool IsDone();
	virtual bool GetCurrent(byte *dataBuffer);
};


