QT += testlib
QT -= gui

CONFIG += qt warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += console
CONFIG += c++17
TEMPLATE = app

INCLUDEPATH += source

SOURCES +=  source/models/tst_clientstests.cpp
