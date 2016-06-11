#include "ConnectionHandler.h"

ConnectionHandler::ConnectionHandler(QObject *parent) : QObject(parent),
    WebSocketServer(new QWebSocketServer(QStringLiteral("Mosp Server"),QWebSocketServer::NonSecureMode, this))
{

}

ConnectionHandler::~ConnectionHandler()
{
    WebSocketServer->close;
}

void ConnectionHandler::connectionRequest()
{
    QThread * thread = new QThread(this);
    QWebSocket * socket = WebSocketServer->nextPendingConnection();
    ClientHandler * client = new ClientHandler(socket,this);
    client->moveToThread(thread);
    QObject::connect(thread,SIGNAL(finished()),client,SLOT(deleteLater()));
    QObject::connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    QObject::connect(client,SIGNAL(socketDisconnected(QWebSocket*)),thread,SLOT(quit()));
    QObject::connect(client,SIGNAL(socketDisconnected(QWebSocket*)),this,SLOT(disconnection(QWebSocket*)));

    clients << socket;
}

void ConnectionHandler::disconnection(QWebSocket *socket)
{
    if(socket)
        clients.removeAll(socket);
}
