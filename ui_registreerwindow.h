/********************************************************************************
** Form generated from reading UI file 'registreerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTREERWINDOW_H
#define UI_REGISTREERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registreerWindow
{
public:
    QLabel *label_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *username;
    QLineEdit *lineEditUser;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password;
    QLineEdit *lineEditPass;
    QHBoxLayout *horizontalLayout_3;
    QLabel *password2;
    QLineEdit *lineEditPass2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *code;
    QLineEdit *lineEditCode;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonRegistreer;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *registreerWindow)
    {
        if (registreerWindow->objectName().isEmpty())
            registreerWindow->setObjectName(QStringLiteral("registreerWindow"));
        registreerWindow->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QStringLiteral("R")));
        registreerWindow->setWindowIcon(icon);
        label_5 = new QLabel(registreerWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 30, 221, 41));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        widget = new QWidget(registreerWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 80, 244, 181));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        username = new QLabel(widget);
        username->setObjectName(QStringLiteral("username"));

        horizontalLayout->addWidget(username);

        lineEditUser = new QLineEdit(widget);
        lineEditUser->setObjectName(QStringLiteral("lineEditUser"));
        lineEditUser->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(lineEditUser);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        password = new QLabel(widget);
        password->setObjectName(QStringLiteral("password"));

        horizontalLayout_2->addWidget(password);

        lineEditPass = new QLineEdit(widget);
        lineEditPass->setObjectName(QStringLiteral("lineEditPass"));
        lineEditPass->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPass);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        password2 = new QLabel(widget);
        password2->setObjectName(QStringLiteral("password2"));

        horizontalLayout_3->addWidget(password2);

        lineEditPass2 = new QLineEdit(widget);
        lineEditPass2->setObjectName(QStringLiteral("lineEditPass2"));
        lineEditPass2->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEditPass2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        code = new QLabel(widget);
        code->setObjectName(QStringLiteral("code"));

        horizontalLayout_4->addWidget(code);

        lineEditCode = new QLineEdit(widget);
        lineEditCode->setObjectName(QStringLiteral("lineEditCode"));
        lineEditCode->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEditCode);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonRegistreer = new QPushButton(widget);
        pushButtonRegistreer->setObjectName(QStringLiteral("pushButtonRegistreer"));

        horizontalLayout_5->addWidget(pushButtonRegistreer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButtonCancel = new QPushButton(widget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_5->addWidget(pushButtonCancel);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(registreerWindow);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), registreerWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(registreerWindow);
    } // setupUi

    void retranslateUi(QDialog *registreerWindow)
    {
        registreerWindow->setWindowTitle(QApplication::translate("registreerWindow", "Registratie", nullptr));
        label_5->setText(QApplication::translate("registreerWindow", "Registratie", nullptr));
        username->setText(QApplication::translate("registreerWindow", "username", nullptr));
        password->setText(QApplication::translate("registreerWindow", "password ", nullptr));
        password2->setText(QApplication::translate("registreerWindow", "password ", nullptr));
        code->setText(QApplication::translate("registreerWindow", "code        ", nullptr));
        pushButtonRegistreer->setText(QApplication::translate("registreerWindow", "registreer", nullptr));
        pushButtonCancel->setText(QApplication::translate("registreerWindow", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registreerWindow: public Ui_registreerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTREERWINDOW_H
