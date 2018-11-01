#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "searchplayerwindow.h"
#include "back_end.h"
#include "creategm.h"
#include "QKeyEvent"
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
    Back_End *B;

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonCreate_clicked();
    void on_CloseGUI_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

public slots:
    void timerFunction();

};

#endif // STARTWINDOW_H

