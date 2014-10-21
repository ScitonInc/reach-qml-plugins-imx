#ifndef NETWORK_H
#define NETWORK_H

#include <QQuickItem>
#include <QNetworkInterface>

class Network : public QQuickItem
{
    Q_OBJECT
public:
    explicit Network(QQuickItem *parent = 0);
    Q_INVOKABLE QString getIp(void);

private:
    QList<QHostAddress> m_ip_list;

};

#endif // NETWORK_H
