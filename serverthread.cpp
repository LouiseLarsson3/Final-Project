#include "serverthread.h"
//#include <QtNetwork/QTcpSocket>
//#include <QDebug>
//#include <qtcpserver.h>

//#define SERVER_PORT 8090

//serverThread::serverThread(QWidget *parent) :
//    QThread(parent),
//    running(false)
//{
//}

//void serverThread::run()
//{
//    QTcpServer server;
//    if (!server.listen(QHostAddress::Any, SERVER_PORT)) {
//        qDebug() << "Error: could not start server";
//        return;
//    }

//    qDebug() << "Server listening on port" << SERVER_PORT;

//    running = true;
//    while (running) {
//        if (server.hasPendingConnections()) {
//            QTcpSocket *client = server.nextPendingConnection();
//            connect(client, &QTcpSocket::readyRead, this, &serverThread::readData);
//            connect(client, &QTcpSocket::disconnected, client, &QTcpSocket::deleteLater);
//            qDebug() << "Client connected" << client->peerAddress().toString() << client->peerPort();
//        }
//    }

//    qDebug() << "Server stopped";
//}

//void serverThread::stop()
//{
//    running = false;
//}

//void serverThread::readData()
//{
//    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
//    if (!client) {
//        return;
//    }

//    while (client->bytesAvailable() > 0) {
//        QString data = QString::fromUtf8(client->readLine().trimmed());
//        qDebug() << "Received data:" << data;

//        // Extract the device ID, timestamp, and bird name from the data
//        QStringList parts = data.split(" ");
//        if (parts.size() != 3) {
//            qDebug() << "Error: invalid data format";
//            continue;
//        }
//        QString deviceID = parts[0];
//        QString timestamp = parts[1];
//        QString birdName = parts[2];

//        // Emit the received data to the GUI
//        emit recievedData(deviceID, timestamp, birdName);
//    }
//}
