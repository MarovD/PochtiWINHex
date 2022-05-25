#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include "Unit1.h"

class CheckSign {
public:
	UnicodeString CheckSigns(BYTE *dataBuffer);
private:
	bool Check(int pos,BYTE sign[],int length,BYTE *dataBuffer);
};

#endif
