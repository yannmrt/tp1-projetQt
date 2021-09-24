#include <QtWidgets/QMainWindow>
#include "ui_WebServer.h"
#include "database.h"

#include <QtWebSockets/QtWebSockets>

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

#include <QtSql/QtSql>
#include <QApplication>
#include <QDateTime>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class WebServer : public QMainWindow
{
    Q_OBJECT

public:
    WebServer(QWidget *parent = Q_NULLPTR);
	char requete;
	char retour;
	char donnees;

private:
    Ui::WebServerClass ui;
	QWebSocketServer *m_pWebSocketServer;
	QList<QWebSocket *> m_clients;
	BaseDeDonnees *bddMySQL;
	bool m_debug;

public slots:
	void newConnection();
	void processTextMessage(QString message);
	void socketDisconnected();
};
