#include "registreerwindow.h"
#include "ui_registreerwindow.h"
#include "mainwindow.h"

registreerWindow::registreerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registreerWindow)
{
    ui->setupUi(this);

    //set background color window
    this->setStyleSheet("background-color: lightBlue;");

    // set color
    ui->lineEditUser->setStyleSheet("background-color: white");
    ui->lineEditPass->setStyleSheet("background-color: white");
    ui->lineEditPass2->setStyleSheet("background-color: white");
    ui->lineEditCode->setStyleSheet("background-color: white");
    ui->pushButtonRegistreer->setStyleSheet("background-color: lightGreen");
    ui->pushButtonCancel->setStyleSheet("background-color: Red");
}

registreerWindow::~registreerWindow()
{
    delete ui;
}

void registreerWindow::on_pushButtonRegistreer_clicked()
{
    //check registratie
    QString username = ui->lineEditUser ->text();
    QString password = ui->lineEditPass ->text();
    QString password2 = ui->lineEditPass2 ->text();
    QString code = ui->lineEditCode ->text();

    if(password == password2 && code == "doyoueven" && username != "" && password != ""){
      MainWindow wi;
      wi.write(wi.filePassword, password,1);
      wi.write(wi.fileUsername, username,1);
      hide();
    }

}
