#include "ConnectionHandler.h"

#include <iostream>

ConnectionHandler::ConnectionHandler(quint16 port, QObject *parent) : QObject(parent),
    webSocketServer(new QWebSocketServer(QStringLiteral("Mosp Server"),QWebSocketServer::NonSecureMode, this))
{
    webSocketServer->listen(QHostAddress::Any, port);
    QObject::connect(webSocketServer,SIGNAL(newConnection()),this,SLOT(connectionRequest()));
}

ConnectionHandler::~ConnectionHandler()
{
    webSocketServer->close();
    qDeleteAll(clients.begin(),clients.end());
}

void ConnectionHandler::connectionRequest()
{
    std::cout << "connection !" << std::endl;
    //QThread * thread = new QThread(this);
    QWebSocket * socket = webSocketServer->nextPendingConnection();
    ClientHandler * client = new ClientHandler(socket);
    //client->moveToThread(thread);
    //QObject::connect(thread,SIGNAL(finished()),client,SLOT(deleteLater()));
    //QObject::connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    //QObject::connect(client,SIGNAL(socketDisconnected(QWebSocket*)),thread,SLOT(quit()));
    QObject::connect(client,SIGNAL(socketDisconnected(QWebSocket*)),this,SLOT(disconnection(QWebSocket*)));

    clients << socket;
}

void ConnectionHandler::disconnection(QWebSocket *socket)
{
    std::cout << "socket deleted from clients list" << std::endl;
    if(socket)
        clients.removeAll(socket);
}
