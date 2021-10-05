#include <QtWidgets/QMainWindow>
#include "ui_TcpServer.h"
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <iostream>
#include <QtWebSockets/QtWebSockets>

#include <QApplication>
#include <QDateTime>
#include <QtSql/QtSql>
#include <QSqlQuery>


class TcpServer : public QMainWindow
{
    Q_OBJECT

public:
	TcpServer(QWidget *parent = Q_NULLPTR);
	char requete;
	char retour;
	char donnees;
	int sizeTable = 0;

private:
    Ui::TcpServerClass ui;
	QTcpServer * server;
	QTcpSocket * socket;
	QTcpSocket * listSocket[1000];

	QSqlDatabase *db;
	QSqlQuery *query;

public slots: 
	void onServerNewConnection();
	void onClientDisconnected();
	void onClientReadyRead();
};
