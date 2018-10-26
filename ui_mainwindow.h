/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *CloseGUI;
    QGroupBox *groupBoxLogin;
    QPushButton *LoginButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutLogin;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLineEdit *lineEdit_Username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPassword;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButtonRegistreer;
    QLabel *labelLogo;
    QLabel *Titel;
    QLabel *Group;
    QLabel *labelTopBar;
    QLabel *Label_date;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBarLogin;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1252, 1023);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        CloseGUI = new QPushButton(centralWidget);
        CloseGUI->setObjectName(QStringLiteral("CloseGUI"));
        CloseGUI->setGeometry(QRect(960, 400, 41, 28));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        CloseGUI->setFont(font);
        CloseGUI->setAutoFillBackground(false);
        CloseGUI->setStyleSheet(QStringLiteral("image (:/resource/image/quitButton.png);"));
        groupBoxLogin = new QGroupBox(centralWidget);
        groupBoxLogin->setObjectName(QStringLiteral("groupBoxLogin"));
        groupBoxLogin->setGeometry(QRect(610, 620, 261, 151));
        LoginButton = new QPushButton(groupBoxLogin);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setEnabled(true);
        LoginButton->setGeometry(QRect(160, 110, 93, 28));
        LoginButton->setAutoFillBackground(false);
        layoutWidget = new QWidget(groupBoxLogin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 241, 81));
        verticalLayoutLogin = new QVBoxLayout(layoutWidget);
        verticalLayoutLogin->setSpacing(6);
        verticalLayoutLogin->setContentsMargins(11, 11, 11, 11);
        verticalLayoutLogin->setObjectName(QStringLiteral("verticalLayoutLogin"));
        verticalLayoutLogin->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelUserName = new QLabel(layoutWidget);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setEnabled(true);

        horizontalLayout->addWidget(labelUserName);

        lineEdit_Username = new QLineEdit(layoutWidget);
        lineEdit_Username->setObjectName(QStringLiteral("lineEdit_Username"));

        horizontalLayout->addWidget(lineEdit_Username);


        verticalLayoutLogin->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        horizontalLayout_2->addWidget(labelPassword);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Password);


        verticalLayoutLogin->addLayout(horizontalLayout_2);

        pushButtonRegistreer = new QPushButton(groupBoxLogin);
        pushButtonRegistreer->setObjectName(QStringLiteral("pushButtonRegistreer"));
        pushButtonRegistreer->setGeometry(QRect(10, 110, 93, 28));
        labelLogo = new QLabel(centralWidget);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        labelLogo->setGeometry(QRect(491, 468, 114, 149));
        Titel = new QLabel(centralWidget);
        Titel->setObjectName(QStringLiteral("Titel"));
        Titel->setGeometry(QRect(613, 469, 316, 103));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Calligraphy"));
        font1.setPointSize(48);
        Titel->setFont(font1);
        Group = new QLabel(centralWidget);
        Group->setObjectName(QStringLiteral("Group"));
        Group->setGeometry(QRect(613, 579, 317, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Modern No. 20"));
        font2.setPointSize(14);
        Group->setFont(font2);
        Group->setAutoFillBackground(false);
        labelTopBar = new QLabel(centralWidget);
        labelTopBar->setObjectName(QStringLiteral("labelTopBar"));
        labelTopBar->setGeometry(QRect(490, 205, 371, 111));
        Label_date = new QLabel(centralWidget);
        Label_date->setObjectName(QStringLiteral("Label_date"));
        Label_date->setGeometry(QRect(550, 260, 251, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setWeight(50);
        Label_date->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        Group->raise();
        CloseGUI->raise();
        groupBoxLogin->raise();
        labelLogo->raise();
        Titel->raise();
        labelTopBar->raise();
        Label_date->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1252, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBarLogin = new QStatusBar(MainWindow);
        statusBarLogin->setObjectName(QStringLiteral("statusBarLogin"));
        statusBarLogin->setEnabled(true);
        MainWindow->setStatusBar(statusBarLogin);

        retranslateUi(MainWindow);
        QObject::connect(CloseGUI, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        CloseGUI->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        groupBoxLogin->setTitle(QApplication::translate("MainWindow", "Login", nullptr));
        LoginButton->setText(QApplication::translate("MainWindow", "Login", nullptr));
        labelUserName->setText(QApplication::translate("MainWindow", "Username", nullptr));
        labelPassword->setText(QApplication::translate("MainWindow", "Password ", nullptr));
        pushButtonRegistreer->setText(QApplication::translate("MainWindow", "registreer", nullptr));
        labelLogo->setText(QString());
        Titel->setText(QApplication::translate("MainWindow", "BroTag", nullptr));
        Group->setText(QApplication::translate("MainWindow", "                             by Do you even!", nullptr));
        labelTopBar->setText(QString());
        Label_date->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
