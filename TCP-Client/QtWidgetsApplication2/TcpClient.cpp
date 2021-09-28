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
	//Au debut du code initalisation et connection au serveur.

}

void TcpCLient::connexion() //Connexion et verification coté serveur
{
	pseudo = ui.nom->text();
	QString port = ui.mdp->text();


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
void TcpCLient::onSocketConnected() //si la connection est aquise on écrit "connexion ok" dans la zone de texte
{
	ui.co->setText("Connexion Ok");

}

void TcpCLient::onSocketDisonnected()  //si l'user des deconnecter on écrit "déconnecté" dans la zone de texte
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
	ui.messagesend->setVisible(false);
}
void TcpCLient::messageserver() //cette fonction permet d'envoyer un message avec le nom d'utilisateur et le message sous format json
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
	}
	else
	{
		ui.messagesend->setText("message non envoye.");
	}


}
void TcpCLient::messagerecu()//cette fonction est importante, elle permet de recevoir les incformations donnée par le serveur et les trier.
{
	QByteArray data = socket->read(socket->bytesAvailable());
	QString str(data);
	if (init == 0) {
		if (str == "login.ok") {
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
			ui.labelinsc->setText("pseudo deja utilisé");
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
		ui.test->QTextEdit::clear();
	}

		

	else if (str == "sendMsg.error") {
		ui.test->insertPlainText("message non envoyer.");
	}
	else {
		ui.test->insertPlainText(str);
		ui.test->verticalScrollBar()->setValue(ui.test->verticalScrollBar()->maximum());
	}

}


void TcpCLient::incri() { //fonction qui permet de s'inscrire.
	pseudo = ui.nom->text();
	QString port = ui.mdp->text();


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



