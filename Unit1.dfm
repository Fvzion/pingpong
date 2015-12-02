object Form1: TForm1
  Left = 194
  Top = 130
  Caption = 'Form1'
  ClientHeight = 636
  ClientWidth = 1057
  Color = clBackground
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnMouseMove = MovimientoMouse
  PixelsPerInch = 96
  TextHeight = 13
  object Borde1: TShape
    Left = 0
    Top = 56
    Width = 1041
    Height = 42
  end
  object Borde2: TShape
    Left = -256
    Top = 584
    Width = 1297
    Height = 33
  end
  object Pelota: TShape
    Left = 776
    Top = 136
    Width = 49
    Height = 49
    Shape = stCircle
  end
  object Cursor: TShape
    Left = 0
    Top = 288
    Width = 25
    Height = 113
    OnMouseEnter = TimingMovimiento
    OnMouseLeave = TimingMovimiento
    OnMouseMove = MovimientoMouse
  end
  object Pared: TShape
    Left = 1000
    Top = 96
    Width = 41
    Height = 489
  end
  object StaticText1: TStaticText
    Left = 376
    Top = 0
    Width = 230
    Height = 50
    Caption = 'PING PONG'
    Color = 65408
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 0
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = TimingMovimiento
    Left = 184
    Top = 16
  end
end
