#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include <QObject>
#include <QtSql/QtSql>
#include <QSqlDatabase>
#include <QMutex>
#include <QString>

#define DEBUG_BASEDEDONNEES

#define BDD_HOSTNAME        "192.168.65.10"
#define BDD_USERNAME        "superuser"
#define BDD_PASSWORD        "superuser"

class BaseDeDonnees : public QObject
{
	Q_OBJECT
public:
	static BaseDeDonnees* getInstance(QString type = "QMYSQL");
	static void detruireInstance();

	bool estConnecte();
	bool connecter(QString nomBase, QString username = BDD_USERNAME, QString password = BDD_PASSWORD, QString serveur = BDD_HOSTNAME);
	bool estOuvert();
	bool ouvrir(QString fichierBase);

	/* uniquement pour : UPDATE, INSERT et DELETE */
	bool executer(QString requete);
	/* uniquement pour : SELECT */
	bool recuperer(QString requete, QString &donnees); // 1 -> 1
	bool recuperer(QString requete, QStringList &donnees); // 1 -> 1..*
	bool recuperer(QString requete, QVector<QString> &donnees); // 1..* -> 1
	bool recuperer(QString requete, QVector<QStringList> &donnees); // 1..* -> 1..*

private:
	BaseDeDonnees(QString type);
	~BaseDeDonnees();

	static BaseDeDonnees*  baseDeDonnees;
	static QString         typeBase;
	static int             nbAcces;

	QSqlDatabase           db;
	QMutex                 mutex;
};
#endif // BASEDEDONNEES_H