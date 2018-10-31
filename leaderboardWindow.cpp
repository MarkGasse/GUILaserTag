#include "leaderboardwindow.h"
#include "ui_leaderboardwindow.h"
#include "startwindow.h"
#include "searchplayerwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTime>
#include <QTimeEdit>
#include <QTimer>
#include <QBasicTimer>
#include <QMovie>
#include <QtDebug>
#include <QScreen>
#include "QListWidget"
#include "mainwindow.h"
#include "QBrush"
#include <vector>

static QTimer *timer1 = new QTimer();

leaderboardWindow::leaderboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::leaderboardWindow)
{
    ui->setupUi(this);

    // setting gifs in array
    //Animations[0] = ("");
    //Animations[1] = ("");

    // get screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rec = screen->geometry();
    int w = rec.width();
    int h = rec.height();

    ui->CloseGUI->setGeometry(w-50,0,50,50);
    ui->pushButtonBack->setGeometry(150,0,150,50);
    ui->pushButtonBACK2->setGeometry(0,0,150,50);
    ui->Label_date->setGeometry(w-400,0,350,50);
    ui->labelTopBar->setGeometry(0,0,w,50);
    ui->groupBox->setGeometry(w/2+250,h/2-280,625,600);
    ui->groupBox_2->setGeometry(w/2-235,60,470,80);
    ui->groupBoxGIF->setGeometry(w/2-850,h/2-280,570,200);
    ui->label->setGeometry(w/2-840,h/2-270,510,190);
    ui->groupBoxEvents->setGeometry(w/2-850,h/2,570,400);
    ui->labelGM->setGeometry(w/2-300,0,600,50);
    ui->labelHPMatch->setGeometry(w/2+400,0,300,50);

    ui->label->setStyleSheet("background-color: lightblue");
    ui->pushButtonBack->setStyleSheet("background-color: lightGray");
    ui->pushButtonBACK2->setStyleSheet("background-color: Gray");
    ui->groupBox_2->setStyleSheet("Background-color: white");
    ui->Label_date->setStyleSheet("background-color: lightblue");
    ui->CloseGUI->setStyleSheet("background-color: red");
    ui->labelTopBar->setStyleSheet("background-color: lightblue");
    ui->groupBox->setStyleSheet("QGroupBox { border: 6px solid black;}");
    ui->groupBoxEvents->setStyleSheet("QGroupBox { border: 6px solid black;}");
    ui->groupBoxGIF->setStyleSheet("QGroupBox { border: 6px solid black;}");
    ui->labelGM->setStyleSheet("background-color: lightBlue");
    ui->textBrowserEvents->setStyleSheet("background-color: lightBlue ");

    this->setStyleSheet("background-color: white;");
    ui->timeEdit->setDisplayFormat("mm:ss");

    ui->pushButton_3->setStyleSheet("background-color: lightGreen");
    ui->pushButton_4->setStyleSheet("background-color: red");

    lb_item = QListWidgetItem(QIcon(":/resource/image/lb.png"), "             Name:                          K/D                         Points:       ");
    ui->listWidgetLeaderboard->addItem(&lb_item);
    ui->listWidgetLeaderboard->setStyleSheet("Background-color: lightblue");
    ui->labelHPMatch->setStyleSheet("background-color: lightBlue");



    QFile gm(game_mode);
    QString game_time;
    QString game_name;
    QString game_Titel;
    QString game_playerHP;

    gm.open(QIODevice::ReadOnly);

    ui->labelGM->setText(game_name);

    QTextStream gm_stream(&gm);
    while(!gm_stream.atEnd())
    {
        game_Titel = gm_stream.readLine();
        game_name = gm_stream.readLine();
        game_time = gm_stream.readLine();
        game_playerHP = gm_stream.readLine();
    }

    ui->labelGM->setText(game_name);

    ui->labelHPMatch->setText("Max HP players: " + game_playerHP);

    int minutes = game_time.toInt();

    ui->timeEdit->setTime(QTime(0, minutes, 0));

    connect (timer1, SIGNAL(timeout()),this,SLOT(timerupdater()));
    connect (timer1, SIGNAL(timeout()), this, SLOT(updateLB()));

}

leaderboardWindow::~leaderboardWindow() {
    delete ui;
}

void leaderboardWindow::writeToEventBox(QString message, QString textColor, QString type)
{
    ui->textBrowserEvents->setTextColor(textColor);
    //QString boldtext = "<b>" + type + message + "</b>";
    ui->textBrowserEvents->append((type + message));
}

void leaderboardWindow::on_pushButton_3_clicked() {
    if(stateTime == 1){
        //start timer to keep time, timer sends events
        auto current_time = ui->timeEdit->time();
        if(current_time.second() == 0 && current_time.minute() == 0) {
            return;
        }
        writeToEventBox("game started!","Green","Arduino: ");
        timer1->start(1000);
        stateTime = 0;
    }

}

void leaderboardWindow::on_pushButton_4_clicked() {
    if(stateTime == 0){
        //do timer stuff
        timer1->stop();
        writeToEventBox("game is paused!","purple","Arduino: ");
        stateTime = 1;
    }

}

void leaderboardWindow::updateLB()
{
    struct player
    {
        QString name;
        int kills;
        int deaths;
        int points;

    };

    std::vector<player> players;

    player p1 = {"player1", 10, 5, 200};
    player p2 = {"player2", 10, 5, 100};
    player p3 = {"player3", 10, 5, 500};

    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);

    for(unsigned int i = 0; i < players.size()-1; i++)
    {
        for(unsigned int j = 0; j < players.size()-i-1; j++)
        {
            if(players[j].points < players[j+1].points)
            {
                auto tmp = players[j];
                players[j] = players[j+1];
                players[j+1] = tmp;
            }
        }
    }

    ui->listWidgetLeaderboard->clear();
    auto lbiiii = new QListWidgetItem(QIcon(":/resource/image/lb.png"), "             Name:                          K/D                         Points:       ");
    ui->listWidgetLeaderboard->addItem(lbiiii);

    int pos = 1;
    for(auto & p : players)
    {
        QString str;

        QTextStream(&str) <<"#"<<pos<<"              "<<p.name<<"                           "<<p.kills/p.deaths<<"                                "<<p.points;
        QString str1 = "test";
        auto lbi = new QListWidgetItem(str);
        ui->listWidgetLeaderboard->addItem(lbi);
        pos++;
    }

}

void leaderboardWindow::timerupdater() {

    auto input_time = ui->timeEdit->time();
    int minutes = input_time.minute();
    int seconds = input_time.second();

    if(seconds == 0) {
        seconds = 59;
        minutes--;
    } else {
        seconds--;
    }

    if(seconds == 0 && minutes == 0) {
        writeToEventBox("game has ended!","red","Arduino: ");
        timer1->stop();
    }


    ui->timeEdit->setTime(QTime(0, minutes, seconds));
}

void leaderboardWindow::on_pushButtonBack_clicked()
{
    close();
    SearchPlayerWindow *SPW;
    SPW = new SearchPlayerWindow(this);
    SPW->showFullScreen();
}

void leaderboardWindow::on_pushButtonBACK2_clicked()
{
    close();
    StartWindow *SW;
    SW = new StartWindow(this);
    SW->showFullScreen();

}

void leaderboardWindow::setAnimation(int arrayPos)
{

    GIF = new QMovie(Animations[arrayPos]);
    GIF->setScaledSize(ui->label->size());
    ui->label->setMovie(GIF);
    GIF->start();
}
