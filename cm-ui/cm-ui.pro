
include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)


DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

QT += quick
QT += qml

CONFIG += c++17

INCLUDEPATH += source
INCLUDEPATH += views
INCLUDEPATH += ../cm-lib/source
SOURCES += \
        source/main.cpp

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

RESOURCES += qml.qrc \
    assets.qrc \
    components.qrc

TRANSLATIONS += \
    cm-ui_en_US.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/Style.qml \
    assets/fontawesome.ttf \
    components.qml \
    components/CommandBar.qml \
    components/NavigationBar.qml \
    components/CommandButton.qml \
    components/NavigationButton.qml \
    views/DashboardView.qml \
    views/EditClientView.qml \
    views/FindClientView.qml \
    views/SplashView.qml \
    views/CreateClientView.qml \
    views/AnchorsDemo.qml \
    views/SizingDemo.qml \
    views/MasterView.qml \
    assets/qmldir \
    components/qmldir \
