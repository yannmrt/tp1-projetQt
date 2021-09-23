/********************************************************************************
** Form generated from reading UI file 'WebSocket.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBSOCKET_H
#define UI_WEBSOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebSocketClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WebSocketClass)
    {
        if (WebSocketClass->objectName().isEmpty())
            WebSocketClass->setObjectName(QString::fromUtf8("WebSocketClass"));
        WebSocketClass->resize(600, 400);
        centralWidget = new QWidget(WebSocketClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        WebSocketClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WebSocketClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        WebSocketClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WebSocketClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WebSocketClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WebSocketClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WebSocketClass->setStatusBar(statusBar);

        retranslateUi(WebSocketClass);

        QMetaObject::connectSlotsByName(WebSocketClass);
    } // setupUi

    void retranslateUi(QMainWindow *WebSocketClass)
    {
        WebSocketClass->setWindowTitle(QCoreApplication::translate("WebSocketClass", "WebServer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WebSocketClass: public Ui_WebSocketClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBSOCKET_H
