#include "ClientHandler.h"

ClientHandler::ClientHandler(QWebSocket *webSocket, QObject *parent):
    QObject(parent), socket(webSocket)
{
    QObject::connect(socket,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));
    QObject::connect(socket,SIGNAL(textMessageReceived(QString)),this,SLOT(messageReceived(QString)));
}

ClientHandler::~ClientHandler()
{
    if(socket)
        socket->deleteLater();
}

void ClientHandler::clientDisconnected()
{
    emit socketDisconnected(socket);
}

void ClientHandler::messageReceived(QString message)
{
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
    socket->sendTextMessage(message);
}
