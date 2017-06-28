//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
		JPEGImage1 = new TJPEGImage;
		BitmapImage1 = new TBitmap;
	   //	lastRect = new TRect;
	  //  mousePos = new TPoint;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	delete(JPEGImage1);
    this->Close();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
    this->FormDestroy(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitExecute(TObject *Sender)
{
	this->Close();
}

void __fastcall TForm1::LoadExecute(TObject *Sender)
{

	this->OpenPictureDialog1->Execute();
 /*
	if(FileExists(OpenPictureDialog1->FileName))
		Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
	else
		throw(Exception("File does not exist"));
 */
	JPEGImage1->LoadFromFile(OpenPictureDialog1->FileName);
	BitmapImage1->Assign(JPEGImage1);
	Image1->Canvas->Draw(0, 0, JPEGImage1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveExecute(TObject *Sender)
{
	if(SavePictureDialog1->Execute())
	{
		if(FileExists(SavePictureDialog1->FileName))
			throw(Exception("File Already exists. Cannot overwrite"));
		else
			Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FileExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ViewExecute(TObject *Sender)
{
			  //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FullScreenExecute(TObject *Sender)
{
	TForm2 *fform;
	fform = new TForm2(this);
	fform->Image1->Picture->Assign(JPEGImage1);
	fform->ShowModal();
	delete(fform);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
	TPoint MousePosImg = Image1->ScreenToClient(mousePos);
	StatusBar1->Panels->Items[0]->Text = "x: " + IntToStr(MousePosImg.x);
	StatusBar1->Panels->Items[1]->Text = "y: " + IntToStr(MousePosImg.y);
	StatusBar1->Panels->Items[2]->Text = "delta: " + IntToStr(WheelDelta);
}
//---------------------------------------------------------------------------
