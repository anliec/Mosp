#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QtWebSockets/QtWebSockets>

class ClientHandler : public QObject
{
    Q_OBJECT
public:
    explicit ClientHandler(QWebSocket *webSocket,QObject *parent = 0);
    ~ClientHandler();

signals:
    void socketDisconnected(QWebSocket* socket);
private slots:
    void messageReceived(QString message);
    void sendMessage(QString message);

    void clientDisconnected();

private:
    QWebSocket* socket;
};

#endif // CLIENTHANDLER_H
