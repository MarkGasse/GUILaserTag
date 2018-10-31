#ifndef BACK_END_H
#define BACK_END_H

#include <QMainWindow>

namespace Ui {
class Back_End;
}

class Back_End : public QMainWindow
{
    Q_OBJECT

public:
    explicit Back_End(QWidget *parent = nullptr);
    ~Back_End();

private:
    Ui::Back_End *ui;
};

#endif // BACK_END_H
