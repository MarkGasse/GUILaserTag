#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "searchplayerwindow.h"
#include "creategm.h"
#include <QTimer>


namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::StartWindow *ui;
    QTimer *timer;
    SearchPlayerWindow *searchW;
    CreateGM *CreateW;

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonCreate_clicked();

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

public slots:
    void timerFunction();

};

#endif // STARTWINDOW_H

