//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
		JPEGImage1 = new TJPEGImage;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	delete(JPEGImage1);
    this->Close();
}
void __fastcall TForm1::CloseExecute(TObject *Sender)
{
	this->FormDestroy(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
    this->FormDestroy(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ToolButton1Click(TObject *Sender)
{
		this->OpenPictureDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Help1Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FileExecute(TObject *Sender)
{
	this->File->OnExecute;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitExecute(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadExecute(TObject *Sender)
{
	this->OpenPictureDialog1->Execute();
		if(FileExists(OpenPictureDialog1->FileName))
			Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		else
			throw(Exception("File does not exist"));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveExecute(TObject *Sender)
{
	if(SavePictureDialog1->Execute())
	{
		if(FileExists(SavePictureDialog1->FileName))
			throw(Exception("File Already exists. Cannot overwrite"));
		else

	}
}
//---------------------------------------------------------------------------
