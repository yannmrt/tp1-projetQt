/********************************************************************************
** Form generated from reading UI file 'TcpServer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServerClass
{
public:
    QWidget *centralWidget;
    QLabel *connectionStatusLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TcpServerClass)
    {
        if (TcpServerClass->objectName().isEmpty())
            TcpServerClass->setObjectName(QString::fromUtf8("TcpServerClass"));
        TcpServerClass->resize(600, 400);
        centralWidget = new QWidget(TcpServerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connectionStatusLabel = new QLabel(centralWidget);
        connectionStatusLabel->setObjectName(QString::fromUtf8("connectionStatusLabel"));
        connectionStatusLabel->setGeometry(QRect(40, 20, 931, 61));
        TcpServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TcpServerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        TcpServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TcpServerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TcpServerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TcpServerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TcpServerClass->setStatusBar(statusBar);

        retranslateUi(TcpServerClass);

        QMetaObject::connectSlotsByName(TcpServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TcpServerClass)
    {
        TcpServerClass->setWindowTitle(QCoreApplication::translate("TcpServerClass", "TCP Server", nullptr));
        connectionStatusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TcpServerClass: public Ui_TcpServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
