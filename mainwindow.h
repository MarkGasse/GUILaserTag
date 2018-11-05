//==========================================================
// Nico van Bentum | nico.vanbentum@student.hu.nl
// Mark Gasse      | mark.gasse@student.hu.nl
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//==========================================================
/// @file

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

extern QString game_mode;

namespace Ui {
class MainWindow;
}

/// \brief
/// MainWindow class, inherits all from QMainWindow.
/// \details
/// Implements a window that acts as a login/register screen
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
    /// Log in button
    /// \details
    /// Deletes the current window and starts the game for the next window.
    void on_LoginButton_clicked();

    /// \brief
    /// Register button
    /// \details
    /// On click returns you to the login window & registers new user.
    void on_pushButtonRegistreer_clicked();

    /// \brief
    /// Close Application button
    /// \details
    /// Calls QApplication:quit() to terminate the program.
    void on_CloseGUI_clicked();

public:
    /// \brief
    /// MainWindow constructor
    /// \details
    /// Takes a QWidget as parent, by default as nullptr
    explicit MainWindow(QWidget *parent = nullptr);

    /// \brief
    /// default destructor
    ~MainWindow();

    QString fileUsername = "username.txt";
    QString filePassword = "password.txt";

    /// \brief
    /// Default layout function
    /// \details
    /// Defaults the GUI elements to our standard layout
    void defaultLayout(int w, int h);

protected:

    /// \brief
    /// Key pressed check
    /// \details
    /// Checks for key press events
    void keyPressEvent(QKeyEvent *event);

public slots:

    /// \brief
    /// Write to file
    /// \details
    /// Takes a filename, text to write and a bool to append or not.
    void write(QString Filename, QString text, bool status);

    /// \brief
    /// Read from file
    /// \details
    /// Takes a filename to read from and returns a QString containing all text from that file.
    QString read(QString Filename);

    /// \brief
    /// Current time display
    /// \details
    /// Gets and shows the current time in the top right of the GUI.
    void timerFunction();

};

#endif // MAINWINDOW_H
