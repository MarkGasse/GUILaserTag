#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QMainWindow>
#include <QMovie>

namespace Ui {
class leaderboardWindow;
}

class leaderboardWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit leaderboardWindow(QWidget *parent = nullptr);
    ~leaderboardWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void timerupdater();

    void on_pushButtonBack_clicked();

    void on_pushButtonBACK2_clicked();

    void setAnimation(int arrayPos);

private:
    Ui::leaderboardWindow *ui;
    QString Animations[1];
    int arrayPos = 0;
    QMovie *GIF = new QMovie("");
};

#endif // LEADERBOARDWINDOW_H
