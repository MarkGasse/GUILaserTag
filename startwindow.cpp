#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QDateTime>
#include "QRect"
#include "QScreen"

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


    //add item to list widget
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/resource/image/images.png"), "FreeforALL");
    ui->listWidgetGame->addItem(item);

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



void StartWindow::on_pushButtonStart_clicked()
{
    close();
    searchW = new SearchPlayerWindow(this);
    searchW->showFullScreen();
}
