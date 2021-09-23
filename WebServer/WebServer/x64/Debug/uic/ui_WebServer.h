/********************************************************************************
** Form generated from reading UI file 'WebServer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBSERVER_H
#define UI_WEBSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebServerClass
{
public:
    QWidget *centralWidget;
    QLabel *connectionStatusLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WebServerClass)
    {
        if (WebServerClass->objectName().isEmpty())
            WebServerClass->setObjectName(QString::fromUtf8("WebServerClass"));
        WebServerClass->resize(447, 400);
        centralWidget = new QWidget(WebServerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connectionStatusLabel = new QLabel(centralWidget);
        connectionStatusLabel->setObjectName(QString::fromUtf8("connectionStatusLabel"));
        connectionStatusLabel->setGeometry(QRect(40, 20, 351, 141));
        WebServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WebServerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 447, 21));
        WebServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WebServerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WebServerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WebServerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WebServerClass->setStatusBar(statusBar);

        retranslateUi(WebServerClass);

        QMetaObject::connectSlotsByName(WebServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *WebServerClass)
    {
        WebServerClass->setWindowTitle(QCoreApplication::translate("WebServerClass", "WebServer", nullptr));
        connectionStatusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WebServerClass: public Ui_WebServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBSERVER_H
