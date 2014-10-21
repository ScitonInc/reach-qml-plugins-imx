#include "systemplugin.h"
#include "system.h"
#include "network.h"
#include "sqlite.h"
#include "upgrade.h"
#include "backlight.h"

#include <qqml.h>

void SystemPlugin::registerTypes(const char *uri)
{
    // @uri com.reachtech.systemplugin
    qmlRegisterType<System>(uri, 1, 0, "System");
    qmlRegisterType<Network>(uri, 1, 0, "Network");
    qmlRegisterType<SqLite>(uri, 1, 0, "SqLite");
    qmlRegisterType<Upgrade>(uri, 1, 0, "Upgrade");
    qmlRegisterType<Backlight>(uri, 1, 0, "Backlight");
}


