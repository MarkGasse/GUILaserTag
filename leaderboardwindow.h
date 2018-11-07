//==========================================================
// Nico van Bentum | nico.vanbentum@student.hu.nl
// Mark Gasse      | mark.gasse@student.hu.nl
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//==========================================================
/// @file

#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include "back_end.h"
#include "QListWidgetItem"
#include "../lasergameServerClass/tcpServer.hpp"

namespace Ui {
class leaderboardWindow;
}

/// \brief
/// leaderboard window class inherits from QMainWindow
/// \details
/// Implements a window that can start/stop a match and keep statistics during a match.
class leaderboardWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::leaderboardWindow *ui;
    QString Animations[3];
    int arrayPos = 0;
    QMovie *GIF = new QMovie("");
    bool gameStarted = 1;
    QListWidgetItem lb_item;
    Back_End *B;
    bool gameIsRunning = 0;
    QString game_time;

private slots:

    /// \brief
    /// Start button
    /// \details
    /// Starts timers and sets game state
    void on_pushButton_3_clicked();

    /// \brief
    /// Stop button
    /// \details
    /// Pauses timers and changes game state
    void on_pushButton_4_clicked();

    /// \brief
    /// Set time timer logic
    /// \details
    /// Subtracts 1 from the current time every timer1 timeout (1000ms)
    void timerupdater();

    /// \brief
    /// Leaderboard update
    /// \details
    /// Keeps track of all connected players statistics, sorts them then writes all
    /// to a GUI element.
    void updateLB();

    /// \brief
    /// Back to search players button
    /// \details
    /// On click returns you to the search players window.
    void on_pushButtonBack_clicked();

    /// \brief
    /// Back to game mode selection button
    /// \details
    /// On click returns you to the game mode selection window.
    void on_pushButtonBACK2_clicked();

    /// \brief
    /// Set new animation
    /// \details
    /// Loads & scales a new gif in the label.
    /// Play gif until timer has reached zero.
    void setAnimation(int arrayPos);

    /// \brief
    /// Close application button
    /// \details
    /// Calls QApplication:quit() to terminate the program.
    void on_CloseGUI_clicked();

    /// \brief
    /// Stops the animation
    /// \details
    /// When the timer has reached zero this function is called.
    /// This function deletes the gif & sets the background.
    void stopAnimation();

public:
    /// \brief
    /// Leaderboardwindow constructor
    /// \details
    /// default leaderboardwindow constructor, its' parent by default a nullptr
    explicit leaderboardWindow(QWidget *parent = nullptr);

    /// \brief
    /// Leaderboardwindow destructor
    ~leaderboardWindow();

    /// \brief
    /// Write to EventBox
    /// \details
    /// Function for writing message to EventBox with a color & type.
    void writeToEventBox(QString message, QString textColor, QString type);

    QTimer *timer1;
    QTimer *timer2;
};

#endif // LEADERBOARDWINDOW_H
