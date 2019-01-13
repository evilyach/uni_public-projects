unit Project1;

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Variants,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.ToolWin,
  Vcl.ActnMan,
  Vcl.ActnCtrls,
  Vcl.ActnMenus,
  Vcl.ExtCtrls,
  Vcl.Menus,
  System.Actions,
  Vcl.ActnList,
  System.ImageList,
  Vcl.ImgList,
  Vcl.StdActns,
  StdStyleActnCtrls,
  Vcl.StdCtrls,
  Vcl.Samples.Spin,
  VCLTee.TeCanvas,
  Vcl.PlatformDefaultStyleActnCtrls,
  Vcl.ExtDlgs;

type

  // ������������ ������������
  ToolEnum = (pen = 1, line = 2, rect = 3, fill = 4);

  // ����� �������� �����
  TMainForm = class(TForm)

    // ������� ����
    main_menu: TMainMenu;
    // ���� "����"
    pen_menu: TMenuItem;
    open_file_menu: TMenuItem;
    save_file_menu: TMenuItem;
    separator2: TMenuItem;
    clear_menu: TMenuItem;
    exit_menu: TMenuItem;
    // ���� "�����"
    file_menu: TMenuItem;
    pen_color_menu: TMenuItem;
    pen_size_menu: TMenuItem;
    separator1: TMenuItem;
    solid_line_menu: TMenuItem;
    dash_line_menu: TMenuItem;
    dot_line_menu: TMenuItem;
    // ���� "����������"
    tool_menu: TMenuItem;
    pen_tool_menu: TMenuItem;
    line_tool_menu: TMenuItem;
    rect_tool_menu: TMenuItem;
    fill_tool_menu: TMenuItem;
    // ���� "�������"
    fill_menu: TMenuItem;
    solid_fill_menu: TMenuItem;
    none_fill_menu: TMenuItem;
    cross_fill_menu: TMenuItem;
    fdiag_fill_menu: TMenuItem;
    bdiag_fill_menu: TMenuItem;
    cross_diag_fill_menu: TMenuItem;
    hor_fill_menu: TMenuItem;
    ver_fill_menu: TMenuItem;

    // ������
    action_list: TActionList;
    clear_action: TAction;
    exit_action: TAction;
    pen_width_action: TAction;
    pen_color_action: TAction;
    solid_line_action: TAction;
    dash_line_action: TAction;
    dot_line_action: TAction;
    pen_tool_action: TAction;
    line_tool_action: TAction;
    rect_tool_action: TAction;
    fill_tool_action: TAction;
    solid_fill_action: TAction;
    none_fill_action: TAction;
    cross_fill_action: TAction;
    fdiag_fill_action: TAction;
    bdiag_fill_action: TAction;
    diag_cross_fill_action: TAction;
    hor_fill_action: TAction;
    ver_fill_action: TAction;

    // ������ ������ � ���������� ���������� � ������������
    image_list: TImageList;
    panel_bot: TPanel;
    tool_label: TLabel;
    tool_combo_box: TComboBox;
    width_label: TLabel;
    width_spin_edit: TSpinEdit;
    style_label: TLabel;
    style_combo_box: TComboBox;
    fill_label: TLabel;
    fill_combo_box: TComboBox;

    // ������� ������ � ��������
    panel_top: TPanel;
    save_button: TButton;
    open_button: TButton;
    clear_button: TButton;
    exit_button: TButton;
    pen_width_button: TButton;
    pen_color_button: TButton;
    pen_tool_button: TButton;
    line_tool_button: TButton;
    rect_tool_button: TButton;
    fill_tool_button: TButton;
    solid_pen_button: TButton;
    dash_pen_button: TButton;
    dot_pen_button: TButton;
    solid_fill_button: TButton;
    none_fill_button: TButton;
    cross_fill_button: TButton;
    fdiag_fill_button: TButton;
    bdiag_fill_button: TButton;
    diag_cross_fill_button: TButton;
    hor_fill_button: TButton;
    ver_fill_button: TButton;

    image: TImage;
    save_file_action: TAction;
    open_file_action: TAction;
    save_pic_dialog: TSavePictureDialog;
    open_pic_dialog: TOpenPictureDialog;
    color_dialog: TColorDialog;  // ������� ������ ��� �����������

    // ������ ��������� ����
    procedure formCreate(Sender: TObject);
    procedure imageMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure imageMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure imageMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure save_buttonClick(Sender: TObject);
    procedure save_file_actionExecute(Sender: TObject);
    procedure open_buttonClick(Sender: TObject);
    procedure open_file_actionExecute(Sender: TObject);
    procedure clear_buttonClick(Sender: TObject);
    procedure clear_actionExecute(Sender: TObject);
    procedure exit_actionExecute(Sender: TObject);
    procedure exit_buttonClick(Sender: TObject);
    procedure pen_width_actionExecute(Sender: TObject);
    procedure pen_width_buttonClick(Sender: TObject);
    procedure pen_color_buttonClick(Sender: TObject);
    procedure pen_color_actionExecute(Sender: TObject);
    procedure pen_tool_buttonClick(Sender: TObject);
    procedure pen_tool_actionExecute(Sender: TObject);
    procedure line_tool_buttonClick(Sender: TObject);
    procedure line_tool_actionExecute(Sender: TObject);
    procedure rect_tool_actionExecute(Sender: TObject);
    procedure rect_tool_buttonClick(Sender: TObject);
    procedure fill_tool_buttonClick(Sender: TObject);
    procedure fill_tool_actionExecute(Sender: TObject);
    procedure tool_combo_boxChange(Sender: TObject);

  private
    tool: ToolEnum;
    width: Integer;
    color: TColor;
    fill_style: TFillStyle;

  public
    { Public declarations }
  end;

