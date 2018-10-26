/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *CloseGUI;
    QLabel *labelTopBar;
    QLabel *Titel;
    QLabel *Label_date;
    QLabel *labelLogo;
    QLabel *Group;
    QGroupBox *groupBoxGame;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidgetGame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonDelete;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCreate;
    QPushButton *pushButtonStart;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(968, 796);
        CloseGUI = new QPushButton(StartWindow);
        CloseGUI->setObjectName(QStringLiteral("CloseGUI"));
        CloseGUI->setGeometry(QRect(360, 0, 41, 28));
        labelTopBar = new QLabel(StartWindow);
        labelTopBar->setObjectName(QStringLiteral("labelTopBar"));
        labelTopBar->setGeometry(QRect(540, 390, 371, 111));
        Titel = new QLabel(StartWindow);
        Titel->setObjectName(QStringLiteral("Titel"));
        Titel->setGeometry(QRect(663, 654, 316, 103));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Calligraphy"));
        font.setPointSize(48);
        Titel->setFont(font);
        Label_date = new QLabel(StartWindow);
        Label_date->setObjectName(QStringLiteral("Label_date"));
        Label_date->setGeometry(QRect(600, 445, 251, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        Label_date->setFont(font1);
        labelLogo = new QLabel(StartWindow);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        labelLogo->setGeometry(QRect(541, 653, 114, 149));
        Group = new QLabel(StartWindow);
        Group->setObjectName(QStringLiteral("Group"));
        Group->setGeometry(QRect(663, 764, 317, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Modern No. 20"));
        font2.setPointSize(14);
        Group->setFont(font2);
        Group->setAutoFillBackground(false);
        groupBoxGame = new QGroupBox(StartWindow);
        groupBoxGame->setObjectName(QStringLiteral("groupBoxGame"));
        groupBoxGame->setGeometry(QRect(220, 150, 271, 281));
        widget = new QWidget(groupBoxGame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 258, 229));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidgetGame = new QListWidget(widget);
        listWidgetGame->setObjectName(QStringLiteral("listWidgetGame"));

        verticalLayout->addWidget(listWidgetGame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonDelete = new QPushButton(widget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));

        horizontalLayout->addWidget(pushButtonDelete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonCreate = new QPushButton(widget);
        pushButtonCreate->setObjectName(QStringLiteral("pushButtonCreate"));

        horizontalLayout->addWidget(pushButtonCreate);


        verticalLayout->addLayout(horizontalLayout);

        pushButtonStart = new QPushButton(widget);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        verticalLayout->addWidget(pushButtonStart);


        retranslateUi(StartWindow);
        QObject::connect(CloseGUI, SIGNAL(clicked()), StartWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Dialog", nullptr));
        CloseGUI->setText(QApplication::translate("StartWindow", "Quit", nullptr));
        labelTopBar->setText(QString());
        Titel->setText(QApplication::translate("StartWindow", "BroTag", nullptr));
        Label_date->setText(QString());
        labelLogo->setText(QString());
        Group->setText(QApplication::translate("StartWindow", "                             by Do you even!", nullptr));
        groupBoxGame->setTitle(QApplication::translate("StartWindow", "Gamemode:", nullptr));
        pushButtonDelete->setText(QApplication::translate("StartWindow", "Delete", nullptr));
        pushButtonCreate->setText(QApplication::translate("StartWindow", "Create", nullptr));
        pushButtonStart->setText(QApplication::translate("StartWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
