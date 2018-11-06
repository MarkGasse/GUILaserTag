#include "mainwindow.h"
#include "back_end.h"
#include <QApplication>
#include <QRect>
#include <QScreen>
#include <QPoint>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Back_End B;
    B.showFullScreen();
    return a.exec();
}
