#ifndef GPIOPINOUTPUT_H
#define GPIOPINOUTPUT_H
#include <QQuickItem>
#include <linux/types.h>

class GPIOPinOutput : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(GPIOPinOutput)
    Q_PROPERTY(int pin READ pin WRITE setPin)


public:
    explicit GPIOPinOutput(QQuickItem *parent = 0);
    ~GPIOPinOutput();
    int pin() const;
    void setPin(const int pin);
    Q_INVOKABLE int writeToPin(int val);
signals:
    
public slots:

private:
    int m_pin;

};

QML_DECLARE_TYPE(GPIOPinOutput)
#endif // GPIOPINOUTPUT_H
