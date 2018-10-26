#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "registreerwindow.h"
#include "searchplayerwindow.h"
#include <QTimer>


namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
public slots:
    void timerFunction();

private slots:
    void on_pushButtonStart_clicked();

private:
    Ui::StartWindow *ui;
    QTimer *timer;
    SearchPlayerWindow *searchW;

};

#endif // STARTWINDOW_H

