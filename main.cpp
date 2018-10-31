#include "mainwindow.h"
#include "back_end.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    Back_End B;
    B.showFullScreen();
   // w.showFullScreen();
    return a.exec();
}
