unit loadscreen;

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
  Vcl.ComCtrls,
  Vcl.Imaging.jpeg,
  Vcl.ExtCtrls;

type
  TLoadForm = class(TForm)
    image: TImage;
    progressBar: TProgressBar;
    timer: TTimer;
    procedure FormShow(Sender: TObject);
    procedure timerTimer(Sender: TObject);
  end;

var
  loadform: Tloadform;

implementation
{$R *.dfm}
procedure TLoadForm.FormShow(Sender: TObject);
begin
  self.progressBar.Position := self.progressBar.Position + 5;
  sleep(1000);
  self.progressBar.Position := self.progressBar.Position + 35;
  sleep(500);
  self.progressBar.Position := self.progressBar.Position + 15;
  sleep(2500);
  self.progressBar.Position := self.progressBar.Position + 25;
  sleep(1000);
  self.progressBar.Position := self.progressBar.Position + 20;
end;

procedure TLoadForm.timerTimer(Sender: TObject);
begin
  timer.Enabled := false;
end;

end.
