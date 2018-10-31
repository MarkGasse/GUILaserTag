#ifndef SEARCHPLAYERWINDOW_H
#define SEARCHPLAYERWINDOW_H

#include "leaderboardwindow.h"
#include <QMainWindow>
#include <QTimer>
#include <QString>

namespace Ui {
class SearchPlayerWindow;
}

class SearchPlayerWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::SearchPlayerWindow *ui;
    leaderboardWindow *lbw;
    QTimer *timer;
    QString status = "not searching";

private slots:
    void on_pushButtonSearch_clicked();
    void on_pushButtonStopS_clicked();
    void on_pushButtonStart_clicked();
    void on_pushButton_clicked();

public:
    explicit SearchPlayerWindow(QWidget *parent = nullptr);
    ~SearchPlayerWindow();

public slots:
    void timerFunction();

};

#endif // SEARCHPLAYERWINDOW_H
