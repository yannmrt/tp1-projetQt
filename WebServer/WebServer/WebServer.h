#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WebServer.h"

#include <QtWebSockets/QtWebSockets>
#include <QTcpSocket>

#include <QtSql/QtSql>
#include <QApplication>

class WebServer : public QMainWindow
{
    Q_OBJECT

public:
    WebServer(QWidget *parent = Q_NULLPTR);

private:
    Ui::WebServerClass ui;
	WebServer *websocket;

public slots:
	void onServerNewConnection();
};
