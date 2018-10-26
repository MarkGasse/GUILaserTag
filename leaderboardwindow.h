#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void timerupdater();

private:
    Ui::leaderboardWindow *ui;
};

#endif // LEADERBOARDWINDOW_H
