/********************************************************************************
** Form generated from reading UI file 'creategm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGM_H
#define UI_CREATEGM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGM
{
public:
    QLabel *labelTitel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditName;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxMode;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBoxTime;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonCreate;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *CreateGM)
    {
        if (CreateGM->objectName().isEmpty())
            CreateGM->setObjectName(QStringLiteral("CreateGM"));
        CreateGM->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QStringLiteral("-")));
        CreateGM->setWindowIcon(icon);
        labelTitel = new QLabel(CreateGM);
        labelTitel->setObjectName(QStringLiteral("labelTitel"));
        labelTitel->setGeometry(QRect(60, 10, 271, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelTitel->setFont(font);
        widget = new QWidget(CreateGM);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 70, 241, 201));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout_3->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, -1);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxMode = new QComboBox(widget);
        comboBoxMode->setObjectName(QStringLiteral("comboBoxMode"));

        horizontalLayout_2->addWidget(comboBoxMode);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBoxTime = new QComboBox(widget);
        comboBoxTime->setObjectName(QStringLiteral("comboBoxTime"));

        horizontalLayout->addWidget(comboBoxTime);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonCreate = new QPushButton(widget);
        pushButtonCreate->setObjectName(QStringLiteral("pushButtonCreate"));

        horizontalLayout_4->addWidget(pushButtonCreate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButtonCancel = new QPushButton(widget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_4->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(CreateGM);

        QMetaObject::connectSlotsByName(CreateGM);
    } // setupUi

    void retranslateUi(QDialog *CreateGM)
    {
        CreateGM->setWindowTitle(QApplication::translate("CreateGM", "Create", nullptr));
        labelTitel->setText(QApplication::translate("CreateGM", "Create GameMode", nullptr));
        label->setText(QApplication::translate("CreateGM", "name:                   ", nullptr));
        label_2->setText(QApplication::translate("CreateGM", "mode:                  ", nullptr));
        label_3->setText(QApplication::translate("CreateGM", "time:", nullptr));
        pushButtonCreate->setText(QApplication::translate("CreateGM", "create", nullptr));
        pushButtonCancel->setText(QApplication::translate("CreateGM", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGM: public Ui_CreateGM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGM_H
