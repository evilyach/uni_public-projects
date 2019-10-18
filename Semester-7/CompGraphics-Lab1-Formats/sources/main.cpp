#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const char *splashcreen_filename = "splash.png";
    QPixmap pixmap(splashcreen_filename);

    QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
    splash.show();

    MainWindow w;

    int duration = 1000; // Продолжительность заставки
    QTimer::singleShot(duration, &splash, SLOT(close()));
    QTimer::singleShot(duration, &w, SLOT(show()));

//    w.showMaximized();
    return a.exec();
}
