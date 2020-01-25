
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controllers/CommandController.h"
#include "controllers/MasterController.h"
#include "controllers/NavigationController.h"
#include "framework/Command.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM", 1, 0, "NavigationController");
    qmlRegisterType<cm::controllers::CommandController>("CM", 1, 0, "CommandController");
    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");
    cm::controllers::MasterController masterController;
    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/assets/");
    engine.addImportPath("qrc:/components/");
    engine.rootContext()->setContextProperty("masterController", &masterController);
    engine.load(QUrl(QStringLiteral("qrc:/views/MasterView.qml")));

    //engine.load(QUrl(QStringLiteral("qrc:/views/AnchorsDemo.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/views/SizingDemo.qml")));
    /*сonst QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);*/

    return app.exec();
}

