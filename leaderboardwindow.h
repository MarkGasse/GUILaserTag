#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include "back_end.h"
#include "QListWidgetItem"

namespace Ui {
class leaderboardWindow;
}

class leaderboardWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::leaderboardWindow *ui;
    QString Animations[2];
    int arrayPos = 0;
    QMovie *GIF = new QMovie("");
    bool gameStarted = 1;
    QListWidgetItem lb_item;
    Back_End *B;
    bool gameIsRunning = 0;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void timerupdater();
    void updateLB();
    void on_pushButtonBack_clicked();
    void on_pushButtonBACK2_clicked();
    void setAnimation(int arrayPos);
    void on_CloseGUI_clicked();
    void stopAnimation();

public:
    explicit leaderboardWindow(QWidget *parent = nullptr);
    ~leaderboardWindow();
    void writeToEventBox(QString message, QString textColor, QString type);

    QTimer *timer1;
    QTimer *timer2;
};

#endif // LEADERBOARDWINDOW_H
