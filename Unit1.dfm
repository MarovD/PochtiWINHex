object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 535
  ClientWidth = 759
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  ShowHint = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 431
    Top = 29
    Width = 50
    Height = 24
    Caption = #1048#1085#1092#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 107
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Edit1: TEdit
    Left = 19
    Top = 35
    Width = 265
    Height = 21
    Hint = #1044#1074#1086#1081#1085#1086#1077' '#1085#1072#1078#1072#1090#1080#1077' '#1076#1083#1103' '#1074#1099#1073#1086#1088#1072' '#1087#1091#1090#1080
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = 'C:\'
    TextHint = #1055#1091#1090#1100' '#1076#1083#1103' '#1089#1095#1080#1090#1099#1074#1072#1085#1080#1103
    OnDblClick = Edit1DblClick
  end
  object Edit2: TEdit
    Left = 19
    Top = 80
    Width = 121
    Height = 21
    Hint = 
      #1059#1082#1072#1079#1099#1074#1072#1077#1090#1089#1103' '#1074' '#1082#1083#1072#1089#1090#1077#1088#1072#1093'. '#1050#1083#1072#1089#1090#1077#1088' '#1089' '#1082#1086#1090#1086#1088#1086#1075#1086' '#1073#1091#1076#1077#1090' '#1085#1072#1095#1080#1085#1072#1090#1089#1103' '#1095#1090#1077#1085 +
      #1080#1077'.'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    TextHint = #1057#1084#1077#1097#1077#1085#1080#1077
  end
  object Edit3: TEdit
    Left = 163
    Top = 80
    Width = 121
    Height = 21
    Hint = 
      #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1095#1080#1090#1099#1074#1072#1077#1084#1099#1093' '#1082#1083#1072#1089#1090#1077#1088#1086#1074'. '#1045#1089#1083#1080' '#1087#1086#1083#1077' '#1087#1091#1089#1090#1086#1077', '#1089#1095#1080#1090#1099#1074#1072#1085#1080#1077' '#1073 +
      #1091#1076#1077#1090' '#1076#1086' '#1087#1086#1089#1083#1077#1076#1085#1077#1075#1086' '#1082#1083#1072#1089#1090#1077#1088#1072'.'
    TabOrder = 2
    TextHint = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1082#1083#1072#1089#1090#1077#1088#1086#1074' '
  end
  object Button1: TButton
    Left = 304
    Top = 78
    Width = 105
    Height = 25
    Caption = #1055#1086#1080#1089#1082' '#1089#1080#1075#1085#1072#1090#1091#1088
    TabOrder = 3
    OnClick = Button1Click
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 19
    Top = 128
    Width = 510
    Height = 383
    DefaultNodeHeight = 26
    Header.AutoSizeIndex = 0
    Header.MainColumn = -1
    TabOrder = 4
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <>
  end
  object RadioGroup1: TRadioGroup
    Left = 19
    Top = 8
    Width = 190
    Height = 21
    DoubleBuffered = False
    ParentDoubleBuffered = False
    TabOrder = 5
  end
  object RadioButton1: TRadioButton
    Left = 24
    Top = 12
    Width = 108
    Height = 17
    Caption = #1042#1099#1073#1086#1088' '#1092#1072#1081#1083#1072
    Checked = True
    TabOrder = 6
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 118
    Top = 12
    Width = 108
    Height = 17
    Caption = #1042#1099#1073#1086#1088' '#1087#1072#1087#1082#1080
    TabOrder = 7
  end
  object Button2: TButton
    Left = 304
    Top = 33
    Width = 105
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 8
    OnClick = Button2Click
  end
  object OpenDialog1: TOpenDialog
    Options = []
    Left = 728
    Top = 504
  end
end
