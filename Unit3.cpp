//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall Thread3::Thread3(TEvent *MyEvent, sqlite3 *DB,int Position, AnsiString Type,bool CreateSuspended)
	: TThread(CreateSuspended)
{
   type=Type;
   position=Position;
   db=DB;
   myEvent=MyEvent;
}
//---------------------------------------------------------------------------
void __fastcall Thread3::Execute()
{
        Synchronize(&UpdateCaption);
}
//---------------------------------------------------------------------------
	  void __fastcall Thread3::UpdateCaption()
	  {
		AnsiString sql="INSERT INTO FILE (ID, NAME) VALUES ("+(AnsiString)position+", \""+type+"\" );";
		sqlite3_exec(db, sql.c_str(), NULL, 0,NULL);
        myEvent->ResetEvent();
	  }
