
include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

QT += testlib
QT -= gui

CONFIG += qt warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += console
CONFIG += c++17
TEMPLATE = app

INCLUDEPATH += source
INCLUDEPATH += ../cm-lib/source

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

HEADERS += source/TestSuite.h \
    source/controllers/MasterControllerTests.h \
    source/data/DateTimeDecoratorTests.h \
    source/data/IntDecoratorTests.h \
    source/data/StringDecoratorTests.h \
    source/models/ClientTests.h

SOURCES += source/main.cpp \
            source/TestSuite.cpp \
            source/controllers/MasterControllerTests.cpp \
            source/data/DateTimeDecoratorTests.cpp \
            source/data/IntDecoratorTests.cpp \
            source/data/StringDecoratorTests.cpp \
            source/models/ClientTests.cpp
