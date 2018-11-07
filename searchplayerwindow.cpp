#include "searchplayerwindow.h"
#include "ui_searchplayerwindow.h"
#include <QPixmap>
#include <QDateTime>
#include "QRect"
#include "QDebug"
#include "QScreen"
#include "startwindow.h"
#include "QMessageBox"
//#include "../lasergameServerClass/tcpServer.hpp"

extern int amountOfPlayers;

client clients[6];
tcpServer S = tcpServer("8080", clients, amountOfPlayers);

SearchPlayerWindow::SearchPlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchPlayerWindow)
{
    ui->setupUi(this);

    S.maxClients = amountOfPlayers;
    qDebug() << S.maxClients;


    // get screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rec = screen->geometry();
    int w = rec.width() ;
    int h = rec.height();

    // set position on gui
    //(X,Y,width,height)
    ui->pushButton->setGeometry(0,0,150,50);
    ui->CloseGUI->setGeometry(w-50,0,50,50);
    ui->labelTopBar->setGeometry(0,0,w-400,50);
    ui->Label_date->setGeometry(w-400,0,350,50);
    ui->Titel->setGeometry(w/2-175,h/2-350,350,100);
    ui->Group->setGeometry(w/2-175,h/2-250,360,100);
    ui->labelLogo->setGeometry(w/2-275,h/2-350,100,100);
    ui->groupBoxSearch->setGeometry(w/2-160,h/2-110,320,300);

    //set background color window
    this->setStyleSheet("background-color: white;");

    // set colors
    ui->CloseGUI->setStyleSheet("background-color: red");
    ui->labelTopBar->setStyleSheet("background-color: lightblue");
    ui->Label_date->setStyleSheet("background-color: lightblue");
    ui->groupBoxSearch->setStyleSheet("QGroupBox { border: 2px solid black;}");
    ui->textBrowserS->setStyleSheet(" { border: 1px solid black;}");
    ui->Group->setStyleSheet("color: red");
    ui->pushButtonStart->setStyleSheet("background-color: lightGreen");
    ui->pushButtonSearch->setStyleSheet("background-color: lightBlue");
    ui->pushButtonStopS->setStyleSheet("background-color: Red");
    ui->pushButton->setStyleSheet("background-color: lightGray");

    //adding logo to labelLogo
    QPixmap LogoPix(":/resource/image/LogoLaser.jpg");
    int LogoWidth =  ui->labelLogo->width();
    int LogoHeight=  ui->labelLogo->height();
    ui->labelLogo->setPixmap(LogoPix.scaled(LogoWidth,LogoHeight,Qt::KeepAspectRatio));


    //timer
    timer_update = new QTimer();
    connect(timer_update, SIGNAL(timeout()),this,SLOT(timerFunction()));
    connect(timer_update, SIGNAL(timeout()),this,SLOT(doNetworkStuff()));
}

SearchPlayerWindow::~SearchPlayerWindow()
{
    delete ui;
}

void SearchPlayerWindow::timerFunction()
{
    // show date
    QDateTime current_date = QDateTime::currentDateTime();
    QString date_text = current_date.toString("hh:mm:ss || dd-MMM-yyyy");
    ui->Label_date->setText(date_text);
}

void SearchPlayerWindow::doNetworkStuff()
{
    S.listenNewClients();

    bool allConnected = true;
    for(int i = 0; i < S.maxClients; i++)
    {
        qDebug() << S.clients[i].con;
        if(S.clients[i].con == false)
        {
            allConnected = false;
            return;
        }
    }

    if(S.start)
    {
        ui->textBrowserS->append("All players already connected.");
        timer_update->stop();
        foundPlayers = true;
        return;
    }

    if(!S.start && allConnected)
    {
        ui->textBrowserS->append("All players connected.");
        S.startGame();
        S.start = true;
        status = "not searching";
        foundPlayers = true;
        timer_update->stop();
    }
}

void SearchPlayerWindow::on_pushButtonSearch_clicked()
{
    if(status != "searching")
    {
       ui->textBrowserS->setTextColor("Green");
       ui->textBrowserS->append("searching for players.....");
       timer_update->start(1000);
       status = "searching";
    }

}

void SearchPlayerWindow::on_pushButtonStopS_clicked()
{
    if(status != "not searching")
    {
       timer_update->stop();
       ui->textBrowserS->setTextColor("Red");
       ui->textBrowserS->append("..... stopped searching for players.");
       status = "not searching";
    }

}

void SearchPlayerWindow::on_pushButtonStart_clicked()
{
    if(status == "not searching" || foundPlayers)
    {
        close();
        lbw = new leaderboardWindow();
        lbw->showFullScreen();
        delete this;
    }
    else
    {
        QMessageBox::warning(this,tr("Error"),tr("Can't start game without players."),QMessageBox::Ok);
    }

}

void SearchPlayerWindow::on_pushButton_clicked()
{
    close();
    StartWindow *SW;
    SW = new StartWindow();
    delete this;
    SW->showFullScreen();
}

void SearchPlayerWindow::on_CloseGUI_clicked()
{
    QApplication::quit();
}
