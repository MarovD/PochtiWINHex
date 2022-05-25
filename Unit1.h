//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include "VirtualTrees.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.Outline.hpp>
#include <Vcl.Samples.DirOutln.hpp>
#include <Vcl.ExtCtrls.hpp>



//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TLabel *Label1;
	TVirtualStringTree *VirtualStringTree1;
	TOpenDialog *OpenDialog1;
	TRadioGroup *RadioGroup1;
	TButton *OpenFSButton;
	TRadioGroup *RadioGroup2;
	TButton *Button3;
	TButton *Button4;
	void __fastcall Edit1DblClick(TObject *Sender);
	void __fastcall OpenFSButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall RadioGroup2Click(TObject *Sender);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);

private:
    void ReloadViewDB();
	void WorkToDB(AnsiString str);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct{

	unsigned long clusterNum;
	UnicodeString   name;

} TreeNodeStruct;
//---------------------------------------------------------------------------
#endif
