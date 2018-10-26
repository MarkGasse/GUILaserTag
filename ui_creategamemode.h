/********************************************************************************
** Form generated from reading UI file 'creategamemode.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGAMEMODE_H
#define UI_CREATEGAMEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateGameMode
{
public:
    QPushButton *pushButtonCreate;
    QPushButton *pushButtonCancel;
    QLabel *labelTitel;

    void setupUi(QDialog *CreateGameMode)
    {
        if (CreateGameMode->objectName().isEmpty())
            CreateGameMode->setObjectName(QStringLiteral("CreateGameMode"));
        CreateGameMode->resize(400, 300);
        pushButtonCreate = new QPushButton(CreateGameMode);
        pushButtonCreate->setObjectName(QStringLiteral("pushButtonCreate"));
        pushButtonCreate->setGeometry(QRect(60, 220, 93, 28));
        pushButtonCancel = new QPushButton(CreateGameMode);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(230, 220, 93, 28));
        labelTitel = new QLabel(CreateGameMode);
        labelTitel->setObjectName(QStringLiteral("labelTitel"));
        labelTitel->setGeometry(QRect(60, 10, 271, 61));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelTitel->setFont(font);

        retranslateUi(CreateGameMode);

        QMetaObject::connectSlotsByName(CreateGameMode);
    } // setupUi

    void retranslateUi(QDialog *CreateGameMode)
    {
        CreateGameMode->setWindowTitle(QApplication::translate("CreateGameMode", "Dialog", nullptr));
        pushButtonCreate->setText(QApplication::translate("CreateGameMode", "create", nullptr));
        pushButtonCancel->setText(QApplication::translate("CreateGameMode", "cancel", nullptr));
        labelTitel->setText(QApplication::translate("CreateGameMode", "Create GameMode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGameMode: public Ui_CreateGameMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGAMEMODE_H
