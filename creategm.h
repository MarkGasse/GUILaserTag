#ifndef CREATEGM_H
#define CREATEGM_H

#include <QDialog>

namespace Ui {
class CreateGM;
}

class CreateGM : public QDialog
{
    Q_OBJECT

private:
    Ui::CreateGM *ui;

private slots:
    void on_pushButtonCancel_clicked();
    void on_pushButtonCreate_clicked();

public:
    explicit CreateGM(QWidget *parent = nullptr);
    ~CreateGM();

};

#endif // CREATEGM_H
