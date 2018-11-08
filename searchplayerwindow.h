//==========================================================
// Nico van Bentum | nico.vanbentum@student.hu.nl
// Mark Gasse      | mark.gasse@student.hu.nl
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//==========================================================
/// @file

#ifndef SEARCHPLAYERWINDOW_H
#define SEARCHPLAYERWINDOW_H

#include "leaderboardwindow.h"
#include <QMainWindow>
#include "back_end.h"
#include <QTimer>
#include <QString>
#include "../lasergameServerClass/tcpServer.hpp"

extern client clients[6];
extern tcpServer S;

namespace Ui {
class SearchPlayerWindow;
}

/// \brief
/// SearchPlayerWindow class
/// \details
/// Implements a window to search for/connect game clients over wi-fi.
class SearchPlayerWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::SearchPlayerWindow *ui;
    leaderboardWindow *lbw;
    QTimer *timer_update;
    QTimer *timer_timefunc;
    QString status = "not searching";
    Back_End *B;
    bool foundPlayers = 0;


private slots:
    /// \brief
    /// Search button
    /// \details
    /// Starts the search for arduino clients.
    void on_pushButtonSearch_clicked();

    /// \brief
    /// Stop button
    /// \details
    /// Stops the search for arduino clients.
    void on_pushButtonStopS_clicked();

    /// \brief
    /// Start button
    /// \details
    /// Deletes the current window and starts the game for the next window.
    void on_pushButtonStart_clicked();

    /// \brief
    /// Back to game mode selection button
    /// \details
    /// Deletes the current window and returns the GUI to the game mode selection window.
    void on_pushButton_clicked();

    /// \brief
    /// Close application button
    /// \details
    /// Terminates the entire application by calling QtApplication::quit() .
    void on_CloseGUI_clicked();

    void on_pushButtonPlayers_clicked();

public:
    /// \brief
    /// searchPlayerWindow constructor.
    /// \details
    /// default Qt window constructor, takes a QWidget as parent which defaults to a nullptr.
    explicit SearchPlayerWindow(QWidget *parent = nullptr);

    /// \brief
    /// Default destructor.
    ~SearchPlayerWindow();

public slots:
    /// \brief
    /// TCP connection
    /// \details
    /// Sets up a TCP socket server to communicate with clients.
    void doNetworkStuff();

    /// \brief
    /// Current time display
    /// \details
    /// Gets and shows the current time in the top right of the GUI.
    void timerFunction();

};

#endif // SEARCHPLAYERWINDOW_H
