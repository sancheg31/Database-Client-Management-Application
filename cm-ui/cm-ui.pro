QT += quick
QT += qml

CONFIG += c++17

INCLUDEPATH += source
INCLUDEPATH += views
SOURCES += \
        source/main.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    cm-ui_en_US.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
