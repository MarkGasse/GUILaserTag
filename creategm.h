#ifndef CREATEGM_H
#define CREATEGM_H

#include <QDialog>

namespace Ui {
class CreateGM;
}

class CreateGM : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGM(QWidget *parent = nullptr);
    ~CreateGM();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonCreate_clicked();

private:
    Ui::CreateGM *ui;
};

#endif // CREATEGM_H
