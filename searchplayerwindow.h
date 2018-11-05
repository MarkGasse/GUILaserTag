#ifndef SEARCHPLAYERWINDOW_H
#define SEARCHPLAYERWINDOW_H

#include "leaderboardwindow.h"
#include <QMainWindow>
#include "back_end.h"
#include <QTimer>
#include <QString>
//#include "../lasergameServerClass/tcpServer.hpp"

/// @file

/// \brief
///
/// \details
///
namespace Ui {
class SearchPlayerWindow;
}

/// \brief
///
/// \details
///
class SearchPlayerWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::SearchPlayerWindow *ui;
    leaderboardWindow *lbw;
    QTimer *timer;
    QString status = "not searching";
    Back_End *B;

private slots:
    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonSearch_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonStopS_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonStart_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButton_clicked();

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
    explicit SearchPlayerWindow(QWidget *parent = nullptr);

    /// \brief
    ///
    /// \details
    ///
    ~SearchPlayerWindow();

    /// \brief
    ///
    /// \details
    ///
    void doNetworkStuff();

    //clients c = clients(2);
    //tcpServer S = tcpServer(8080, c);

public slots:
    /// \brief
    ///
    /// \details
    ///
    void timerFunction();

};

#endif // SEARCHPLAYERWINDOW_H
