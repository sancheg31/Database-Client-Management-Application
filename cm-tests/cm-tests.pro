
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

SOURCES +=  source/models/tst_clientstests.cpp
