#include "TcpClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	TcpCLient w;
    w.show();
    return a.exec();
}
