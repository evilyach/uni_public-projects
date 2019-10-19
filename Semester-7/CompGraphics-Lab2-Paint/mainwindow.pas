unit mainwindow;

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
  Vcl.ExtCtrls,
  Vcl.Buttons,
  Vcl.Menus,
  Vcl.StdCtrls,
  Vcl.CheckLst,
  Vcl.ExtDlgs,
  Jpeg,
  ShellApi,
  Vcl.Samples.Spin;

const
  // Стандартные значения ширины и высоты холста
  image_width = 640;
  image_height = 360;

type
  // Класс основной формы
  TMainForm = class(TForm)
    pic: TPaintBox;
    scrollBox: TScrollBox;
    toolPanel: TPanel;
    penButton: TSpeedButton;
    lineButton: TSpeedButton;
    rectButton: TSpeedButton;
    colorBox: TPaintBox;
    colorDialog: TColorDialog;
    fillButton: TSpeedButton;
    menu: TMainMenu;
    fileMenu: TMenuItem;
    fillBox: TComboBox;
    openButton: TSpeedButton;
    saveDialog: TSavePictureDialog;
    openDialog: TOpenPictureDialog;
    saveButton: TSpeedButton;
    openMenu: TMenuItem;
    saveMenu: TMenuItem;
    N3: TMenuItem;
    exitMenu: TMenuItem;
    sizeEdit: TSpinEdit;
    N1: TMenuItem;
    aboutMenu: TMenuItem;
    roundedRectButton: TSpeedButton;
    ellipseButton: TSpeedButton;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure picPaint(Sender: TObject);
    procedure picMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure picMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure picMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure DrawLine(x0, y0, x, y: integer; mode: TPenMode);
    procedure DrawRect(x0, y0, x, y: integer; mode: TPenMode);
    procedure DrawEllipse(x0, y0, x, y: integer; mode: TPenMode);
    procedure DrawRoundedRect(x0, y0, x, y: integer; mode: TPenMode);
    procedure colorBoxPaint(Sender: TObject);
    procedure colorBoxMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure fillBoxDrawItem(Control: TWinControl; Index: Integer;
      Rect: TRect; State: TOwnerDrawState);
    procedure openButtonClick(Sender: TObject);
    procedure saveButtonClick(Sender: TObject);
    procedure exitMenuClick(Sender: TObject);
    procedure openMenuClick(Sender: TObject);
    procedure saveMenuClick(Sender: TObject);
    procedure sizeEditChange(Sender: TObject);
    procedure aboutMenuClick(Sender: TObject);

  private
    bmp: TBitmap;
    isDragging: boolean;
    brush: TBrushStyle;
    fillIndex: integer;
  end;

var
  MainForm: TMainForm;
  x0, y0: integer;

implementation
{$R *.dfm}

procedure TMainForm.FormCreate(Sender: TObject);
begin
  // Создание рисунка в памяти
  bmp := TBitmap.Create;
  bmp.Width := image_width;
  bmp.Height := image_height;

  // Установка свойств pic
  with pic do begin
    Width := bmp.Width;
    Height := bmp.Height;
    Left := 0;
    Top := 0;
  end;

  // Установка стандартных значений
  brush := bsSolid;
end;

procedure TMainForm.FormDestroy(Sender: TObject);
begin
  bmp.Free;
end;

procedure TMainForm.aboutMenuClick(Sender: TObject);
var
  path: string;
begin
  path := ExtractFilePath(Application.ExeName) + 'about.rtf';
  ShellExecute(Application.Handle, PChar('open'), PChar(path), PChar(0), nil, SW_NORMAL);
end;

procedure TMainForm.exitMenuClick(Sender: TObject);
begin
  close;
end;

procedure TMainForm.openButtonClick(Sender: TObject);
begin
  if openDialog.execute then begin
    bmp.loadFromFile(openDialog.FileName);
  end;
end;

procedure TMainForm.openMenuClick(Sender: TObject);
begin
  self.openButtonClick(self);
end;

procedure TMainForm.saveButtonClick(Sender: TObject);
begin
  if saveDialog.Execute then begin
    bmp.SaveToFile(saveDialog.FileName);
  end;
end;

procedure TMainForm.saveMenuClick(Sender: TObject);
begin
  self.saveButtonClick(self);
end;

procedure TMainForm.sizeEditChange(Sender: TObject);
begin
  bmp.Canvas.Pen.Width := sizeEdit.Value;
