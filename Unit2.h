//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "FileSystem.h"
//---------------------------------------------------------------------------
class Thread2 : public TThread
{
private:
	FileSystem File;
	void __fastcall UpdateTable();
	void __fastcall End();
	class Thread3 *myTread3;
    bool CheckThread3();
protected:
	void __fastcall Execute();
public:
	__fastcall Thread2(FileSystem file,bool CreateSuspended);
	TEvent *MyEvent;
};
//---------------------------------------------------------------------------
#endif
