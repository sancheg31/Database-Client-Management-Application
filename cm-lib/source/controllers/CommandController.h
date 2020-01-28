#pragma once

#include <QObject>
#include <QtQml/QQmlListProperty>

#include "cm-lib_global.h"
#include "framework/Command.h"
#include "controllers/IDataBaseController.h"
#include "controllers/NavigationController.h"
#include "models/Client.h"
#include "models/ClientSearch.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT CommandController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands READ ui_createClientViewContextCommands CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommands READ ui_findClientViewContextCommands CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommands READ ui_editClientViewContextCommands CONSTANT)

public:
    explicit CommandController(QObject* _parent = nullptr, IDatabaseController* databaseController = nullptr, controllers::NavigationController* navigationController = nullptr, models::Client* newClient = nullptr, models::ClientSearch* clientSearch = nullptr);
    ~CommandController();

    QQmlListProperty<framework::Command> ui_createClientViewContextCommands();
    QQmlListProperty<framework::Command> ui_findClientViewContextCommands();
    QQmlListProperty<framework::Command> ui_editClientViewContextCommands();

public slots:
    void setSelectedClient(cm::models::Client* client);
    void onCreateClientSaveExecuted();
    void onFindClientSearchExecuted();
    void onEditClientSaveExecuted();
    void onEditClientDeleteExecuted();

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //controllers
} //cm



