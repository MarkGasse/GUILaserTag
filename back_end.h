#ifndef BACK_END_H
#define BACK_END_H

#include <QMainWindow>

extern bool closeUI;

namespace Ui {
class Back_End;
}

class Back_End : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Back_End *ui;

public:
    explicit Back_End(QWidget *parent = nullptr);
    ~Back_End();

};

#endif // BACK_END_H
