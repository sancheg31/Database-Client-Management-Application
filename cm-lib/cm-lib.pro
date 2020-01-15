
QT -= gui


TARGET = cm-lib
TEMPLATE = lib

CONFIG += c++17

DEFINES += CMLIB_LIBRARY

INCLUDEPATH += source

SOURCES += \
    source/models/Client.cpp

HEADERS += \
    source/cm-lib_global.h \
    source/models/Client.h

TRANSLATIONS += \
    cm-lib_en_US.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}

!isEmpty(target.path): INSTALLS += target
