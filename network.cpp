#include "network.h"
#include <QDebug>

Network::Network(QQuickItem *parent) :
    QQuickItem(parent)
{
     m_ip_list = QNetworkInterface::allAddresses();
}

QString Network::getIp()
{
    foreach(QHostAddress ip, m_ip_list) {
        qDebug() << ip.toString();
        if(ip != ip.LocalHost && ip.protocol() == QAbstractSocket::IPv4Protocol) {
            qDebug() << "returning: " << ip.toString();
            return ip.toString();
        }
    }

    qDebug() << "returning: localhost";
    return "127.0.0.1";
}
