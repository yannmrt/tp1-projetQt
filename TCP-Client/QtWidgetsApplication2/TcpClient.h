#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TcpClient.h"
#include <QTcpSocket>
#include <QtSql>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QCryptographicHash>
#include <QPixmap>


class TcpCLient : public QMainWindow
{
    Q_OBJECT

public:
	TcpCLient(QWidget *parent = Q_NULLPTR);

private:
    Ui::projetmortClass ui;
	QTcpSocket * socket;
	int init = 0; //permet d'initaliser la connexion
	char mess = 10;
	QString pseudo; //permet de sauvegarder le pseudo


private slots: //les differente fonction décrite dans le .cpp
	void connexion();
	void onSocketDisonnected();
	void onSocketConnected();
	void messageserver();
	void messagerecu();
	void incri();
};

