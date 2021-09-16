#include "WebServer.h"

WebServer::WebServer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	websocket = new WebServer(this);

	QObject::connect(websocket, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
	websocket->listen(QHostAddress::AnyIPv4, 178);
}

void WebServer::onServerNewConnection()
{

}
