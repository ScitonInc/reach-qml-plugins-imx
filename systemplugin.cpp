#include "systemplugin.h"
#include "system.h"
#include "network.h"
#include "sqlite.h"
#include "upgrade.h"
#include "backlight.h"
#include "gpiopininput.h"
#include "gpiopinoutput.h"
#include "gpiopinsinput.h"
#include "gpiopinsoutput.h"
#include <qqml.h>

void SystemPlugin::registerTypes(const char *uri)
{
    // @uri com.reachtech.systemplugin
    qmlRegisterType<System>(uri, 1, 0, "System");
    qmlRegisterType<Network>(uri, 1, 0, "Network");
    qmlRegisterType<SqLite>(uri, 1, 0, "SqLite");
    qmlRegisterType<Upgrade>(uri, 1, 0, "Upgrade");
    qmlRegisterType<Backlight>(uri, 1, 0, "Backlight");
    qmlRegisterType<GPIOPinInput>(uri, 1, 0, "GPIOPinInput");
    qmlRegisterType<GPIOPinOutput>(uri, 1, 0, "GPIOPinOutput");
    qmlRegisterType<GPIOPinsInput>(uri, 1, 0, "GPIOPinsInput");
    qmlRegisterType<GPIOPinsOutput>(uri, 1, 0, "GPIOPinsOutput");
}


