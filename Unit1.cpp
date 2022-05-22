//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "FileCtrl.hpp"

#include "Factory.h"
#include "Iterator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
FileSystem File;
Iterator iterator=Iterator(File);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1DblClick(TObject *Sender)
{

	if(RadioButton1->Checked){
	OpenDialog1->Execute();
	Edit1->Text = OpenDialog1->FileName;
	}


	if(RadioButton2->Checked)
	{
	String Dir = "c:\\";
	if(SelectDirectory("”кажите путь к папке","",Dir))
	Edit1->Text = Dir;
	}
	Button2Click(Sender);


}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{

	if(Edit1->Text !="")
	{
		Factory Factory;
		UnicodeString str1="\\\\.\\";
		UnicodeString str2=Edit1->Text;

		if(str2[str2.Length()]=='\\')
		str2[str2.Length()]='\0';
		str2 = StringReplace(str2,"\\","\\\\",TReplaceFlags()<<rfReplaceAll);
		UnicodeString str3=str1+str2;

		wchar_t *fileName=str3.t_str();
		File=Factory.CreateFS(fileName);
		iterator=Iterator(File);
		File.ViewInfo(Label1);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Label2->Caption="";
	if(File.countCluster!=0)
	{
		if(Edit2->Text=="")
			iterator.First();
		else
			iterator.SetPosition(StrToLong(Edit2->Text));

		if(Edit3->Text=="")
			iterator.End();
		else
			iterator.SetDone(StrToLong(Edit3->Text));

		byte *dataBuffer = new byte[File.clusterSize];

		for(;!iterator.IsDone();iterator.Next()){
		 if(iterator.GetCurrent(dataBuffer))
			 {for(int i=0; i<File.clusterSize;i++)
			 {
				 Label2->Caption+=dataBuffer[i];
				 Label2->Caption+=" ";
			 }
		 }
		}
		delete[] dataBuffer;
	}
}
//---------------------------------------------------------------------------

