#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "startwindow.h"
#include "registreerwindow.h"
#include "back_end.h"
#include <QTimer>
#include "QDebug"
#include "QFile"
#include "QString"
#include "QTextStream"
#include "QKeyEvent"
#include "QCloseEvent"
/// @file

extern QString game_mode;

/// \brief
///
/// \details
///
namespace Ui {
class MainWindow;
}

/// \brief
///
/// \details
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    StartWindow *startW;
    Back_End *B;
    registreerWindow *registreerW;
    QTimer *timer;
    bool MBoxStatus;

private slots:
    /// \brief
    ///
    /// \details
    ///
    void on_LoginButton_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonRegistreer_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_CloseGUI_clicked();

public:
    /// \brief
    ///
    /// \details
    ///
    explicit MainWindow(QWidget *parent = nullptr);

    /// \brief
    ///
    /// \details
    ///
    ~MainWindow();

    QString fileUsername = "username.txt";
    QString filePassword = "password.txt";

    /// \brief
    ///
    /// \details
    ///
    void defaultLayout(int w, int h);

protected:

    /// \brief
    ///
    /// \details
    ///
    void keyPressEvent(QKeyEvent *event);

public slots:

    /// \brief
    ///
    /// \details
    ///
    void write(QString Filename, QString text, bool status);

    /// \brief
    ///
    /// \details
    ///
    QString read(QString Filename);

    /// \brief
    ///
    /// \details
    ///
    void timerFunction();

};

#endif // MAINWINDOW_H