var
  MainForm: TMainForm;

implementation
{$R *.dfm}

// ���������� ������� �������� �����
procedure TMainForm.formCreate(Sender: TObject);
begin
  // ������� ����� ����� ������
  image.canvas.pen.color   := clWhite;
  image.canvas.font.color  := clWhite;
  image.canvas.brush.style := bsClear;
  image.canvas.brush.color := clWindowText;

  // ��������� ����������� ��������
  self.tool  := pen;
  self.width := 1;
  //self.fill_style := bsSolid;
end;

// ���������� ������� ������� ��� ����
procedure TMainForm.imageMouseDown(Sender: TObject;
                                   Button: TMouseButton;
                                   Shift: TShiftState;
                                   x, y: Integer);
begin
  // �������� ����� �����
  if image.canvas.brush.style <> bsClear then
    image.canvas.brush.color := self.color;

  // ��������� ������������ ��� ������� ���
  if (tool = line) or (tool = rect) then
    image.canvas.PenPos := Image.screenToClient(Mouse.CursorPos);
  if (tool = fill) then
    image.canvas.FloodFill(x, y, self.color, self.fill_style);
end;

// ���������� ������� ������������ ����
procedure TMainForm.imageMouseMove(Sender: TObject;
                                   Shift: TShiftState;
                                   x, y: Integer);
begin
  // ��������� ��������� ���������� ���������
  if not (ssLeft in Shift) and (tool = pen) then
    image.canvas.penPos := image.screenToClient(mouse.cursorPos);

  // ������ �� ������� ��������� �� ������
  if (tool = pen) and (ssLeft in shift) then
    image.canvas.lineTo(x, y);
end;

// ���������� ������� ��������� ������� ��� ����
procedure TMainForm.imageMouseUp(Sender: TObject;
                                 Button: TMouseButton;
                                 Shift: TShiftState;
                                 x, y: Integer);
begin
  if (tool = line) then
    Image.Canvas.LineTo(x, y);

  if (tool = rect) then
   Image.Canvas.Rectangle(image.canvas.penPos.x,
                          image.canvas.penPos.y,
                          image.screenToClient(mouse.cursorPos).x,
                          image.screenToClient(mouse.cursorPos).y);
end;

// ���������� ������� "������� ����"
procedure TMainForm.open_file_actionExecute(Sender: TObject);
begin
  if open_pic_dialog.execute then
    if open_pic_dialog.filename <> '' then
      image.picture.loadFromFile(open_pic_dialog.filename);
end;

// ���������� ������ "������� ����"
procedure TMainForm.open_buttonClick(Sender: TObject);
begin
  open_file_actionExecute(self);
