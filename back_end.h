#ifndef BACK_END_H
#define BACK_END_H

#include <QMainWindow>
//#include "QTimer"

extern bool closeUI;

namespace Ui {
class Back_End;
}

class Back_End : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Back_End *ui;
  //  QTimer *timer;
  //  MainWindow *W;

public:
    explicit Back_End(QWidget *parent = nullptr);
    ~Back_End();
    void closeWindow();

public slots:
    void check();

};

#endif // BACK_END_H
