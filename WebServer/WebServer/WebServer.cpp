#include "WebServer.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>

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

}

void WebServer::newConnection()
{
	ui.connectionStatusLabel->setText("Un client s'est connecté");

	QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
		
	QObject::connect(pSocket, &QWebSocket::textMessageReceived, this, &WebServer::processTextMessage);
	QObject::connect(pSocket, &QWebSocket::binaryMessageReceived, this, &WebServer::processBinaryMessage);
	QObject::connect(pSocket, &QWebSocket::disconnected, this, &WebServer::socketDisconnected);

	// On sauvegarde le client dans un nouveau tableau
	WebServer::m_clients[sizeTable] = pSocket;
	WebServer::sizeTable++;

}

void WebServer::processTextMessage(QString message)
{
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

	QByteArray data = message.toUtf8();

	QJsonDocument jsonResponse(QJsonDocument::fromJson(data));
	QJsonArray & array = jsonResponse.array();

	for (QJsonArray::iterator it = array.begin(); it != array.end(); it++)
	{
		if ((*it).isObject())
		{
			QJsonObject object = (*it).toObject();

			QString method = object.value("Method").toVariant().toString();
			/*  1 = login / 2 = sendMessage / 3 = method
			*/

			// Connexion à la base de données
			QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
			db.setHostName("192.168.65.10");
			db.setUserName("superuser");
			db.setPassword("superuser");
			db.setDatabaseName("projetQt");

			if (!db.open()) {
				ui.connectionStatusLabel->setText("La connexion à la base de donnée à échouée.");
			}
			else {

				QSqlQuery query(db);

				if (method == "1") {
					// Connexion de l'utilisateur
					QString method = object.value("Method").toVariant().toString();
					QString username = object.value("username").toVariant().toString();
					QString password = object.value("password").toVariant().toString();

					QString requete = "SELECT username, password FROM user WHERE username = '" + username + "' AND password='" + password + "'";
					retour = query.exec(requete);

					if (query.size() > 0) {
						pClient->sendTextMessage("login.ok");
					}
					else {
						pClient->sendTextMessage("login.error");
					}


				}

				if (method == "2") {
					// send message
					//requete = "SELECT temperature FROM mesures ORDER BY heure ASC";
					QString method = object.value("Method").toVariant().toString();
					QString username = object.value("username").toVariant().toString();
					QString message = object.value("message").toVariant().toString();

					QString date = QDateTime::currentDateTime().toString("dd MMMM yyyy");
					QString heure = QDateTime::currentDateTime().toString("hh:mm:ss");

					QString requete = "INSERT INTO chat (text, heure, date, username) VALUES ('" + message + "', '" + heure + "', '" + date + "', '" + username + "')";
					retour = query.exec(requete);

					if (retour) {
						QByteArray heureEncode = heure.toUtf8();
						QByteArray usernameEncode = username.toUtf8();
						QByteArray MessageEncode = message.toUtf8();
						for (int i = 0; i < WebServer::sizeTable; i++)
						{
							WebServer::m_clients[i]->sendTextMessage(heureEncode + " " + usernameEncode + " : " + MessageEncode + "\n");

						}

						pClient->sendTextMessage("sendMsg.ok");
					}
					else {
						pClient->sendTextMessage("sendMsg.error");
					}


				}

				if (method == "3") {
					// Inscription
					QString method = object.value("Method").toVariant().toString();
					QString username = object.value("username").toVariant().toString();
					QString password = object.value("password").toVariant().toString();

					QString requete = "SELECT username FROM user WHERE username = '" + username + "'";
					retour = query.exec(requete);

					if (query.size() == 0) {

						QString requete = "INSERT INTO user (username, password) VALUES ('" + username + "', '" + password + "')";
						retour = query.exec(requete);

						if (retour)
						{
							pClient->sendTextMessage("register.ok");
						}
						else {
							pClient->sendTextMessage("register.error");
						}

					}
					else {
						pClient->sendTextMessage("register.error");
					}
				}

				if (method == "4") {
					// get message
					QString method = object.value("Method").toVariant().toString();
					QString username = object.value("username").toVariant().toString();

					QString retour = true;

					if (retour == true) {
						// On peut récupèrer les chat
						QString requete = "SELECT text, heure, username FROM chat ORDER BY id ASC";
						retour = query.exec(requete);

						if (retour == true) {
							// Ici on va envoyer les messages au client au format JSON
							QSqlQuery query("SELECT text, heure, username FROM chat ORDER BY id ASC LIMIT 100");
							// for(/*initialisation*/ int i=1; /*condition*/ i<=10; /*incrémentation*/ ++i)
							while (query.next()) {
								QString text = query.value("text").toString();
								QString heure = query.value("heure").toString();
								QString username = query.value("username").toString();

								QString msgFinal = heure + " " + username + " : " + text;

								pClient->sendTextMessage(msgFinal.toUtf8());

							}
						}
						else {
							pClient->sendTextMessage("getMsg.error");
						}
					}
				}
		    }
		}
	}
}

void WebServer::processBinaryMessage() {
}

// Déconnexion du client
void WebServer::socketDisconnected()
{
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

	m_clients.removeAll(pClient);
	pClient->deleteLater();
}
