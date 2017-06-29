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
	TOpenPictureDialog *OpenPictureDialog1;
	TImage *Image1;
	TAction *View;
	TAction *FullScreen;
	TMenuItem *View1;
	TMenuItem *FullScreen1;
	TSavePictureDialog *SavePictureDialog1;
	TAction *Copy;
	TAction *Cut;
	TAction *New;
	TAction *Crop;
	TToolButton *btnFullScreen;
	TToolButton *btnCopy;
	TToolButton *btnCut;
	TToolButton *btnCrop;
	TToolButton *btnRotateLeft;
	TAction *RotateLeft;
	TAction *RotateRight;
	TToolButton *ToolButton1;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall ExitExecute(TObject *Sender);
	void __fastcall LoadExecute(TObject *Sender);
	void __fastcall SaveExecute(TObject *Sender);
	void __fastcall FileExecute(TObject *Sender);
	void __fastcall ViewExecute(TObject *Sender);
	void __fastcall FullScreenExecute(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall CopyExecute(TObject *Sender);
	void __fastcall CutExecute(TObject *Sender);
	void __fastcall CropExecute(TObject *Sender);
	void __fastcall RotateRightExecute(TObject *Sender);
	void __fastcall RotateLeftExecute(TObject *Sender);


private:	// User declarations
	TJPEGImage *JPEGImage1;
	TBitmap *Bitmap1;
    TBitmap *Bitmap2;
	TRect lastRect;
	TPoint mousePos;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
void __fastcall DrawCustom(TImage *image, TGraphic *bitmap);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
