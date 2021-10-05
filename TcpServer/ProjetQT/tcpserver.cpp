#include "tcpserver.h"

//json specific
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>

TcpServer::TcpServer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	socket = new QTcpSocket(this);
	server = new QTcpServer(this);

	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
	server->listen(QHostAddress::AnyIPv4, 178);

}

// Lorsqu'un client se connecte, on affiche le message un client s'est connecter et on se préparer à écouter ses messages ou déconnexion
void TcpServer::onServerNewConnection()
{
	ui.connectionStatusLabel->setText("Un client s'est connecté");

	QTcpSocket * client = server->nextPendingConnection();

	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::connect(client, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));

	// On sauvegarde le client dans un nouveau tableau
	TcpServer::listSocket[sizeTable] = client;
	TcpServer::sizeTable++;
}

// Lorsque le client se déconnecter, on déconnecte le socket et on supprime l'objet
void TcpServer::onClientDisconnected()
{
	QTcpSocket * obj = qobject_cast<QTcpSocket*>(sender());

	QObject::disconnect(obj, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
	QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));

	ui.connectionStatusLabel->setText("Le client est déconnecter");
	obj->deleteLater();
}

// Lorsqu'un client envoi un message on affiche le message et on le lui renvoi
void TcpServer::onClientReadyRead()
{

	QTcpSocket * obj = qobject_cast<QTcpSocket*>(sender());
	obj->write("");

	QByteArray data = obj->read(obj->bytesAvailable());
	QString str(data);

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
				//ui.connectionStatusLabel->setText("Erreur de connexion à la bdd");
				ui.connectionStatusLabel->setText(db.lastError().text());
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

					if (query.size() > 0)
					{
						obj->write("login.ok");
					}
					else {
						obj->write("login.error");
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
						for (int i = 0; i < TcpServer::sizeTable; i++)
						{
							TcpServer::listSocket[i]->write(heureEncode + " " + usernameEncode + " : " + MessageEncode + "\n");

						}
					}
					else {
						obj->write("sendMsg.error");
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
							obj->write("register.ok");
						}
						else {
							obj->write("register.error");
						}

					}
					else {
						obj->write("register.error");
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
						/*QStringList values;
						retour = bddMySQL->recuperer(requete, values);*/
						retour = query.exec(requete);

						if (retour == true) {
							// Ici on va envoyer les messages au client au format JSON
							QSqlQuery query("SELECT text, heure, username FROM chat ORDER BY id ASC LIMIT 100");
							// for(/*initialisation*/ int i=1; /*condition*/ i<=10; /*incrémentation*/ ++i)
							while (query.next()) {
								QString text = query.value("text").toString();
								QString heure = query.value("heure").toString();
								QString username = query.value("username").toString();

								QString msgFinal = heure + " " + username + " : " + text + "\n";

								obj->write(msgFinal.toUtf8());

							}
						}
						else {
							obj->write("getMsg.error");
						}
					}
				}
			}
		}
	}
}