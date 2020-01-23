#ifndef LOCAL_CLIENT_H
#define LOCAL_CLIENT_H


#include <QTcpSocket>
#include <QTime>


class My_Local_Client: public QObject{

Q_OBJECT

private:

  QTcpSocket* obj_Server_TcpSocket;

  QString* local_client_info;

  QString txtInput;

  int NextBlockSize;

  QByteArray binary_data;

public:

 My_Local_Client( int port_number );
 ~My_Local_Client();

public slots:

    void slotSendToServer( const QByteArray& binary_data );
    void slotConnected();
    void slotReadyRead();
    void slotError( QAbstractSocket::SocketError err );

};


#endif // MY_LOCAL_CLIENT_H
