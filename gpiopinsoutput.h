#ifndef GPIOPINSOUTPUT_H
#define GPIOPINSOUTPUT_H

#include <QQuickItem>
#include <linux/types.h>

class GPIOPinsOutput : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(GPIOPinsOutput)
public:
    explicit GPIOPinsOutput(QQuickItem *parent = 0);
    ~GPIOPinsOutput();
    Q_INVOKABLE int writeToPins(int val);
    
signals:
    
public slots:
    
};

QML_DECLARE_TYPE(GPIOPinsOutput)

#endif // GPIOPINSOUTPUT_H
