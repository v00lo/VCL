//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == char(27))
		this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ExitFullScreenExecute(TObject *Sender)
{
     this->Close();
}
//---------------------------------------------------------------------------
