#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include <QObject>
#include <QFile>
#include <QTextStream>

#define BRIGHTNESS "/sys/class/backlight/backlight.22/brightness"
#define BL_POWER "/sys/class/backlight/backlight.22/bl_power"

class Backlight : public QObject
{
    Q_OBJECT

public:
    explicit Backlight(QObject *parent = 0);
    ~Backlight();

    Q_INVOKABLE int brightness(void);
    Q_INVOKABLE void setBrightness(int duration);
    Q_INVOKABLE void enable(void);
    Q_INVOKABLE void disable(void);

private:
    QFile m_brightness_file;
    QFile m_backlight_file;
};

#endif
