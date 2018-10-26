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

public:
    explicit registreerWindow(QWidget *parent = nullptr);
    ~registreerWindow();

private slots:
    void on_pushButtonRegistreer_clicked();

private:
    Ui::registreerWindow *ui;
};

#endif // REGISTREERWINDOW_H
