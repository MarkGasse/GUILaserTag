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
#include "QKeyEvent"

extern QString game_mode;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    StartWindow *startW;
    registreerWindow *registreerW;
    QTimer *timer;
    bool MBoxStatus;

private slots:
    void on_LoginButton_clicked();
    void on_pushButtonRegistreer_clicked();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString fileUsername = "username.txt";
    QString filePassword = "password.txt";
    void defaultLayout(int w, int h);

protected:
    void keyPressEvent(QKeyEvent *event);


public slots:
    void write(QString Filename, QString text, bool status);
    QString read(QString Filename);
    void timerFunction();

};

#endif // MAINWINDOW_H