end;

procedure TMainForm.picPaint(Sender: TObject);
begin
  pic.Canvas.Draw(0, 0, bmp);
end;

procedure TMainForm.DrawLine(x0, y0, x, y: integer; mode: TPenMode);
var
  point: TPoint;
begin
  with bmp.Canvas do begin
    // Определяем текущую позицию
    point := PenPos;

    // Стираем временный рисунок
    pen.Mode := pmNot;
    moveTo(x0, y0);
    lineTo(point.x, point.y);

    // Рисуем новый
    pen.Mode := Mode;
    moveTo(x0, y0);
    lineTo(x, y);
  end;
end;

procedure TMainForm.DrawRect(x0: Integer; y0: Integer; x: Integer; y: Integer;
  mode: TPenMode);
var
  point: TPoint;
  rct: TRect;
begin
  with bmp.Canvas do begin
    // Определяем текущую позицию и начальный прямоугольник
    point := PenPos;
    if (point.x > x0) and (point.y > y0) then
      rct := Rect(x0, y0, point.x, point.y)
    else if (point.x > x0) and (point.y < y0) then
      rct := Rect(x0, point.y, point.x, y0)
    else if (point.x < x0) and (point.y > y0) then
      rct := Rect(point.x, y0, x0, point.y)
    else if (point.x < x0) and (point.y < y0) then
      rct := Rect(point.x, point.y, x0, y0);

    // Стираем временный рисунок
    DrawFocusRect(rct);
    if (x > x0) and (y > y0) then
      rct := Rect(x0, y0, x, y)
    else if (x > x0) and (y < y0) then
      rct := Rect(x0, y, x, y0)
    else if (x < x0) and (y > y0) then
      rct := Rect(x, y0, x0, y)
    else if (x < x0) and (y < y0) then
      rct := Rect(x, y, x0, y0);

    if Mode = pmCopy then begin     // Рисуем новый
      brush.Style := bsClear;
      Rectangle(rct);
      brush.Style := bsSolid;
    end else begin                  // Или снова временный
      DrawFocusRect(rct);
    end;

    // Новая текущая позиция рисования
    moveTo(x, y);
  end;
end;

procedure TMainForm.DrawEllipse(x0: Integer; y0: Integer; x: Integer; y: Integer;
  mode: TPenMode);
var
  point: TPoint;
  rct: TRect;
begin
  with bmp.Canvas do begin
    // Определяем текущую позицию и начальный эллипс
    point := PenPos;
    if (point.x > x0) and (point.y > y0) then
      rct := Rect(x0, y0, point.x, point.y)
    else if (point.x > x0) and (point.y < y0) then
      rct := Rect(x0, point.y, point.x, y0)
    else if (point.x < x0) and (point.y > y0) then
      rct := Rect(point.x, y0, x0, point.y)
    else if (point.x < x0) and (point.y < y0) then
      rct := Rect(point.x, point.y, x0, y0);

    // Стираем временный рисунок
    DrawFocusRect(rct);
    if (x > x0) and (y > y0) then
      rct := Rect(x0, y0, x, y)
    else if (x > x0) and (y < y0) then
      rct := Rect(x0, y, x, y0)
    else if (x < x0) and (y > y0) then
      rct := Rect(x, y0, x0, y)
    else if (x < x0) and (y < y0) then
      rct := Rect(x, y, x0, y0);

    if Mode = pmCopy then begin     // Рисуем новый
      brush.Style := bsClear;
      Ellipse(rct);
      brush.Style := bsSolid;
    end else begin                  // Или снова временный
      DrawFocusRect(rct);
    end;

    // Новая текущая позиция рисования
    moveTo(x, y);
  end;
end;

procedure TMainForm.DrawRoundedRect(x0: Integer; y0: Integer; x: Integer; y: Integer;
  mode: TPenMode);
var
  point: TPoint;
  rct: TRect;
