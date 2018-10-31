#ifndef SEARCHPLAYERWINDOW_H
#define SEARCHPLAYERWINDOW_H

#include "leaderboardwindow.h"
#include <QMainWindow>
#include "back_end.h"
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
    Back_End *B;

private slots:
    void on_pushButtonSearch_clicked();
    void on_pushButtonStopS_clicked();
    void on_pushButtonStart_clicked();
    void on_pushButton_clicked();
    void on_CloseGUI_clicked();

public:
    explicit SearchPlayerWindow(QWidget *parent = nullptr);
    ~SearchPlayerWindow();

public slots:
    void timerFunction();

};

#endif // SEARCHPLAYERWINDOW_H
