#include "TcpCLient.h"

TcpCLient::TcpCLient(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisonnected()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(messagerecu()));
	socket->connectToHost( "192.168.65.230", 178);
	ui.lineEdit->setVisible(false);
	ui.pushButton_2->setVisible(false);
	ui.test->setVisible(false);




	/*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.65.83");
	db.setUserName("lowrance");
	db.setPassword("azerty");
	db.setDatabaseName("Lawrence");
	if (db.open())
	{
		ui.SQL->setText("co");
	}
	else
	{
		ui.SQL->setText("pasco");
	}*/

}

void TcpCLient::connexion()
{
	QString nom = ui.nom->text();
	QString port = ui.mdp->text();

	/*socket->write(nom.toStdString().c_str());
	socket->write(":");
	socket->write(port.toStdString().c_str());*/

	QJsonObject levan{
{"login",nom},
{"mot de passe",port},
	};

	QJsonArray jsarray{ levan };
	QJsonDocument jsDoc(jsarray);

	QString jsString = QString::fromLatin1(jsDoc.toJson());

	socket->write(jsString.toLatin1());

}
void TcpCLient::onSocketConnected()
{
	ui.co->setText("Connexion Ok");
	socket->write("test");

}

void TcpCLient::onSocketDisonnected()
{
	ui.co->setText("deconnecter");
}
void TcpCLient::messageserver()
{
	if (socket->state() == QTcpSocket::ConnectedState)
	{
		ui.messagesend->setText("message envoye.");
		QString msg = ui.lineEdit->text();

		QJsonObject levan{
	{"pseudo",10},
	{"message",msg},
		};

		QJsonArray jsarray{ levan };
		QJsonDocument jsDoc(jsarray);

		QString jsString = QString::fromLatin1(jsDoc.toJson());

		socket->write(jsString.toLatin1());
		//socket->write(documentJSON);
		//socket->write(msg.toStdString().c_str());
	}
	else
	{
		ui.messagesend->setText("message non envoye.");
		//ui.test->setText("message recu: " + str);
	}


}
void TcpCLient::messagerecu()
	{
	if (init == 0) {
		QByteArray data = socket->read(socket->bytesAvailable());
		QString str(data);
		//ui.test->setText("message recu: " + str);
		if (str == "ok") {
			//ui.test->setText("message recu: " + str);
			ui.nom->setVisible(false);
			ui.mdp->setVisible(false);
			ui.label_2->setVisible(false);
			ui.label_3->setVisible(false);
			ui.label->setVisible(false);
			ui.pushButton->setVisible(false);
			ui.lineEdit->setVisible(true);
			ui.pushButton_2->setVisible(true);
			ui.test->setVisible(true);
			ui.test2->setVisible(false);
			init = 1;
		}
		else
		{
			ui.test2->setText("erreur de connection");
		}
	}
	else{
		QByteArray data = socket->read(socket->bytesAvailable());
		QString str(data);
		ui.test->insertPlainText("*pseudo*: " + str + "\n");
	}
	}


/*res["method"] = "login";
res["username"] = "username";
res["password"] = fkezfe;*/