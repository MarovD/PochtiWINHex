//---------------------------------------------------------------------------
#include <System.hpp>
#pragma hdrstop

#include <sqlite3.h>
#include <typeinfo>

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"

#include "PassDecorator.h"
#include "CheckSign.h"

#pragma package(smart_init)
unsigned long count;
__fastcall Thread2::Thread2(FileSystem file,bool CreateSuspended)
	: TThread(CreateSuspended)
{
	File=file;
	MyEvent = new TEvent(NULL,true,false,"",false);
	myTread3=NULL;

}
//---------------------------------------------------------------------------
void __fastcall Thread2::Execute()
{
    count=0;
	Form1->FindSignButton->Enabled=false;
	Form1->OpenFSButton->Enabled=false;
	Form1->Edit1->Enabled=false;

	char* db_name = "Databases.db";
	sqlite3 *db;
    if ( sqlite3_open(db_name,&db))
	{
		sqlite3_close(db);
	}

	Iterator iterator=Iterator(File);

	if(Form1->ClusterReadingMode->ItemIndex==1)
	iterator=PassDecorator(iterator);

	UnicodeString type;
	if(File.countCluster!=0)
	{
		if(Form1->Edit2->Text=="")
			iterator.First();
		else
			iterator.SetPosition(StrToLong(Form1->Edit2->Text));

		if(Form1->Edit3->Text=="")
			iterator.End();
		else
			iterator.SetDone(StrToLong(Form1->Edit3->Text));

		byte *dataBuffer = new byte[File.clusterSize];
		CheckSign check;
		for(;!iterator.IsDone();iterator.Next()){
		 if(iterator.GetCurrent(dataBuffer))
			{
				type=check.CheckSigns(dataBuffer);
				count++;
				if(count%10000==0)
					Synchronize(&UpdateTable);
				if(type!="NON")
				{
				 if(CheckThread3())
					{
				 	MyEvent->SetEvent();
					myTread3=new Thread3(MyEvent,db,iterator.GetPosition(),type,false);
					}
				}

			 }
		}
		delete[] dataBuffer;
	}

	CheckThread3();

	myTread3->Terminate();
	sqlite3_close(db);
	Synchronize(&End);
}
//---------------------------------------------------------------------------
void __fastcall Thread2::UpdateTable()
{
  Form1->ReloadViewDB();
  Form1->Label2->Caption="Кластеров считано\n";
  Form1->Label2->Caption+=count;

}
void __fastcall Thread2::End()
{
  Form1->FindSignButton->Enabled=true;
  Form1->OpenFSButton->Enabled=true;
  Form1->Edit1->Enabled=true;
  Form1->ReloadViewDB();
}
bool Thread2::CheckThread3(){
	while (MyEvent->WaitFor(0)==wrSignaled)
	{
	 Sleep(1);
	}
    return true;
}
