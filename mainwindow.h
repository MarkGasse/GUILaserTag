#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "startwindow.h"
#include "registreerwindow.h"
#include <QTimer>
#include "QDebug"
#include "QFile"
#include "QString"
#include "QTextStream"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString fileUsername = ":/resource/text/username.txt";
    QString filePassword = ":/resource/text/password.txt";
    void defaultLayout(int w, int h);
    void timerFunction();

public slots:
    void write(QString Filename, QString text);
    QString read(QString Filename, int i);


private slots:
    void on_LoginButton_clicked();

    void on_pushButtonRegistreer_clicked();

private:
    Ui::MainWindow *ui;
    StartWindow *startW;
    registreerWindow *registreerW;
    QTimer *timer;
};

#endif // MAINWINDOW_H
