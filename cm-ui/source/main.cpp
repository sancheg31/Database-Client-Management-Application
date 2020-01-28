#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controllers/MasterController.h"
#include "controllers/CommandController.h"
#include "controllers/NavigationController.h"
#include "data/DateTimeDecorator.h"
#include "data/EnumeratorDecorator.h"
#include "data/IntDecorator.h"
#include "data/StringDecorator.h"
#include "data/DropDown.h"
#include "data/DropDownValue.h"
#include "framework/Command.h"
#include "models/Address.h"
#include "models/Appointment.h"
#include "models/Client.h"
#include "models/ClientSearch.h"
#include "models/Contact.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM", 1, 0, "NavigationController");
    qmlRegisterType<cm::controllers::CommandController>("CM", 1, 0, "CommandController");

    qmlRegisterType<cm::data::DateTimeDecorator>("CM", 1, 0, "DateTimeDecorator");
    qmlRegisterType<cm::data::EnumeratorDecorator>("CM", 1, 0, "EnumeratorDecorator");
    qmlRegisterType<cm::data::IntDecorator>("CM", 1, 0, "IntDecorator");
    qmlRegisterType<cm::data::StringDecorator>("CM", 1, 0, "StringDecorator");
    qmlRegisterType<cm::data::DropDown>("CM", 1, 0, "DropDown");
    qmlRegisterType<cm::data::DropDownValue>("CM", 1, 9, "DropDownValue");

    qmlRegisterType<cm::models::Address>("CM", 1, 0, "Address");
    qmlRegisterType<cm::models::Appointment>("CM", 1, 0, "Appointment");
    qmlRegisterType<cm::models::Client>("CM", 1, 0, "Client");
    qmlRegisterType<cm::models::ClientSearch>("CM", 1, 0, "ClientSearch");
    qmlRegisterType<cm::models::Contact>("CM", 1, 0, "Contact");

    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");

    cm::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/assets");
    engine.addImportPath("qrc:/components");
    engine.rootContext()->setContextProperty("masterController", &masterController);
    engine.load(QUrl(QStringLiteral("qrc:/views/MasterView.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
