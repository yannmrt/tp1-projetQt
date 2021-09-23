#include "TcpCLient.h"
#include <qtextedit.h>
#include <qscrollbar.h>
#include <QPixmap>

TcpCLient::TcpCLient(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisonnected()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(messagerecu()));
	socket->connectToHost( "192.168.65.230", 178);
	//socket->connectToHost("localhost", 178);
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
	pseudo = ui.nom->text();
	QString port = ui.mdp->text();

	/*socket->write(nom.toStdString().c_str());
	socket->write(":");
	socket->write(port.toStdString().c_str());

	QByteArray string = port.toStdString().c_str();
	QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Md4);
	hash->addData(string);
	QByteArray string1 = hash->result();*/

	QJsonObject levan{
{"Method",1},
{"username",pseudo},
{"password",port},
	};

	QJsonArray jsarray{ levan };
	QJsonDocument jsDoc(jsarray);

	QString jsString = QString::fromLatin1(jsDoc.toJson());

	socket->write(jsString.toLatin1());

}
void TcpCLient::onSocketConnected()
{
	ui.co->setText("Connexion Ok");
	//socket->write("test");

}

void TcpCLient::onSocketDisonnected()
{
	ui.co->setText("deconnecter");
	ui.nom->setVisible(false);
	ui.mdp->setVisible(false);
	ui.label_2->setVisible(false);
	ui.label_3->setVisible(false);
	ui.label->setVisible(false);
	ui.pushButton->setVisible(false);
	ui.lineEdit->setVisible(false);
	ui.pushButton_2->setVisible(false);
	ui.test->setVisible(false);
	ui.test2->setVisible(false);
	ui.insc->setVisible(false);
	ui.labelinsc->setVisible(false);
}
void TcpCLient::messageserver()
{
	if (socket->state() == QTcpSocket::ConnectedState)
	{
		ui.messagesend->setText("message envoye.");
		QString msg = ui.lineEdit->text();

		QJsonObject levan{
	{"Method",2},
	{"username",pseudo},
	{"message",msg},
		};

		QJsonArray jsarray{ levan };
		QJsonDocument jsDoc(jsarray);

		QString jsString = QString::fromLatin1(jsDoc.toJson());

		socket->write(jsString.toLatin1());
		ui.lineEdit->clear();
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
	QByteArray data = socket->read(socket->bytesAvailable());
	QString str(data);
	if (init == 0) {
		//ui.test->setText("message recu: " + str);
		if (str == "login.ok") {
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
			ui.insc->setVisible(false);
			ui.labelinsc->setVisible(false);
			init = 1;
			QJsonObject levan{
				{"Method",4},
			};

			QJsonArray jsarray{ levan };
			QJsonDocument jsDoc(jsarray);

			QString jsString = QString::fromLatin1(jsDoc.toJson());
			socket->write(jsString.toLatin1());
			
		}
		else if (str == "register.ok") {
			ui.labelinsc->setText("inscription reussis !");
		}

		else if (str == "register.error") {
			ui.labelinsc->setText("pseudo deja utilis�");
		}

		else if (str == "login.error") {
			ui.labelinsc->setText("login ou mot de passe incorrect !");
		}

		else
		{
			ui.test2->setText("erreur de connection");
		}
	}
	else if (str == "sendMsg.ok") {

		QJsonObject levan{
		{"Method",4},
		};

		QJsonArray jsarray{ levan };
		QJsonDocument jsDoc(jsarray);

		QString jsString = QString::fromLatin1(jsDoc.toJson());
		socket->write(jsString.toLatin1());
		//ui.test->insertPlainText("message envoyer + afficher le message avec le peudo");
		//ui.test->insertPlainText(str);
		ui.test->QTextEdit::clear();
	}

		

	else if (str == "sendMsg.error") {
		ui.test->insertPlainText("message non envoyer.");
	}
	else {
		//ui.test->insertPlainText("gros probleme");
		ui.test->insertPlainText(str);
		ui.test->verticalScrollBar()->setValue(ui.test->verticalScrollBar()->maximum());
	}

}


void TcpCLient::incri() {
	pseudo = ui.nom->text();
	QString port = ui.mdp->text();

	/*socket->write(nom.toStdString().c_str());
	socket->write(":");
	socket->write(port.toStdString().c_str());

	QByteArray string = port.toStdString().c_str();
	QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Md4);
	hash->addData(string);
	QByteArray string1 = hash->result();*/

	QJsonObject levan{
{"Method",3},
{"username",pseudo},
{"password",port},
	};

	QJsonArray jsarray{ levan };
	QJsonDocument jsDoc(jsarray);

	QString jsString = QString::fromLatin1(jsDoc.toJson());

	socket->write(jsString.toLatin1());

}





/*res["method"] = "login";
res["username"] = "username";
res["password"] = fkezfe;*/


/*
//debut

		QTcpSocket * socket = qobject_cast<QTcpSocket*>(sender());
		QByteArray data = socket->read(socket->bytesAvailable() < 64 ? 64 : socket->bytesAvailable());
		QString str(data);

		//QString str = this->socket->readAll();
		QJsonDocument jsonResponse(QJsonDocument::fromJson(data));
		QJsonArray & array = jsonResponse.array();

		for (QJsonArray::iterator it = array.begin(); it != array.end(); it++)
		{
			if ((*it).isObject())
			{
				QJsonObject object = (*it).toObject();


				QString method = object.value("Method").toVariant().toString();
				//1 = login / 2 = sendMessage / 3 = method
				

if (method == "2") {
	// Connexion de l'utilisateur
	QString method = object.value("Method").toVariant().toString();
	QString username = object.value("username").toVariant().toString();
	QString message = object.value("message").toVariant().toString();
	QString heure = object.value("heure").toVariant().toString();

	ui.test->insertPlainText(username + message + heure);


}
			}
		}

		//fin */