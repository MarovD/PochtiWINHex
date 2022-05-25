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
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 431
    Top = 8
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
  object Edit1: TEdit
    Left = 19
    Top = 49
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
    Top = 144
    Width = 510
    Height = 367
    DefaultNodeHeight = 26
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 4
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1053#1086#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072
        Width = 203
      end
      item
        Position = 1
        Text = #1058#1080#1087' '#1092#1072#1081#1083#1072
        Width = 112
      end>
  end
  object RadioGroup1: TRadioGroup
    Left = 19
    Top = 8
    Width = 265
    Height = 35
    BiDiMode = bdLeftToRight
    Columns = 2
    DoubleBuffered = False
    ItemIndex = 0
    Items.Strings = (
      #1042#1099#1073#1086#1088' '#1087#1072#1087#1082#1080
      #1042#1099#1073#1086#1088' '#1092#1072#1081#1083#1072)
    ParentBiDiMode = False
    ParentDoubleBuffered = False
    TabOrder = 5
  end
  object OpenFSButton: TButton
    Left = 304
    Top = 47
    Width = 105
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 6
    OnClick = OpenFSButtonClick
  end
  object RadioGroup2: TRadioGroup
    Left = 19
    Top = 104
    Width = 390
    Height = 34
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      #1057#1095#1080#1090#1099#1074#1072#1085#1080#1077' '#1074#1089#1077#1093' '#1082#1083#1072#1089#1090#1077#1088#1086#1074
      #1055#1088#1086#1087#1091#1089#1082' '#1087#1091#1089#1090#1099#1093' '#1082#1083#1072#1089#1090#1077#1088#1086#1074)
    TabOrder = 7
    OnClick = RadioGroup2Click
  end
  object Button3: TButton
    Left = 544
    Top = 447
    Width = 129
    Height = 25
    Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1089#1090#1088#1086#1082#1080
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 544
    Top = 478
    Width = 130
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1082#1072' '#1090#1072#1073#1083#1080#1094#1099' '#1080' '#1041#1044
    TabOrder = 9
    OnClick = Button4Click
  end
  object OpenDialog1: TOpenDialog
    Options = []
    Left = 728
    Top = 504
  end
end
