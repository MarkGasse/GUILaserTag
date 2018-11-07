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
    ui->comboBoxHP->setStyleSheet("background-color: white");
    ui->lineEditPlayers->setStyleSheet("background-color: white");
    ui->lineEditPlayers->setGeometry(121, 5, 117, 24);

    //set gamemodes
    ui->comboBoxMode->addItem("FreeForAll");

    //set times
    for(int t = 5; t <= 50; t+= 5){
        ui->comboBoxTime->addItem(QString::number(t));
    }

    //set Health points
    ui->comboBoxHP->addItem(QString::number(1));
    for(int h = 50; h <= 500; h+= 50){
        ui->comboBoxHP->addItem(QString::number(h));
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
    QString HP       = ui->comboBoxHP->currentText();
    QString fileName = ui->lineEditName->text();
    QString nrofplayers = ui->lineEditPlayers->text();

    QString array[5] = {fileName,mode,time,HP, nrofplayers};

    if(fileName != "")
    {
        MainWindow W;
        for(int i = 0; i < 5; i++)
        {
             W.write(fileName,array[i],1);
        }

        W.write("GAMEMODES",fileName,1);

        close();

        StartWindow *startW;
        startW = new StartWindow();
        delete this;
        startW->showFullScreen();
    }

}
