//==========================================================
// Nico van Bentum | nico.vanbentum@student.hu.nl
// Mark Gasse      | mark.gasse@student.hu.nl
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//==========================================================

#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "searchplayerwindow.h"
#include "back_end.h"
#include "creategm.h"
#include "QKeyEvent"
#include <QTimer>
/// @file

namespace Ui {
class StartWindow;
}

extern int amountOfPlayers;

/// \brief
/// StartWindow class
/// \details
/// Implements a window for choosing the gamemode.
class StartWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::StartWindow *ui;
    QTimer *timer;
    SearchPlayerWindow *searchW;
    CreateGM *CreateW;
    Back_End *B;

private slots:
    /// \brief
    /// call to search player window
    /// \details
    /// Open searchPlayer window if gamemode is selected.
    /// Else information pop-up
    void on_pushButtonStart_clicked();

    /// \brief
    /// Delete gamemode
    /// \details
    /// Current selected gamemode will be deleted when pressed.
    void on_pushButtonDelete_clicked();

    /// \brief
    /// call to create gamemode window
    /// \details
    /// open creategm window
    void on_pushButtonCreate_clicked();

    /// \brief
    /// close UI
    /// \details
    /// Calls QApplication:quit() to terminate the program.
    void on_CloseGUI_clicked();

protected:
    /// \brief
    /// login button
    /// \details
    /// If enter key is pressed call to on_pushButtonStart_clicked().
    void keyPressEvent(QKeyEvent *event);

public:
    /// \brief
    /// default constructor
    /// \details
    ///  The constructor sets the UI layout.
    ///  Calls timerFunction every time the timer reached zero.
    ///  reads gamemodes and add to list widget.
    explicit StartWindow(QWidget *parent = nullptr);

    /// \brief
    /// deconstructer startWindow
    /// \details
    /// deletes startwindow
    ~StartWindow();

public slots:

    /// \brief
    /// Show Time
    /// \details
    /// Updates the date on UI when function is called
    void timerFunction();

};

#endif // STARTWINDOW_H

