#include "tcpserver.h"
#include "database.h"

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

	// Connexion à la bdd
	bddMySQL = BaseDeDonnees::getInstance("QMYSQL");
	bddMySQL->connecter("projetQt", "superuser", "superuser", "192.168.65.10");


}

// Lorsqu'un client se connecte, on affiche le message un client s'est connecter et on se préparer à écouter ses messages ou déconnexion
void TcpServer::onServerNewConnection()
{
	ui.connectionStatusLabel->setText("Un client s'est connecté");

	QTcpSocket * client = server->nextPendingConnection();

	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::connect(client, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(sqlConnect()));
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
	//QString str = this->socket->readAll();
	QJsonDocument jsonResponse(QJsonDocument::fromJson(data));
	QJsonArray & array = jsonResponse.array();

	for (QJsonArray::iterator it = array.begin(); it != array.end(); it++)
	{
		if ((*it).isObject())
		{
			QJsonObject object = (*it).toObject();
			/*for (auto it = object.begin(); it != object.end(); it++)
			{
				qDebug() << (*it);
			}*/

			/*QString test = object.value("pseudo").toVariant().toString();
			if (test == "10")
			{
				ui.connectionStatusLabel->setText(test);
			}*/

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

				QString requete;
				requete = "INSERT INTO chat (text, heure, date, username) VALUES ('" + message + "', '" + heure + "', '" + date + "', '" + username + "')";
				retour = bddMySQL->executer(requete);

				if (retour == true) {
					obj->write("sendMsg.ok");
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

				QString requete;
				requete = "INSERT INTO user (username, password) VALUES ('" + username + "', '" + password + "')";
				retour = bddMySQL->executer(requete);

				if (retour == true)
				{
					obj->write("register.ok");
				}
				else {
					obj->write("register.error");
				}

			}

			if (method == "4") {
				// get message
				QString method = object.value("Method").toVariant().toString();
				QString username = object.value("username").toVariant().toString();

				QString requete;
				requete = "SELECT username FROM user WHERE username = '" + username + "'";
				QStringList values;
				retour = bddMySQL->recuperer(requete, values);

				if (retour == true) {
					// On peut récupèrer les chat
					obj->write("login.ok");
				}
			}
		}
	}
}