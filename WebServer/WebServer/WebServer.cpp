#include "WebServer.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>
#include "database.h"

WebServer::WebServer(QWidget *parent)
    : QMainWindow(parent),
	m_pWebSocketServer(new QWebSocketServer(QStringLiteral("WebServer"),
		QWebSocketServer::NonSecureMode, this)),
	m_clients(), 
	m_debug()
{
    ui.setupUi(this);

	QObject::connect(m_pWebSocketServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
	m_pWebSocketServer->listen(QHostAddress::AnyIPv4, 168);

	// Connexion à la bdd
	bddMySQL = BaseDeDonnees::getInstance("QMYSQL");
	bddMySQL->connecter("projetQt", "superuser", "superuser", "192.168.65.10");
}

void WebServer::newConnection()
{
	ui.connectionStatusLabel->setText("Un client s'est connecté");

	QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
		
	QObject::connect(pSocket, &QWebSocket::textMessageReceived, this, &WebServer::processTextMessage);
	QObject::connect(pSocket, &QWebSocket::disconnected, this, &WebServer::socketDisconnected);

}

void WebServer::processTextMessage(QString message)
{
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

	QByteArray data = message.toUtf8();

	pClient->sendTextMessage(data);
}

void WebServer::processBinaryMessage(QByteArray message)
{
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

	//pClient->sendBinaryMessage(message);

}


// Déconnexion du client
void WebServer::socketDisconnected()
{
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

	m_clients.removeAll(pClient);
	pClient->deleteLater();
}
