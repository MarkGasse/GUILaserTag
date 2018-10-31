#ifndef REGISTREERWINDOW_H
#define REGISTREERWINDOW_H

#include <QDialog>
#include "QString"

namespace Ui {
class registreerWindow;
}

class registreerWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::registreerWindow *ui;

private slots:
    void on_pushButtonRegistreer_clicked();

public:
    explicit registreerWindow(QWidget *parent = nullptr);
    ~registreerWindow();

};

#endif // REGISTREERWINDOW_H
