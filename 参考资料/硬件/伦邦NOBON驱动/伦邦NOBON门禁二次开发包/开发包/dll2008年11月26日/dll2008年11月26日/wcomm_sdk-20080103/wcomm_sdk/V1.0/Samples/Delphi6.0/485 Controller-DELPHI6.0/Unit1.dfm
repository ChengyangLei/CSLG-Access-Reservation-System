object Form1: TForm1
  Left = 380
  Top = 130
  Width = 612
  Height = 627
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 35
    Width = 18
    Height = 13
    Caption = 'SN:'
  end
  object Label2: TLabel
    Left = 16
    Top = 68
    Width = 51
    Height = 13
    Caption = 'Serial Port:'
  end
  object Button1: TButton
    Left = 32
    Top = 120
    Width = 73
    Height = 33
    Caption = 'Test'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Text1: TMemo
    Left = 120
    Top = 16
    Width = 457
    Height = 569
    Lines.Strings = (
      '')
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object Button2: TButton
    Left = 32
    Top = 168
    Width = 73
    Height = 33
    Caption = 'Exit'
    TabOrder = 2
    OnClick = Button2Click
  end
  object EditSN: TEdit
    Left = 48
    Top = 32
    Width = 65
    Height = 21
    TabOrder = 3
    Text = '26604'
  end
  object EditSerialPort: TEdit
    Left = 48
    Top = 84
    Width = 65
    Height = 21
    TabOrder = 4
    Text = 'COM1'
  end
  object wserial: TCWComm_Serial
    AutoConnect = False
    ConnectKind = ckRunningOrNew
    Left = 32
    Top = 224
  end
end
