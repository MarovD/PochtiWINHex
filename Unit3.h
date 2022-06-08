//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <sqlite3.h>
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
class Thread3 : public TThread
{
private:

protected:
	void __fastcall Execute();
public:
	__fastcall Thread3(TEvent *MyEvent, sqlite3 *DB,int Position, AnsiString Type,bool CreateSuspended);
    void __fastcall UpdateCaption();
	TEvent *myEvent;
	sqlite3 *db;
	int position;
	AnsiString type;
};
//---------------------------------------------------------------------------
#endif
