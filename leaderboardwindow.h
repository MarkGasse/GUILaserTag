#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include "back_end.h"
#include "QListWidgetItem"
/// @file

/// \brief
///
/// \details
///
namespace Ui {
class leaderboardWindow;
}

/// \brief
///
/// \details
///
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

private slots:

    /// \brief
    ///
    /// \details
    ///
    void on_pushButton_3_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButton_4_clicked();

    /// \brief
    ///
    /// \details
    ///
    void timerupdater();

    /// \brief
    ///
    /// \details
    ///
    void updateLB();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonBack_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonBACK2_clicked();

    /// \brief
    ///
    /// \details
    ///
    void setAnimation(int arrayPos);

    /// \brief
    ///
    /// \details
    ///
    void on_CloseGUI_clicked();

    /// \brief
    ///
    /// \details
    ///
    void stopAnimation();

public:
    /// \brief
    ///
    /// \details
    ///
    explicit leaderboardWindow(QWidget *parent = nullptr);

    /// \brief
    ///
    /// \details
    ///
    ~leaderboardWindow();

    /// \brief
    ///
    /// \details
    ///
    void writeToEventBox(QString message, QString textColor, QString type);

    QTimer *timer1;
    QTimer *timer2;
};

#endif // LEADERBOARDWINDOW_H
