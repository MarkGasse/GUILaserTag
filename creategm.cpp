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
    ui->comboBoxDPS->setStyleSheet("background-color: white");
    ui->comboBox_2->setStyleSheet("background-color: white");

    //set gamemodes
    ui->comboBoxMode->addItem("FreeForAll");

    //set times
    for(int t = 5; t <= 50; t+= 5){
        ui->comboBoxTime->addItem(QString::number(t));
    }

    //set Health points
    ui->comboBoxHP->addItem(QString::number(1));
    for(int h = 100; h <= 500; h+= 50){
        ui->comboBoxHP->addItem(QString::number(h));
    }

    //set damage points
    for(int dmg = 10; dmg <= 100; dmg+=10 )
    {
        ui->comboBoxDPS->addItem(QString::number(dmg));
    }

    //set nr of players
    for(int p = 1; p <= 10; p++)
    {
        ui->comboBox_2->addItem(QString::number(p));
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
    QString nrofplayers = ui->comboBox_2->currentText();
    QString deeps   = ui->comboBoxDPS->currentText();

    QString array[6] = {fileName,mode,time,HP, deeps, nrofplayers};

    if(fileName != "")
    {
        MainWindow W;
        for(int i = 0; i < 6; i++)
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
