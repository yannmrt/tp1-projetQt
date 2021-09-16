#include "tcpserver.h"

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
	QByteArray data = obj->read(obj->bytesAvailable());
	QString str(data);
	ui.connectionStatusLabel->setText("Message recu du client: " + str);
	obj->write(data);
}

void TcpServer::sqlConnect()
{
	BaseDeDonnees *bddMySQL = BaseDeDonnees::getInstance("QMYSQL");
	bddMySQL->connecter("projetQt", "superuser", "superuser", "192.168.65.10");
}