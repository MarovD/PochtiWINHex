#include <tchar.h>
#include <windows.h>
#include "NTFS.h"
#include "FAT32.h"
#include "NON.h"

enum FS {Entfs , Efat32, ENON};

class Factory
{
public:
	Factory();
	FileSystem CreateFS(wchar_t* path);
private:
	FS DefinitionFS(byte *dataBuffer);
};


