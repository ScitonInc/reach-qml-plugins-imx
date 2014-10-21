TEMPLATE = lib
TARGET = systemplugin
QT += qml quick
QT += sql
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.reachtech.systemplugin

# Input
SOURCES += \
    system.cpp \
    systemplugin.cpp \
    network.cpp \
    worker.cpp \
    upgrade.cpp \
    sqlite.cpp \
    backlight.cpp

HEADERS += \
    system.h \
    systemplugin.h \
    network.h \
    upgrade.h \
    sqlite.h \
    worker.h \
    backlight.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

