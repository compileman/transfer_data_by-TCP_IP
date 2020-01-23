#include "local_client.h"
#include <QCoreApplication>
#include "ourdata.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int client_port_number = 9000;

    My_Local_Client My_Client( client_port_number );

    return a.exec();
}
