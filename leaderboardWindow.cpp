#include "leaderboardWindow.h"
#include "ui_leaderboardWindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTime>
#include <QTimeEdit>
#include <QTimer>
#include <QBasicTimer>
#include <QtDebug>
#include <QScreen>

static QTimer *timer1 = new QTimer();

leaderboardWindow::leaderboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::leaderboardWindow)
{
    ui->setupUi(this);

    // get screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rec = screen->geometry();
    int w = rec.width() ;
    int h = rec.height();

    ui->pushButton_3->setStyleSheet("background-color: lightGreen");
    ui->pushButton_4->setStyleSheet("background-color: red");
    ui->textBrowser_2->setStyleSheet(" { border: 1px solid black;}");
    ui->centralWidget->setGeometry(500,500,500,500);

    connect (timer1, SIGNAL(timeout()),this,SLOT(timerupdater()));

}

leaderboardWindow::~leaderboardWindow() {
    delete ui;
}

void leaderboardWindow::on_pushButton_3_clicked() {

    //start timer to keep time, timer sends events
    auto current_time = ui->timeEdit->time();
    if(current_time.hour() == 0 && current_time.minute() == 0) {
        return;
    }

    timer1->start(100);

    //do file i/o stuff
    QFile file("C:\\test.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        ui->textBrowser_2->append(line);
    }
    //ui->textBrowser_2->setText(in.readAll());
}

void leaderboardWindow::on_pushButton_clicked() {

}

void leaderboardWindow::on_pushButton_4_clicked() {

    //do timer stuff
    timer1->stop();
    QTime zero_time(0,0);
    ui->timeEdit->setTime(zero_time);
}

void leaderboardWindow::timerupdater() {

    auto input_time = ui->timeEdit->time();
    int minutes = input_time.hour();
    int seconds = input_time.minute();

    if(seconds == 0) {
        seconds = 59;
        minutes--;
    } else {
        seconds--;
    }

    if(seconds == 0 && minutes == 0) {
        on_pushButton_4_clicked();
    }

    ui->timeEdit->setTime(QTime(minutes, seconds));
}
