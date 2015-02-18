#include "system.h"

System::System(QQuickItem *parent):
    QQuickItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

System::~System()
{
}

QDateTime System::currentDateTime(void)
{
    return QDateTime::currentDateTime();
}

bool System::setDate(int year, int month, int day)
{
    QDateTime d_cur(QDateTime::currentDateTime());
    QDate d_new(year,month,day);
    QString d_set;
    QProcess p(this);
    QString cmd(DATE_CMD);
    QStringList args;

    if (!d_new.isValid()) {
        return false;
    }

    d_set.append(d_new.toString(Qt::ISODate));
    d_set.append(" ");
    d_set.append(d_cur.time().toString());

    args << "-s" << d_set.toLatin1();

    qDebug() << "exec: " << cmd << " " << args;

    p.start(cmd,args);
    p.waitForFinished(1000);

    this->setHwClock();

    return true;
}

bool System::setTime(int hour, int minutes, int seconds)
{
    QDateTime t_cur(QDateTime::currentDateTime());
    QTime t_new(hour,minutes,seconds);
    QString t_set;
    QProcess p(this);
    QString cmd(DATE_CMD);
    QStringList args;

    if (!t_new.isValid()) {
        return false;
    }

    t_set.append(t_cur.date().toString(Qt::ISODate));
    t_set.append(" ");
    t_set.append(t_new.toString());

    args << "-s" << t_set.toLatin1();

    qDebug() << "exec: " << cmd << " " << args;

    p.start(cmd,args);
    p.waitForFinished(1000);

    this->setHwClock();

    return true;
}

bool System::setHwClock()
{
    QString cmd(HWCLOCK_CMD);
    QProcess p(this);
    QStringList args;

    args << "-w";

    qDebug() << "exec: " << cmd << " " << args;

    p.start(cmd, args);

    p.waitForFinished(1000);

    return true;
}

QString System::execute(QString command, QStringList args)
{
    QProcess p(this);

    qDebug() << "executing " << command << " with args " << args << "\n";

    p.start(command, args);

    QByteArray data;

    if (!p.waitForFinished())
    {
        data.append("Error: ").append(p.errorString());
        qDebug() << "Error: " << p.errorString();
    }
    else
        data.append(p.readAll());

   return QString::fromLatin1(data.data());

}

QString System::execute(QString command)
{
    QProcess p(this);
    p.setProcessChannelMode(QProcess::MergedChannels);

    qDebug() << "executing " << command << "\n";

    p.start(command);

    QByteArray data;

    while(p.waitForReadyRead())
        data.append(p.readAll());

    return QString::fromLatin1(data.data());

}

