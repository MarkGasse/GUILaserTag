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

leaderboardWindow::leaderboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::leaderboardWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer();
    timer2 = new QTimer();

    //setting gifs in array
    Animations[0] = ("");
    Animations[1] = (":/gif/killAnimation/AnimationKill/schieten 2.gif");



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
    ui->groupBox_2->setGeometry(w/2-235,60,470,80);
    ui->groupBoxGIF->setGeometry(w/2-850,h/2-430,570,400);
    ui->label->setGeometry(20,20,530,360);
    ui->groupBoxEvents->setGeometry(w/2-850,h/2,570,500);
    ui->textBrowserEvents->setGeometry(20,20,530,460);
    ui->labelGM->setGeometry(w/2-300,0,600,50);
    ui->labelHPMatch->setGeometry(w/2+400,0,300,50);
    ui->listWidgetLeaderboard->setGeometry(20,20,585,910);

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
    connect(timer2, SIGNAL(timeout()),this,SLOT(stopAnimation()));

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

void leaderboardWindow::on_pushButton_3_clicked()
{
    auto current_time = ui->timeEdit->time();
    if(current_time.second() == 0 && current_time.minute() == 0)
    {
        return;
    }



    if(gameStarted == 1){
        writeToEventBox("game started!","Green","Arduino: ");
        setAnimation(1);
        timer1->start(1000);
         gameStarted = 0;
        gameIsRunning = 1;
    }

}

void leaderboardWindow::on_pushButton_4_clicked()
{
    if(gameStarted == 0){
        //do timer stuff
        timer1->stop();
        timer2->stop();
        writeToEventBox("game is paused!","purple","Arduino: ");
        gameStarted = 1;
        gameIsRunning = 0;
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

        QTextStream(&str) <<"#"<<pos<<"              "<<p.name<<"                         "<<p.kills<<"/"<<p.deaths<<"                          "<<p.points;
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
        gameIsRunning = 0;
        timer1->stop();
    }


    ui->timeEdit->setTime(QTime(0, minutes, seconds));
}

void leaderboardWindow::on_pushButtonBack_clicked()
{
    if(gameIsRunning) return;

    SearchPlayerWindow *SPW;
    SPW = new SearchPlayerWindow();
    SPW->showFullScreen();
    close();

}

void leaderboardWindow::on_pushButtonBACK2_clicked()
{
    if(gameIsRunning) return;

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
    timer2->start(2300);

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
