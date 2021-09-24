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

			if (method == "1") {
				// Connexion de l'utilisateur
				QString method = object.value("Method").toVariant().toString();
				QString username = object.value("username").toVariant().toString();
				QString password = object.value("password").toVariant().toString();

				QString requete;
				requete = "SELECT username, password FROM user WHERE username = '" + username + "' AND password='" + password + "'";
				QStringList values;
				retour = bddMySQL->recuperer(requete, values);

				if (retour == true) {
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

				QString requete;
				requete = "INSERT INTO chat (text, heure, date, username) VALUES ('" + message + "', '" + heure + "', '" + date + "', '" + username + "')";
				retour = bddMySQL->executer(requete);

				if (retour == true) {
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

				QString requete;
				requete = "INSERT INTO user (username, password) VALUES ('" + username + "', '" + password + "')";
				retour = bddMySQL->executer(requete);

				if (retour == true)
				{
					pClient->sendTextMessage("register.ok");
				}
				else {
					pClient->sendTextMessage("register.error");
				}
			}

			if (method == "4") {
				// get message
				QString method = object.value("Method").toVariant().toString();
				QString username = object.value("username").toVariant().toString();

				QString requete;
				/*requete = "SELECT * FROM user WHERE username = '" + username + "'";
				QStringList values;
				retour = bddMySQL->recuperer(requete, values);*/

				QString retour = true;

				if (retour == true) {
					// On peut récupèrer les chat
					requete = "SELECT text, heure, username FROM chat ORDER BY id ASC";
					QStringList values;
					retour = bddMySQL->recuperer(requete, values);

					if (retour == true) {
						// Ici on va envoyer les messages au client au format JSON
						QSqlQuery query("SELECT text, heure, username FROM chat ORDER BY id ASC");
						// for(/*initialisation*/ int i=1; /*condition*/ i<=10; /*incrémentation*/ ++i)
						while (query.next()) {
							QString text = query.value("text").toString();
							QString heure = query.value("heure").toString();
							QString username = query.value("username").toString();

							/*QJsonObject levan{
								{"Method",2},
								{"username",username},
								{"message",text},
								{"heure",heure},
							};
							QJsonArray jsarray{ levan };
							QJsonDocument jsDoc(jsarray);
							QString jsString = QString::fromLatin1(jsDoc.toJson());
							obj->write(jsString.toLatin1());*/
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

// Déconnexion du client
void WebServer::socketDisconnected()
{
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

	m_clients.removeAll(pClient);
	pClient->deleteLater();
}
