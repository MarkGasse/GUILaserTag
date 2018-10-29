#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDateTime>
#include "QRect"
#include "QScreen"
#include "QDebug"
#include "QFile"
#include "QString"
#include "QTextStream"

QString game_mode = " ";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    // get screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rec = screen->geometry();
    int w = rec.width() ;
    int h = rec.height();

    defaultLayout(w,h);

    ui->groupBoxLogin->setGeometry(w/2-132,h/2-100,275,175);

    ui->LoginButton->setStyleSheet("background-color: lightGreen");
    ui->pushButtonRegistreer->setStyleSheet("background-color: lightBlue");
    ui->lineEdit_Password->setStyleSheet("background-color: white");
    ui->lineEdit_Username->setStyleSheet("background-color: white");
    ui->labelTopBar->setStyleSheet("background-color: lightblue");
    ui->Label_date->setStyleSheet("background-color: lightblue");
    ui->groupBoxLogin->setStyleSheet("QGroupBox { border: 2px solid black;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::defaultLayout(int w, int h)
{
    // set position on gui
    //(X,Y,width,height)
    ui->CloseGUI->setGeometry(w-50,0,50,50);
    ui->labelTopBar->setGeometry(0,0,w-50,50);
    ui->Label_date->setGeometry(w-400,0,350,50);
    ui->Titel->setGeometry(w/2-175,h/2-350,350,100);
    ui->Group->setGeometry(w/2-175,h/2-250,360,100);
    ui->labelLogo->setGeometry(w/2-275,h/2-350,100,100);

    //set background color window
    this->setStyleSheet("background-color: white;");

    // set colors
    ui->CloseGUI->setStyleSheet("background-color: red");
    ui->labelTopBar->setStyleSheet("background-color: lightblue");
    ui->Label_date->setStyleSheet("background-color: lightblue");
    ui->Group->setStyleSheet("color: red");

    //adding logo to labelLogo
    QPixmap LogoPix(":/resource/image/LogoLaser.jpg");
    int LogoWidth =  ui->labelLogo->width();
    int LogoHeight=  ui->labelLogo->height();
    ui->labelLogo->setPixmap(LogoPix.scaled(LogoWidth,LogoHeight,Qt::KeepAspectRatio));

    //timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timerFunction()));
    timer->start(1000);
}

void MainWindow::timerFunction()
{
    // show date
    QDateTime current_date = QDateTime::currentDateTime();
    QString date_text = current_date.toString("hh:mm:ss || dd-MMM-yyyy");
    ui->Label_date->setText(date_text);
}

void MainWindow::write(QString Filename, QString text, bool status)
{
    // open myfile and check if file is open
    QFile myfile(Filename);

    if(status)
    {
        myfile.open(QFile::WriteOnly | QFile::Text | QFile::Append);
        if(!myfile.isOpen()) qDebug() << "file not open";

        // write to myfile
        QTextStream out(&myfile);
        out << text << "\n";

        myfile.flush();

    } else {
        myfile.open(QFile::WriteOnly | QFile::Truncate | QFile::Text);
        if(!myfile.isOpen()) qDebug() << "file not open";
    }

    // close myfile
    myfile.close();
}

QString MainWindow::read(QString Filename)
{
    // open myfile and check if file is open
    QFile myfile(Filename);
    if(!myfile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "could not read file: " << Filename << ".\n";
    }

    // read myfile
    QTextStream in(&myfile);

       QString Line = in.readLine();



    // close myfile
    myfile.close();
    return Line;
}

void MainWindow::on_LoginButton_clicked()
{
    // check login
    QString username = ui->lineEdit_Username ->text();
    QString password = ui->lineEdit_Password ->text();

    QString pass[10];
    QString user[10];
    int m= 0;
    QFile myfile(filePassword);
    QFile myfile2(fileUsername);

    myfile.open(QIODevice::ReadOnly);
    myfile2.open(QIODevice::ReadOnly);
    QTextStream in(&myfile);
    QTextStream in2(&myfile2);
    while(!in.atEnd() && !in2.atEnd()){
        pass[m] = in.readLine();
        user[m] = in2.readLine();
        //qDebug() << user[m] << pass[m] << endl;
        m++;
    }
        myfile.close();
        myfile2.close();

    for(int j = 0; j < 10; j++ ){
        if(username == user[j]  && password == pass[j] && username != "" && password != ""){
            hide();
            startW = new StartWindow(this);
            startW->showFullScreen();
        }else{
            ui->statusBarLogin->setStyleSheet("color: red");
            ui->statusBarLogin->showMessage("username or password is not correct!",4000);
            ui->lineEdit_Password->setText("");
            ui->lineEdit_Username->setText("");
        }
    }
}

void MainWindow::on_pushButtonRegistreer_clicked()
{
    registreerW = new registreerWindow(this);
    registreerW->show();
}
