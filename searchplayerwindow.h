#ifndef SEARCHPLAYERWINDOW_H
#define SEARCHPLAYERWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QString>

namespace Ui {
class SearchPlayerWindow;
}

class SearchPlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchPlayerWindow(QWidget *parent = nullptr);
    ~SearchPlayerWindow();
public slots:
    void timerFunction();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonStopS_clicked();

    void on_pushButtonStart_clicked();

private:
    Ui::SearchPlayerWindow *ui;
    QTimer *timer;
    QString status;
};

#endif // SEARCHPLAYERWINDOW_H
