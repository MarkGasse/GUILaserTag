#include "creategm.h"
#include "ui_creategm.h"
#include "mainwindow.h"
#include "QString"
#include "startwindow.h"

CreateGM::CreateGM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGM)
{
    ui->setupUi(this);

    //set background color window
    this->setStyleSheet("background-color: lightBlue;");
    ui->pushButtonCreate->setStyleSheet("background-color: lightGreen");
    ui->pushButtonCancel->setStyleSheet("background-color: red");
    ui->lineEditName->setStyleSheet("background-color: white");
    ui->comboBoxMode->setStyleSheet("background-color: white");
    ui->comboBoxTime->setStyleSheet("background-color: white");

    //set gamemodes
    ui->comboBoxMode->addItem("FreeForAll");

    //set times
    for(int t = 5; t <= 60; t+= 5){
        ui->comboBoxTime->addItem(QString::number(t) + " minuten");
    }

}

CreateGM::~CreateGM()
{
    delete ui;
}

void CreateGM::on_pushButtonCancel_clicked()
{
    close();
}

void CreateGM::on_pushButtonCreate_clicked()
{
    QString mode     = ui->comboBoxMode->currentText();
    QString time     = ui->comboBoxTime->currentText();
    QString fileName = ui->lineEditName->text();
    QString array[3] = {fileName,mode,time};
    MainWindow W;
    for(int i = 0; i < 3; i++){
         W.write(fileName,array[i],1);
    }

    W.write("GAMEMODES",fileName,1);





    close();
    StartWindow *startW;
    startW = new StartWindow(this);
    startW->showFullScreen();
}