end;

// ���������� ������� "��������� ���"
procedure TMainForm.save_file_actionExecute(Sender: TObject);
begin
  if save_pic_dialog.execute() then
    image.picture.saveToFile(save_pic_dialog.filename);
end;

// ���������� ������ "��������� ���"
procedure TMainForm.save_buttonClick(Sender: TObject);
begin
  self.save_file_actionExecute(self);
end;

// ���������� ������� "��������"
procedure TMainForm.clear_actionExecute(Sender: TObject);
begin
  self.formCreate(self);
end;

// ���������� ������ "��������"
procedure TMainForm.clear_buttonClick(Sender: TObject);
begin
  self.clear_actionExecute(self);
end;

// ���������� ������� "�������"
procedure TMainForm.exit_actionExecute(Sender: TObject);
begin
  self.close();
end;

// ���������� ������ "�������"
procedure TMainForm.exit_buttonClick(Sender: TObject);
begin
  self.exit_actionExecute(self);
end;

// ���������� ������� "������ ����"
procedure TMainForm.pen_width_actionExecute(Sender: TObject);
var
  s_width: String;
  t_width: Integer;
  ok: Integer;
begin
  while True do
  begin
    s_width := inputBox('������ ����',
                        '������� ������ ����',
                        intToStr(self.width));

    t_width := strToInt(s_width);
    if (t_width > 0) and (t_width <= 120) then
    begin
      self.width := t_width;
      width_spin_edit.Value := t_width;
      break;
    end else begin
      ok := messageDlg('���������� ������� ����� ������ ����!',
                 mtError, mbOKCancel, 0);
                 
      if ok = mrOK then
        continue
      else if ok = mrCancel then
        break;
    end;
  end;
end;

// ���������� ������ "������ ����"
procedure TMainForm.pen_width_buttonClick(Sender: TObject);
begin
  self.pen_width_actionExecute(self);
end;

// ���������� ������� "���� ����"
procedure TMainForm.pen_color_actionExecute(Sender: TObject);
begin
  if self.color_dialog.execute() then
    self.color := self.color_dialog.color;
end;

// ���������� ������ "���� ����"
procedure TMainForm.pen_color_buttonClick(Sender: TObject);
begin
  self.pen_color_actionExecute(self);
end;

// ���������� ������� ������ ����������� "�����"
procedure TMainForm.pen_tool_actionExecute(Sender: TObject);
begin
  self.tool := pen;
  self.tool_combo_box.ItemIndex := 0;
end;

// ���������� ������ ������ ����������� "�����"
procedure TMainForm.pen_tool_buttonClick(Sender: TObject);
begin
  self.pen_tool_actionExecute(self);
end;

// ���������� ������� ������ ����������� "�����"
procedure TMainForm.line_tool_actionExecute(Sender: TObject);
begin
  self.tool := line;
  self.tool_combo_box.ItemIndex := 1;
end;

// ���������� ������ ������ ����������� "�����"
procedure TMainForm.line_tool_buttonClick(Sender: TObject);
begin
  self.line_tool_actionExecute(self);
end;

// ���������� ������� ������ ����������� "�������������"
procedure TMainForm.rect_tool_actionExecute(Sender: TObject);
begin
  self.tool := rect;
  self.tool_combo_box.ItemIndex := 2;
end;

// ���������� ������ ������ ����������� "�������������"
procedure TMainForm.rect_tool_buttonClick(Sender: TObject);
begin
  self.rect_tool_actionExecute(self);
end;

// ���������� ������� ������ ����������� "�������"
procedure TMainForm.fill_tool_actionExecute(Sender: TObject);
begin
  self.tool := fill;
  self.tool_combo_box.ItemIndex := 3;
end;

// ���������� ������ ������ ����������� "�������"
procedure TMainForm.fill_tool_buttonClick(Sender: TObject);
begin
  self.fill_tool_actionExecute(self);
end;

// ���������� ��������� �������� ���������� ������������
procedure TMainForm.tool_combo_boxChange(Sender: TObject);
begin
  case tool_combo_box.ItemIndex of
    0: self.tool := pen;
    1: self.tool := line;
    2: self.tool := rect;
    3: self.tool := fill;
  end;
end;

end.
