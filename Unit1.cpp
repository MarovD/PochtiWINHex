//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Unit1.h"
#include "FileCtrl.hpp"
#include <NTFS.cpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
FileSystem File;
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
		UnicodeString str1="\\\\.\\";
		UnicodeString str2=Edit1->Text;

		if(str2[str2.Length()]=='\\')
		str2[str2.Length()]='\0';
		str2 = StringReplace(str2,"\\","\\\\",TReplaceFlags()<<rfReplaceAll);
		UnicodeString str3=str1+str2;

		wchar_t *fileName=str3.t_str();
		File=NTFS(fileName);

		File.ViewInfo(Label1);
	}
}
//---------------------------------------------------------------------------

