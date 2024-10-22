/********************************************************************************
** Form generated from reading UI file 'Udp_reciver.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDP_RECIVER_H
#define UI_UDP_RECIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Udp_reciver
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Udp_reciver)
    {
        if (Udp_reciver->objectName().isEmpty())
            Udp_reciver->setObjectName("Udp_reciver");
        Udp_reciver->resize(800, 600);
        centralwidget = new QWidget(Udp_reciver);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 250, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(510, 250, 49, 16));
        Udp_reciver->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Udp_reciver);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Udp_reciver->setMenuBar(menubar);
        statusbar = new QStatusBar(Udp_reciver);
        statusbar->setObjectName("statusbar");
        Udp_reciver->setStatusBar(statusbar);

        retranslateUi(Udp_reciver);

        QMetaObject::connectSlotsByName(Udp_reciver);
    } // setupUi

    void retranslateUi(QMainWindow *Udp_reciver)
    {
        Udp_reciver->setWindowTitle(QCoreApplication::translate("Udp_reciver", "Udp_reciver", nullptr));
        pushButton->setText(QCoreApplication::translate("Udp_reciver", "Send Data", nullptr));
        label->setText(QCoreApplication::translate("Udp_reciver", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Udp_reciver: public Ui_Udp_reciver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDP_RECIVER_H
