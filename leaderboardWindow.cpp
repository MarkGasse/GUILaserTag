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
#include "../lasergameServerClass/tcpServer.hpp"
#include "searchplayerwindow.h"

std::vector<std::string> killedbylog = {};

struct player
{
    QString name;
    int kills;
    int deaths;
    int points;

};

leaderboardWindow::leaderboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::leaderboardWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer();
    timer2 = new QTimer();

    //setting gifs in array
    Animations[0] = (":/AnimationEnd/AnimationEnd/schieten 2 (1).gif");
    Animations[1] = (":/gif/killAnimation/AnimationKill/schieten 2.gif");
     Animations[2] = (":/start/AnimationStart/schieten 2_1.gif");

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
    ui->groupBox->setGeometry(w/2+250,h/2-430,625,950);
    ui->groupBox_2->setGeometry(w/2-235,260,470,80);
    ui->groupBoxGIF->setGeometry(w/2-850,h/2-430,570,400);
    ui->label->setGeometry(20,20,530,360);
    ui->groupBoxEvents->setGeometry(w/2-850,h/2,570,500);
    ui->textBrowserEvents->setGeometry(20,20,530,460);
    ui->labelGM->setGeometry(w/2-300,0,600,50);
    ui->labelHPMatch->setGeometry(w/2+400,0,300,50);
    ui->listWidgetLeaderboard->setGeometry(20,20,585,910);
    ui->pushButtonBack->hide();
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
    QString game_name;
    QString game_Titel;
    QString game_playerHP;
    QString game_players;
    QString game_deeps;

    gm.open(QIODevice::ReadOnly);
    //read game_mode/client info into variables
    QTextStream gm_stream(&gm);
    while(!gm_stream.atEnd())
    {
        game_Titel = gm_stream.readLine();
        game_name = gm_stream.readLine();
        game_time = gm_stream.readLine();
        game_playerHP = gm_stream.readLine();
        game_players = gm_stream.readLine();
        game_deeps = gm_stream.readLine();
    }

    ui->labelGM->setText(game_name);
    int playerhp = game_playerHP.toInt();
    int deeps = game_deeps.toInt();

    //set clients' internal info
    for(auto & c : clients)
    {
        if(c.con == 1)
        {
            c.kills = 0;
            c.deaths = 0;
            c.hp = playerhp;
            c.dmg = deeps;
        }
    }

    ui->labelGM->setText(game_name);
    ui->labelHPMatch->setText("Max HP players: " + game_playerHP);

    int minutes = game_time.toInt();
    ui->timeEdit->setTime(QTime(0, minutes, 0));

    //connects functions to clocked timers
    connect (timer1, SIGNAL(timeout()),this,SLOT(timerupdater()));
    connect (timer1, SIGNAL(timeout()), this, SLOT(updateLB()));
    connect(timer2, SIGNAL(timeout()),this,SLOT(stopAnimation()));
}

leaderboardWindow::~leaderboardWindow()
{
    delete ui;
}

void leaderboardWindow::writeToEventBox(QString message, QString textColor, QString type)
{
    ui->textBrowserEvents->setTextColor(textColor);
    ui->textBrowserEvents->append((type + message));
}

//Game start button
void leaderboardWindow::on_pushButton_3_clicked()
{
    auto current_time = ui->timeEdit->time();
    if(current_time.second() == 0 && current_time.minute() == 0)
    {
        return;
    }

    if(gameStarted == 0)
    {
        writeToEventBox("game started!","Green","GUI: ");
        setAnimation(2);
        timer1->start(1000);
         gameStarted = 1;
        gameIsRunning = 1;
        S.startGame();
    }
}

//game stop button
void leaderboardWindow::on_pushButton_4_clicked()
{
    if(gameStarted == 1)
    {
        //do timer stuff
        timer1->stop();
        timer2->stop();
        writeToEventBox("game stopped!","red","GUI: ");
        //change states
        gameStarted = 0;
        gameIsRunning = 0;
        int minutes = game_time.toInt();
        ui->timeEdit->setTime(QTime(0, minutes, 0));
        //send GameOver to clients
        S.gameOver();
    }
}

//function that calculates and updates stuff for the leaderboard, every 1000ms
void leaderboardWindow::updateLB()
{
    static std::vector<player> players;

    for(int i = 0; i < S.maxClients; i++)
    {
        if(S.clients[i].con)
        {
            const char *ch_name = S.clients[i].name.c_str();
            QString qstr_name = ch_name;

            int k = S.clients[i].kills;
            int d = S.clients[i].deaths;
            int p = k*100 - d*100;
            (p < 0) ? p = 0 : p;

            player pl = {qstr_name, k, d, p};
            players.push_back(pl);
        }
    }

    if(players.size() > 1)
    {
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
    }

    ui->listWidgetLeaderboard->clear();
    auto lbiiii = new QListWidgetItem(QIcon(":/resource/image/lb.png"), "             Name:                          K/D                         Points:       ");
    ui->listWidgetLeaderboard->addItem(lbiiii);

    int pos = 1;
    for(auto & p : players)
    {
        QString str;
        QTextStream(&str) <<"#"<<pos<<"              "<<p.name<<"                         "<<p.kills<<"/"<<p.deaths<<"                          "<<p.points;
        QString str1 = "test";
        auto lbi = new QListWidgetItem(str);
        ui->listWidgetLeaderboard->addItem(lbi);
        pos++;
    }
    players.clear();
    S.receiveCli();

    for(auto & s : killedbylog)
    {
        QString si = s.c_str();
        writeToEventBox(si,"yellow", "Arduino: ");
        setAnimation(1);
    }
    killedbylog.clear();
}

void leaderboardWindow::timerupdater()
{
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
        setAnimation(0);
        writeToEventBox("game has ended!","red","GUI: ");
        gameIsRunning = 0;
        timer1->stop();
        S.gameOver();
    }

    if(seconds == 0 && minutes == 1)
    {
        S.oneMinuteLeft();
    }

    ui->timeEdit->setTime(QTime(0, minutes, seconds));
}

void leaderboardWindow::on_pushButtonBack_clicked()
{
    if(gameIsRunning)
    {
        QMessageBox::warning(this,tr("ERROR "),tr("Please stop the game."),QMessageBox::Ok);
        return;
    }

    S.gameOver();
    SearchPlayerWindow *SPW;
    SPW = new SearchPlayerWindow();

    SPW->showFullScreen();
    close();
}


//back to game mode selection button
void leaderboardWindow::on_pushButtonBACK2_clicked()
{
    if(gameIsRunning)
    {
        QMessageBox::warning(this,tr("ERROR "),tr("Please stop the game."),QMessageBox::Ok);
        return;
    }

    S.~tcpServer();
    new(&S)tcpServer("8080", clients, amountOfPlayers);

    StartWindow *SW;
    SW = new StartWindow();
    SW->showFullScreen();
    close();
}

void leaderboardWindow::setAnimation(int arrayPos)
{
    GIF = new QMovie(Animations[arrayPos]);
    GIF->setScaledSize(ui->label->size());
    ui->label->setMovie(GIF);
    GIF->start();
    timer2->start(2200);

}

void leaderboardWindow::on_CloseGUI_clicked()
{
    if(gameIsRunning)
    {
        QMessageBox::warning(this,tr("ERROR "),tr("Please stop the game before exiting."),QMessageBox::Ok);
        return;
    } else {
        QApplication::quit();
    }
}

void leaderboardWindow::stopAnimation()
{
    GIF->stop();
    timer2->stop();
    ui->label->setStyleSheet("background-color: lightblue");
    delete GIF;
}
