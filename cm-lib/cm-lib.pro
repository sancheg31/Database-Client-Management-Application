
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
    source/data/DataDecorator.cpp \
    source/data/DateTimeDecorator.cpp \
    source/data/Entity.cpp \
    source/data/EntityCollection.cpp \
    source/data/EntityCollectionBase.cpp \
    source/data/EntityCollectionObject.cpp \
    source/data/EnumeratorDecorator.cpp \
    source/data/IntDecorator.cpp \
    source/data/StringDecorator.cpp \
    source/controllers/CommandController.cpp \
    source/controllers/MasterController.cpp \
    source/framework/Command.cpp \
    source/models/Address.cpp \
    source/models/Appointment.cpp \
    source/models/Client.cpp \
    source/models/Contact.cpp

HEADERS += \
    source/data/DataDecorator.h \
    source/data/DateTimeDecorator.h \
    source/data/Entity.h \
    source/data/EntityCollection.h \
    source/data/EntityCollectionBase.h \
    source/data/EntityCollectionObject.h \
    source/data/EnumeratorDecorator.h \
    source/data/IntDecorator.h \
    source/data/StringDecorator.h \
    source/cm-lib_global.h \
    source/controllers/CommandController.h \
    source/controllers/MasterController.h \
    source/controllers/NavigationController.h \
    source/framework/Command.h \
    source/models/Address.h \
    source/models/Appointment.h \
    source/models/Client.h \
    source/models/Contact.h

TRANSLATIONS += \
    cm-lib_en_US.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}

!isEmpty(target.path): INSTALLS += target

message(cm-lib project dir: $${PWD})
