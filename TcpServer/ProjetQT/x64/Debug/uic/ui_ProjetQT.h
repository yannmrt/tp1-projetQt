/********************************************************************************
** Form generated from reading UI file 'ProjetQT.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETQT_H
#define UI_PROJETQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjetQTClass
{
public:
    QWidget *centralWidget;
    QLabel *connectionStatusLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetQTClass)
    {
        if (ProjetQTClass->objectName().isEmpty())
            ProjetQTClass->setObjectName(QString::fromUtf8("ProjetQTClass"));
        ProjetQTClass->resize(600, 400);
        centralWidget = new QWidget(ProjetQTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connectionStatusLabel = new QLabel(centralWidget);
        connectionStatusLabel->setObjectName(QString::fromUtf8("connectionStatusLabel"));
        connectionStatusLabel->setGeometry(QRect(40, 20, 931, 61));
        ProjetQTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjetQTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ProjetQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjetQTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProjetQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjetQTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProjetQTClass->setStatusBar(statusBar);

        retranslateUi(ProjetQTClass);

        QMetaObject::connectSlotsByName(ProjetQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjetQTClass)
    {
        ProjetQTClass->setWindowTitle(QCoreApplication::translate("ProjetQTClass", "ProjetQT", nullptr));
        connectionStatusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProjetQTClass: public Ui_ProjetQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETQT_H
