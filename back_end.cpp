#include "back_end.h"
#include "ui_back_end.h"
#include "QRect"
#include "QScreen"
#include "mainwindow.h"
#include "startwindow.h"
#include "QDebug"

bool closeUI = 0;
static QTimer *timer1 = new QTimer();

Back_End::Back_End(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Back_End)
{
    ui->setupUi(this);

    MainWindow *W;
    W = new MainWindow(this);
    W->showFullScreen();

    // get screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rec = screen->geometry();
    int w = rec.width() ;
    //int h = rec.height();

    ui->label->setGeometry(0,0,w,50);
    ui->label->setStyleSheet("background-color: lightblue");
    this->setStyleSheet("background-color: white");


    connect(timer1, SIGNAL(timeout()),this,SLOT(check()));
    timer1->start(1000);


}

Back_End::~Back_End()
{
    delete ui;
}

void Back_End::closeWindow()
{
    close();
}

void Back_End::check()
{

}
