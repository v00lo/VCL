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

		TRect lastRect;
		TPoint  mousePos;
		Bitmap2 = new TBitmap;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	delete(JPEGImage1);
	delete(Bitmap1);
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
	this->FormDestroy(Form1);
}

void __fastcall TForm1::LoadExecute(TObject *Sender)
{
	delete(JPEGImage1);
	delete(Bitmap1);
	JPEGImage1 = new TJPEGImage;
	Bitmap1 = new TBitmap;

	this->OpenPictureDialog1->Execute();

	JPEGImage1->LoadFromFile(OpenPictureDialog1->FileName);
	Bitmap1->Assign(JPEGImage1);
	Image1->Height = JPEGImage1->Height;
	Image1->Width = JPEGImage1->Width;
	Image1->Left = 0;
	Image1->Top = 35;
	Image1->Canvas->Draw(0, 0, JPEGImage1);

   //	delete(JPEGImage1);
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
	fform->Image1->Picture->Assign(Bitmap1);
	fform->ShowModal();
	delete(fform);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
	TPoint MousePosImg = Image1->ScreenToClient(mousePos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	mousePos.x = X;
    mousePos.y = Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if(Shift.Contains(ssLeft))
	{
		Image1->Canvas->DrawFocusRect(lastRect);
		lastRect.Left = mousePos.x;
		lastRect.Right = X;
		lastRect.Top = mousePos.y;
		lastRect.Bottom = Y;
		Image1->Canvas->DrawFocusRect(lastRect);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CopyExecute(TObject *Sender)
{
	TRect  sourceRect;

	sourceRect.Left= lastRect.Left;
	sourceRect.Top= lastRect.Top;
	sourceRect.Right= Image1->ClientRect.Right + mousePos.x;
	sourceRect.Bottom= Image1->ClientRect.Bottom + mousePos.y;

	Bitmap1->Assign(JPEGImage1);
	Image1->Canvas->CopyRect(Image1->ClientRect, Bitmap1->Canvas,
sourceRect);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CutExecute(TObject *Sender)
{
	Bitmap1->Canvas->CopyMode = cmWhiteness;
	Bitmap1->Canvas->CopyRect(lastRect, Bitmap1->Canvas, lastRect);
	DrawCustom(Image1, Bitmap1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawCustom(TImage *image, TGraphic *bitmap)
{
	JPEGImage1->Assign(bitmap);
	image->Picture->Assign(bitmap);
}
void __fastcall TForm1::CropExecute(TObject *Sender)
{
	TRect srcRect, dstRect;

	srcRect = Rect(30, 30, 60, 60);
	dstRect = Rect(lastRect.Top, lastRect.Left, lastRect.GetHeight(), lastRect.GetWidth());

	Bitmap1->Height = lastRect.GetHeight();
	Bitmap1->Width = lastRect.GetWidth();
	Bitmap1->Canvas->CopyMode = cmSrcCopy;
	Bitmap1->Canvas->CopyRect(srcRect, Image1->Canvas, dstRect);
	DrawCustom(Image1, Bitmap1);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RotateRightExecute(TObject *Sender)
{
	int i,j;
	Bitmap1->Assign(JPEGImage1);
	Bitmap2->Width=Bitmap1->Height;
	Bitmap2->Height=Bitmap1->Width;

	for (int i=0; i < Bitmap1->Width; i++)
		for(int j=0; j < Bitmap1->Height; j++)
			Bitmap2->Canvas->Pixels[Bitmap2->Width - j][i]= Bitmap1->Canvas->Pixels[i][j];

	JPEGImage1->Assign(Bitmap2);
	Image1->Canvas->Draw(0,0,JPEGImage1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RotateLeftExecute(TObject *Sender)
{
	int i,j;
	Bitmap1->Assign(JPEGImage1);
	Bitmap2->Width=Bitmap1->Height;
	Bitmap2->Height=Bitmap1->Width;

	for (int i=0; i < Bitmap1->Width; i++)
		for(int j=0; j < Bitmap1->Height; j++)
			Bitmap2->Canvas->Pixels[Bitmap2->Width - j][i]= Bitmap1->Canvas->Pixels[i][j];

	JPEGImage1->Assign(Bitmap2);
	Image1->Picture->Assign(JPEGImage1);
}
//---------------------------------------------------------------------------

