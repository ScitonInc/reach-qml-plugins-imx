#ifndef SYSTEM_H
#define SYSTEM_H

#include <QQuickItem>
#include <QTime>
#include <QProcess>
#include <QDebug>

#define DATE_CMD "/bin/date"
#define HWCLOCK_CMD "/sbin/hwclock"

class System : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(System)

public:
    System(QQuickItem *parent = 0);
    ~System();

    Q_INVOKABLE QDateTime currentDateTime(void);
    Q_INVOKABLE bool setDate(int year, int month, int day);
    Q_INVOKABLE bool setTime(int hour, int minutes, int seconds);
    Q_INVOKABLE QString execute(QString command, QStringList args);
    Q_INVOKABLE QString execute(QString command);
    Q_INVOKABLE QString shell(QString command);
    Q_INVOKABLE QString getSoftwareVersion();

private slots:
    bool setHwClock(void);
};

#endif // SYSTEM_H

