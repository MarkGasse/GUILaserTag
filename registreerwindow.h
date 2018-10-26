#ifndef REGISTREERWINDOW_H
#define REGISTREERWINDOW_H

#include <QMainWindow>
#include "QString"

namespace Ui {
class registreerWindow;
}

class registreerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit registreerWindow(QWidget *parent = nullptr);
    ~registreerWindow();

private slots:
    void on_pushButtonRegistreer_clicked();

private:
    Ui::registreerWindow *ui;
};

#endif // REGISTREERWINDOW_H
