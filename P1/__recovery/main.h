//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Dialogs.hpp>
#include <jpeg.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImageList *ImageList1;
	TActionList *ActionList1;
	TMainMenu *MainMenu1;
	TToolBar *ToolBar1;
	TStatusBar *StatusBar1;
	TAction *File;
	TAction *Load;
	TAction *Save;
	TMenuItem *File1;
	TMenuItem *Load1;
	TMenuItem *Save1;
	TAction *Exit;
	TMenuItem *Exit1;
	TAction *Help;
	TToolButton *ToolButton1;
	TOpenPictureDialog *OpenPictureDialog1;
	TImage *Image1;
	TAction *View;
	TAction *FullScreen;
	TMenuItem *View1;
	TMenuItem *FullScreen1;
	TSavePictureDialog *SavePictureDialog1;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall CloseExecute(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall Help1Click(TObject *Sender);
	void __fastcall FileExecute(TObject *Sender);
	void __fastcall ExitExecute(TObject *Sender);
	void __fastcall LoadExecute(TObject *Sender);
	void __fastcall SaveExecute(TObject *Sender);
private:	// User declarations
	TJPEGImage *JPEGImage1;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
