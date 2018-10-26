/********************************************************************************
** Form generated from reading UI file 'searchplayerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHPLAYERWINDOW_H
#define UI_SEARCHPLAYERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchPlayerWindow
{
public:
    QWidget *centralwidget;
    QLabel *Titel;
    QPushButton *CloseGUI;
    QLabel *Group;
    QLabel *Label_date;
    QLabel *labelTopBar;
    QLabel *labelLogo;
    QGroupBox *groupBoxSearch;
    QWidget *widget;
    QVBoxLayout *verticalLayoutSearch;
    QTextBrowser *textBrowserS;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonSearch;
    QSpacerItem *horizontalSpacerS;
    QPushButton *pushButtonStopS;
    QPushButton *pushButtonStart;

    void setupUi(QMainWindow *SearchPlayerWindow)
    {
        if (SearchPlayerWindow->objectName().isEmpty())
            SearchPlayerWindow->setObjectName(QStringLiteral("SearchPlayerWindow"));
        SearchPlayerWindow->resize(990, 768);
        centralwidget = new QWidget(SearchPlayerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Titel = new QLabel(centralwidget);
        Titel->setObjectName(QStringLiteral("Titel"));
        Titel->setGeometry(QRect(753, 904, 316, 103));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Calligraphy"));
        font.setPointSize(48);
        Titel->setFont(font);
        CloseGUI = new QPushButton(centralwidget);
        CloseGUI->setObjectName(QStringLiteral("CloseGUI"));
        CloseGUI->setGeometry(QRect(170, 170, 41, 28));
        Group = new QLabel(centralwidget);
        Group->setObjectName(QStringLiteral("Group"));
        Group->setGeometry(QRect(753, 1014, 317, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Modern No. 20"));
        font1.setPointSize(14);
        Group->setFont(font1);
        Group->setAutoFillBackground(false);
        Label_date = new QLabel(centralwidget);
        Label_date->setObjectName(QStringLiteral("Label_date"));
        Label_date->setGeometry(QRect(690, 695, 251, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setWeight(50);
        Label_date->setFont(font2);
        labelTopBar = new QLabel(centralwidget);
        labelTopBar->setObjectName(QStringLiteral("labelTopBar"));
        labelTopBar->setGeometry(QRect(630, 640, 371, 111));
        labelLogo = new QLabel(centralwidget);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        labelLogo->setGeometry(QRect(631, 903, 114, 149));
        groupBoxSearch = new QGroupBox(centralwidget);
        groupBoxSearch->setObjectName(QStringLiteral("groupBoxSearch"));
        groupBoxSearch->setGeometry(QRect(370, 50, 261, 301));
        widget = new QWidget(groupBoxSearch);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 300, 266));
        verticalLayoutSearch = new QVBoxLayout(widget);
        verticalLayoutSearch->setObjectName(QStringLiteral("verticalLayoutSearch"));
        verticalLayoutSearch->setContentsMargins(0, 0, 0, 0);
        textBrowserS = new QTextBrowser(widget);
        textBrowserS->setObjectName(QStringLiteral("textBrowserS"));

        verticalLayoutSearch->addWidget(textBrowserS);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonSearch = new QPushButton(widget);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        horizontalLayout->addWidget(pushButtonSearch);

        horizontalSpacerS = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerS);

        pushButtonStopS = new QPushButton(widget);
        pushButtonStopS->setObjectName(QStringLiteral("pushButtonStopS"));

        horizontalLayout->addWidget(pushButtonStopS);


        verticalLayoutSearch->addLayout(horizontalLayout);

        pushButtonStart = new QPushButton(widget);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        verticalLayoutSearch->addWidget(pushButtonStart);

        SearchPlayerWindow->setCentralWidget(centralwidget);

        retranslateUi(SearchPlayerWindow);
        QObject::connect(CloseGUI, SIGNAL(clicked()), SearchPlayerWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(SearchPlayerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SearchPlayerWindow)
    {
        SearchPlayerWindow->setWindowTitle(QApplication::translate("SearchPlayerWindow", "MainWindow", nullptr));
        Titel->setText(QApplication::translate("SearchPlayerWindow", "BroTag", nullptr));
        CloseGUI->setText(QApplication::translate("SearchPlayerWindow", "Quit", nullptr));
        Group->setText(QApplication::translate("SearchPlayerWindow", "                             by Do you even!", nullptr));
        Label_date->setText(QString());
        labelTopBar->setText(QString());
        labelLogo->setText(QString());
        groupBoxSearch->setTitle(QApplication::translate("SearchPlayerWindow", "Config players", nullptr));
        pushButtonSearch->setText(QApplication::translate("SearchPlayerWindow", "Search players", nullptr));
        pushButtonStopS->setText(QApplication::translate("SearchPlayerWindow", "Stop searching", nullptr));
        pushButtonStart->setText(QApplication::translate("SearchPlayerWindow", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchPlayerWindow: public Ui_SearchPlayerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHPLAYERWINDOW_H
