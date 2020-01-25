
include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

QT -= gui

TARGET = cm-lib
TEMPLATE = lib

CONFIG += c++17

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui
message(cm-lib output dir: $${DESTDIR})

DEFINES += CMLIB_LIBRARY

INCLUDEPATH += source

SOURCES += \
    source/controllers/CommandController.cpp \
    source/controllers/MasterController.cpp \
    source/framework/Command.cpp \
    source/models/Client.cpp

HEADERS += \
    source/cm-lib_global.h \
    source/controllers/CommandController.h \
    source/controllers/MasterController.h \
    source/controllers/NavigationController.h \
    source/framework/Command.h \
    source/models/Client.h

TRANSLATIONS += \
    cm-lib_en_US.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}

!isEmpty(target.path): INSTALLS += target

message(cm-lib project dir: $${PWD})
