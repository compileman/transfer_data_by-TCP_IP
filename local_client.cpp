#include "local_client.h"
#include <QDataStream>


My_Local_Client::~My_Local_Client(){

    delete local_client_info;
};


My_Local_Client::My_Local_Client( int port_number){

    ///класс-сокет
    obj_Server_TcpSocket = new QTcpSocket(this);

    ///current info
    local_client_info = new QString;

    obj_Server_TcpSocket->connectToHost( "127.0.0.1" , port_number );

    connect( obj_Server_TcpSocket, SIGNAL( connected() ) , SLOT( slotConnected() ) );

    connect( obj_Server_TcpSocket, SIGNAL( readyRead() ) , SLOT( slotReadyRead() ) );

    connect( obj_Server_TcpSocket , SIGNAL( error(QAbstractSocket::SocketError) ) ,
                   this,        SLOT( slotError( QAbstractSocket::SocketError ) )
           );

};


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

////test
void My_Local_Client::slotReadyRead()
{

    QDataStream in(obj_Server_TcpSocket);

    in.setVersion( QDataStream::Qt_5_7 );

    ///Считываем из сокета NextBlockSize:

    if ( !NextBlockSize ) {

                if ( this->obj_Server_TcpSocket->bytesAvailable() < (int)sizeof(quint16) ) {

                    return;
                }

        in >> NextBlockSize;
    };

     ///проверка корректности размера блока данных:
     if ( obj_Server_TcpSocket->bytesAvailable() < NextBlockSize ) {

                printf("Incorrect input stream: sizeof( stream ) < NextBlockSize ");
                return;
        }

       ///Тут из сокета сервера считываем время

       QTime time;
       in >> time;

       in >> binary_data;

};



// ----------------------------------------------------------------------
void My_Local_Client::slotError(QAbstractSocket::SocketError err)
{

    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(obj_Server_TcpSocket->errorString())
                    );
    local_client_info->append(strError);

};



// ----------------------------------------------------------------------
////Доделать,что именно отправлять в package серверу!!

void My_Local_Client::slotSendToServer( const QByteArray & binary_data )
{

    ///готовим пакет для записи в сокет :

    QByteArray  byte_package;

    QDataStream qt_out(  &byte_package , QIODevice::WriteOnly  );

    qt_out.setVersion( QDataStream::Qt_5_7 );

    qt_out << quint16(0) << QTime::currentTime() << byte_package ;

    qt_out.device()->seek(0);

    qt_out << quint16 ( byte_package.size() - sizeof(quint16) );

    //////////////////////////////////////////////////////////////////

    this->obj_Server_TcpSocket->write( byte_package );

}


// ------------------------------------------------------------------
void My_Local_Client::slotConnected()
{
    this->local_client_info->append("Received the connected() signal !\n");
}





