#include "backlight.h"

#include <QDebug>

Backlight::Backlight(QObject *parent) : QObject(parent)
    ,m_brightness_file(FULL_BRIGHTNESS)
    ,m_backlight_file(FULL_BL_POWER)
{
    // Check here if this is the correct kernel
    QDir dir(FULL_BACKLIGHT_PATH);

    if (!dir.exists()) {
        m_brightness_file.setFileName(BASE_BRIGHTNESS);
        m_backlight_file.setFileName(BASE_BL_POWER);
    }
}

Backlight::~Backlight()
{
    if(m_brightness_file.isOpen()) {
        m_brightness_file.close();
    }

    if(m_backlight_file.isOpen()) {
        m_backlight_file.close();
    }
}

void Backlight::setBrightness(int brightness)
{
    m_brightness_file.open(QIODevice::ReadWrite);
    QTextStream out(&m_brightness_file);

    out << QString::number(brightness).toLatin1() << endl;
    m_brightness_file.close();
}

int Backlight::brightness()
{
    m_brightness_file.open(QIODevice::ReadOnly);
    QTextStream in(&m_brightness_file);
    QString s = in.readLine();
    m_brightness_file.close();

    return s.toInt();
}

void Backlight::enable()
{
    m_backlight_file.open(QIODevice::ReadWrite);
    QTextStream out(&m_backlight_file);
    out << QString::number(0).toLatin1() << endl;
    m_backlight_file.close();
}

void Backlight::disable()
{
    m_backlight_file.open(QIODevice::ReadWrite);
    QTextStream out(&m_backlight_file);
    out << QString::number(1).toLatin1() << endl;
    m_backlight_file.close();
}