begin
  with bmp.Canvas do begin
    // Определяем текущую позицию и начальный скругленный прямоугольник
    point := PenPos;
    if (point.x > x0) and (point.y > y0) then
      rct := Rect(x0, y0, point.x, point.y)
    else if (point.x > x0) and (point.y < y0) then
      rct := Rect(x0, point.y, point.x, y0)
    else if (point.x < x0) and (point.y > y0) then
      rct := Rect(point.x, y0, x0, point.y)
    else if (point.x < x0) and (point.y < y0) then
      rct := Rect(point.x, point.y, x0, y0);

    // Стираем временный рисунок
    DrawFocusRect(rct);
    if (x > x0) and (y > y0) then
      rct := Rect(x0, y0, x, y)
    else if (x > x0) and (y < y0) then
      rct := Rect(x0, y, x, y0)
    else if (x < x0) and (y > y0) then
      rct := Rect(x, y0, x0, y)
    else if (x < x0) and (y < y0) then
      rct := Rect(x, y, x0, y0);

    if Mode = pmCopy then begin     // Рисуем новый
      brush.Style := bsClear;
      RoundRect(rct, 10, 10);
      brush.Style := bsSolid;
    end else begin                  // Или снова временный
      DrawFocusRect(rct);
    end;

    // Новая текущая позиция рисования
    moveTo(x, y);
  end;
end;

procedure TMainForm.picMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; x, y: Integer);
begin
  isDragging := True;
  bmp.Canvas.MoveTo(x, y);
  x0 := x;
  y0 := y;
end;

procedure TMainForm.picMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; x, y: Integer);
begin
  if not isDragging then
    exit;

  // Если инструмент - отрезок
  if lineButton.Down then
    DrawLine(x0, y0, x, y, pmCopy);

  // Если инструмент - прямогольник
  if rectButton.Down then
    DrawRect(x0, y0, x, y, pmCopy);

  // Если инструмент - скругленный прямоугольник
  if roundedRectButton.Down then
    DrawRoundedRect(x0, y0, x, y, pmCopy);

  // Если инструмент - эллипс
  if ellipseButton.Down then
    DrawEllipse(x0, y0, x, y, pmCopy);

  // Если инструмент - заливка
  if fillButton.Down then
  begin
    case fillBox.ItemIndex of
      0: bmp.Canvas.Brush.Style := bsSolid;
      1: bmp.Canvas.Brush.Style := bsClear;
      2: bmp.Canvas.Brush.Style := bsHorizontal;
      3: bmp.Canvas.Brush.Style := bsVertical;
      4: bmp.Canvas.Brush.Style := bsFDiagonal;
      5: bmp.Canvas.Brush.Style := bsBDiagonal;
      6: bmp.Canvas.Brush.Style := bsCross;
      7: bmp.Canvas.Brush.Style := bsDiagCross;
    end;

    if button = mbLeft then
      bmp.Canvas.FloodFill(x, y, bmp.Canvas.Pixels[x, y], fsSurface);
  end;

  isDragging := False;
  picPaint(self);
end;

procedure TMainForm.picMouseMove(Sender: TObject; Shift: TShiftState;
  x, y: Integer);
begin
  // Если не рисуем
  if not isDragging then
    exit;

  // Если инструмент - карандаш
  if penButton.Down then
    bmp.Canvas.LineTo(x, y);

  // Если инструмент - отрезок
  if lineButton.Down then
    DrawLine(x0, y0, x, y, pmNot);

  // Если инструмент - прямогольник
  if rectButton.Down then
    DrawRect(x0, y0, x, y, pmNot);

  // Если инструмент - скругленный прямоугольник
  if roundedRectButton.Down then
    DrawRoundedRect(x0, y0, x, y, pmNot);

  // Если инструмент - эллипс
  if ellipseButton.Down then
    DrawEllipse(x0, y0, x, y, pmNot);

  picPaint(self);
end;

procedure TMainForm.colorBoxPaint(Sender: TObject);
begin
  with colorBox.Canvas do begin
    brush.Color := bmp.Canvas.Brush.Color;
    Rectangle(15, 15, 35, 35);
    brush.Color := bmp.Canvas.Pen.Color;
    Rectangle(5, 5, 25, 25);
  end;
end;

procedure TMainForm.colorBoxMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if colorDialog.Execute then begin
    if button = mbLeft then
      bmp.Canvas.Pen.Color := colorDialog.Color
    else
      bmp.Canvas.Brush.Color := colorDialog.Color;

    colorBoxPaint(self);
  end;
end;

procedure TMainForm.fillBoxDrawItem(Control: TWinControl; Index: Integer;
  Rect: TRect; State: TOwnerDrawState);
begin
  with fillBox.Canvas do begin
    brush.Color := bmp.Canvas.Pen.Color;
    brush.Style := TBrushStyle(index);
    pen.Style := psClear;
    Rectangle(Rect.Left, Rect.Top, Rect.Right, Rect.Bottom);
  end;
end;

end.
