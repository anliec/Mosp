#include "ClientHandler.h"

#include <iostream>

ClientHandler::ClientHandler(QWebSocket *webSocket, QObject *parent):
    QObject(parent), socket(webSocket)
{
    std::cout << "creation" << std::endl;
    QObject::connect(socket,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));
    QObject::connect(socket,SIGNAL(textMessageReceived(QString)),this,SLOT(messageReceived(QString)));

    sendMessage("{ \"type\" : \"text\",\"content\":\"Welcome on Mosp server\" }");
}

ClientHandler::~ClientHandler()
{
    std::cout << "destruction" << std::endl;
    if(socket)
        socket->deleteLater();
}

void ClientHandler::clientDisconnected()
{
    std::cout << "client disconected: " << std::endl;
    emit socketDisconnected(socket);
}

void ClientHandler::messageReceived(QString message)
{
    std::cout << "message get: " << message.toStdString() << std::endl;
    if(message == "ping")
    {
        sendMessage("pong");
    }
    else
    {
        sendMessage("ping");
    }
}

void ClientHandler::sendMessage(QString message)
{
    std::cout << "message send: " << message.toStdString() << std::endl;
    socket->sendTextMessage(message);
}
