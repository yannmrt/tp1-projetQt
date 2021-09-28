/********************************************************************************
** Form generated from reading UI file 'Tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
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
    QLabel *co;
    QLabel *messagesend;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *SQL;
    QLabel *test2;
    QTextEdit *test;
    QPushButton *insc;
    QLabel *labelinsc;
    QLabel *label_4;
    QPushButton *actu;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *projetmortClass)
    {
        if (projetmortClass->objectName().isEmpty())
            projetmortClass->setObjectName(QString::fromUtf8("projetmortClass"));
        projetmortClass->resize(600, 489);
        centralWidget = new QWidget(projetmortClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 110, 61, 21));
        nom = new QLineEdit(centralWidget);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(220, 140, 113, 20));
        mdp = new QLineEdit(centralWidget);
        mdp->setObjectName(QString::fromUtf8("mdp"));
        mdp->setGeometry(QRect(220, 180, 113, 20));
        mdp->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 140, 81, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(146, 180, 71, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 210, 75, 23));
        co = new QLabel(centralWidget);
        co->setObjectName(QString::fromUtf8("co"));
        co->setGeometry(QRect(480, 90, 101, 31));
        messagesend = new QLabel(centralWidget);
        messagesend->setObjectName(QString::fromUtf8("messagesend"));
        messagesend->setGeometry(QRect(220, 390, 131, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 320, 91, 71));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 320, 321, 71));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        SQL = new QLabel(centralWidget);
        SQL->setObjectName(QString::fromUtf8("SQL"));
        SQL->setGeometry(QRect(500, 140, 91, 31));
        test2 = new QLabel(centralWidget);
        test2->setObjectName(QString::fromUtf8("test2"));
        test2->setGeometry(QRect(10, 120, 111, 31));
        test2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        test = new QTextEdit(centralWidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(113, 100, 321, 211));
        test->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        test->setUndoRedoEnabled(true);
        test->setReadOnly(true);
        insc = new QPushButton(centralWidget);
        insc->setObjectName(QString::fromUtf8("insc"));
        insc->setGeometry(QRect(240, 240, 75, 23));
        labelinsc = new QLabel(centralWidget);
        labelinsc->setObjectName(QString::fromUtf8("labelinsc"));
        labelinsc->setGeometry(QRect(170, 260, 221, 31));
        labelinsc->setLayoutDirection(Qt::LeftToRight);
        labelinsc->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 10, 181, 81));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/image.png")));
        actu = new QPushButton(centralWidget);
        actu->setObjectName(QString::fromUtf8("actu"));
        actu->setGeometry(QRect(480, 210, 75, 23));
        projetmortClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(projetmortClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
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
        QObject::connect(insc, SIGNAL(clicked()), projetmortClass, SLOT(incri()));
        QObject::connect(actu, SIGNAL(clicked()), projetmortClass, SLOT(actu()));

        QMetaObject::connectSlotsByName(projetmortClass);
    } // setupUi

    void retranslateUi(QMainWindow *projetmortClass)
    {
        projetmortClass->setWindowTitle(QCoreApplication::translate("projetmortClass", "projetmort", nullptr));
        label->setText(QCoreApplication::translate("projetmortClass", "Connexion", nullptr));
        label_2->setText(QCoreApplication::translate("projetmortClass", "Nom d'user", nullptr));
        label_3->setText(QCoreApplication::translate("projetmortClass", "Mot de passe", nullptr));
        pushButton->setText(QCoreApplication::translate("projetmortClass", "Connexion", nullptr));
        co->setText(QString());
        messagesend->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("projetmortClass", "message", nullptr));
        SQL->setText(QString());
        test2->setText(QString());
        insc->setText(QCoreApplication::translate("projetmortClass", "Incription", nullptr));
        labelinsc->setText(QString());
        label_4->setText(QString());
        actu->setText(QCoreApplication::translate("projetmortClass", "Actualiser", nullptr));
    } // retranslateUi

};

namespace Ui {
    class projetmortClass: public Ui_projetmortClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
