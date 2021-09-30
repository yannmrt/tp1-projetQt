#include <QtWidgets/QMainWindow>
#include "ui_TcpServer.h"
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <QtSql/QtSql>
#include <iostream>
#include <QtWebSockets/QtWebSockets>

#include <QApplication>
#include "database.h"
#include <QDateTime>

class TcpServer : public QMainWindow
{
    Q_OBJECT

public:
	TcpServer(QWidget *parent = Q_NULLPTR);
	char requete;
	char retour;
	char donnees;

private:
    Ui::TcpServerClass ui;
	QTcpServer * server;
	QTcpSocket * socket;
	BaseDeDonnees *bddMySQL;
	QSqlDatabase *db;

public slots: 
	void onServerNewConnection();
	void onClientDisconnected();
	void onClientReadyRead();
};
