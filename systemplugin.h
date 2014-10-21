#ifndef SYSTEMPLUGIN_H
#define SYSTEMPLUGIN_H

#include <QQmlExtensionPlugin>

class SystemPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // SYSTEMPLUGIN_H

