program Paint;

uses
  Vcl.Forms,
  mainwindow in 'mainwindow.pas' {MainForm},
  loadscreen in 'loadscreen.pas' {loadform};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  LoadForm := TLoadForm.Create(Application);
  LoadForm.Show;
  LoadForm.Update;
  while LoadForm.timer.Enabled do
    Application.ProcessMessages;
  Application.CreateForm(TMainForm, MainForm);
  LoadForm.Hide;
  LoadForm.Free;
  Application.Run;
end.
