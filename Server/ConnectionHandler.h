#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <QObject>
#include <QtWebSockets/QtWebSockets>

#include "ClientHandler.h"

class ConnectionHandler : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionHandler(quint16 port, QObject *parent = 0);
    ~ConnectionHandler();
signals:

public slots:
    void connectionRequest();
    void disconnection(QWebSocket * socket);

private:
    QList<QWebSocket*> clients;
    QWebSocketServer *webSocketServer;
};

#endif // CONNECTIONHANDLER_H
