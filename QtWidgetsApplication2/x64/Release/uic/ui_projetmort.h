/********************************************************************************
** Form generated from reading UI file 'projetmort.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETMORT_H
#define UI_PROJETMORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_projetmortClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *nom;
    QLineEdit *mdp;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *test;
    QLabel *co;
    QLabel *messagesend;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *SQL;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *projetmortClass)
    {
        if (projetmortClass->objectName().isEmpty())
            projetmortClass->setObjectName(QString::fromUtf8("projetmortClass"));
        projetmortClass->resize(602, 400);
        centralWidget = new QWidget(projetmortClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 40, 61, 21));
        nom = new QLineEdit(centralWidget);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(220, 70, 113, 20));
        mdp = new QLineEdit(centralWidget);
        mdp->setObjectName(QString::fromUtf8("mdp"));
        mdp->setGeometry(QRect(220, 110, 113, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 70, 81, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(146, 110, 71, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 140, 75, 23));
        test = new QLabel(centralWidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(180, 280, 91, 31));
        co = new QLabel(centralWidget);
        co->setObjectName(QString::fromUtf8("co"));
        co->setGeometry(QRect(480, 20, 101, 31));
        messagesend = new QLabel(centralWidget);
        messagesend->setObjectName(QString::fromUtf8("messagesend"));
        messagesend->setGeometry(QRect(240, 310, 71, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 280, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 250, 113, 20));
        SQL = new QLabel(centralWidget);
        SQL->setObjectName(QString::fromUtf8("SQL"));
        SQL->setGeometry(QRect(500, 70, 91, 31));
        projetmortClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(projetmortClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 21));
        projetmortClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(projetmortClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        projetmortClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(projetmortClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        projetmortClass->setStatusBar(statusBar);

        retranslateUi(projetmortClass);
        QObject::connect(pushButton, SIGNAL(clicked()), projetmortClass, SLOT(connexion()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), projetmortClass, SLOT(messageserver()));

        QMetaObject::connectSlotsByName(projetmortClass);
    } // setupUi

    void retranslateUi(QMainWindow *projetmortClass)
    {
        projetmortClass->setWindowTitle(QCoreApplication::translate("projetmortClass", "projetmort", nullptr));
        label->setText(QCoreApplication::translate("projetmortClass", "Connexion", nullptr));
        label_2->setText(QCoreApplication::translate("projetmortClass", "Nom d'user", nullptr));
        label_3->setText(QCoreApplication::translate("projetmortClass", "Mot de passe", nullptr));
        pushButton->setText(QCoreApplication::translate("projetmortClass", "Connexion", nullptr));
        test->setText(QString());
        co->setText(QString());
        messagesend->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("projetmortClass", "message", nullptr));
        SQL->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class projetmortClass: public Ui_projetmortClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETMORT_H
