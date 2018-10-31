#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QDateTime>
#include "QRect"
#include "QScreen"
#include "QTemporaryFile"
#include <cstdio>
#include "mainwindow.h"
#include <QMessageBox>
#include "QPalette"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);



    // get screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rec = screen->geometry();
    int w = rec.width() ;
    int h = rec.height();

    // set position on gui
    //(X,Y,width,height)
    ui->CloseGUI->setGeometry(w-50,0,50,50);
    ui->labelTopBar->setGeometry(0,0,w-50,50);
    ui->Label_date->setGeometry(w-400,0,350,50);
    ui->Titel->setGeometry(w/2-175,h/2-350,350,100);
    ui->Group->setGeometry(w/2-175,h/2-250,360,100);
    ui->labelLogo->setGeometry(w/2-275,h/2-350,100,100);
    ui->pushButtonStart->setGeometry(w/2-25,h/2+200,50,50);
    ui->groupBoxGame->setGeometry(w/2-140,h/2-110,280,280);

    //set background color window
    this->setStyleSheet("background-color: white;");

    // set colors
    ui->CloseGUI->setStyleSheet("background-color: red");
    ui->labelTopBar->setStyleSheet("background-color: lightblue");
    ui->Label_date->setStyleSheet("background-color: lightblue");
    ui->pushButtonCreate->setStyleSheet("background-color: lightblue");
    ui->pushButtonDelete->setStyleSheet("background-color: red");
    ui->Group->setStyleSheet("color: red");
    ui->pushButtonStart->setStyleSheet("background-color: lightGreen");
    ui->groupBoxGame->setStyleSheet("QGroupBox { border: 2px solid black;}");

    //adding logo to labelLogo
    QPixmap LogoPix(":/resource/image/LogoLaser.jpg");
    int LogoWidth =  ui->labelLogo->width();
    int LogoHeight=  ui->labelLogo->height();
    ui->labelLogo->setPixmap(LogoPix.scaled(LogoWidth,LogoHeight,Qt::KeepAspectRatio));

    //timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timerFunction()));
    timer->start(1000);

    // read gamemodes and add to list widget
    MainWindow W;
    QFile file("GAMEMODES");

    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QListWidgetItem *item = new QListWidgetItem(QIcon(":/resource/image/images.png"),in.readLine());
        ui->listWidgetGame->addItem(item);
    }
        file.close();

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::timerFunction()
{
    // show date
    QDateTime current_date = QDateTime::currentDateTime();
    QString date_text = current_date.toString("hh:mm:ss || dd-MMM-yyyy");
    ui->Label_date->setText(date_text);
}


// open searchplayerwindow
void StartWindow::on_pushButtonStart_clicked()
{
    if(ui->listWidgetGame->selectedItems().size() != 0){
        QString selectedItem = ui->listWidgetGame->currentItem()->text();

        game_mode = selectedItem;

        close();
        searchW = new SearchPlayerWindow(this);
        searchW->showFullScreen();
    }else{
       QMessageBox::information(this,tr("Not selected!"),tr("Select gamemode before starting game."),QMessageBox::Ok);
    }

}

// delete selected item from listwidget
void StartWindow::on_pushButtonDelete_clicked()
{

    QString selectedItem = ui->listWidgetGame->currentItem()->text();
    delete ui->listWidgetGame->currentItem();

    // write all gamemodes except the item you want ot delete to TmpGameModeList
    MainWindow W;

    QFile file("GAMEMODES");

    file.open(QIODevice::ReadOnly); //open gamemodes
    QTextStream in(&file);


    while(!in.atEnd()){
        QString item = in.readLine();

        if(item != selectedItem){
           W.write("TmpGameModeList",item,1); //open and close tmpgamemodelist
        } else {
            std::string file_to_remove = item.toStdString();
            //const char *f = file_to_remove.c_str();
            //if(std::remove(f)) qDebug() << "deleted";
        }
    }
        file.close(); //close gamemodes, tmp and gamemodes now both closed

         W.write("GAMEMODES","",0); //open and close gamemodes
        QFile file2("TmpGameModeList");

        file2.open(QIODevice::ReadOnly); //open tmpgamemodelist
        QTextStream in2(&file2);
        while(!in2.atEnd()){
            QString item = in2.readLine();

               W.write("GAMEMODES",item,1); //open and close gamemodes
        }
            file2.close(); //close tmpgamemodelist, both are now closed

            W.write("TmpGameModeList", "", 0); //open and close tmpga
}

//Open create new gamemode window
void StartWindow::on_pushButtonCreate_clicked()
{
    CreateW = new CreateGM(this);
    CreateW->show();

}

void StartWindow::on_CloseGUI_clicked()
{
 close();
}
