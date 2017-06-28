object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'Form2'
  ClientHeight = 328
  ClientWidth = 570
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 570
    Height = 328
    Align = alClient
    Center = True
    Proportional = True
    OnDblClick = ExitFullScreenExecute
    ExplicitLeft = 200
    ExplicitTop = 80
    ExplicitWidth = 105
    ExplicitHeight = 105
  end
  object ActionList1: TActionList
    Left = 424
    Top = 160
    object ExitFullScreen: TAction
      Caption = 'ExitFullScreen'
      OnExecute = ExitFullScreenExecute
    end
  end
end
