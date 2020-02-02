#pragma once

#include <QObject>
#include <QtQml/QQmlListProperty>

#include "cm-lib_global.h"
#include "framework/Command.h"
#include "controllers/IDataBaseController.h"
#include "controllers/NavigationController.h"
#include "controllers/ICommandController.h"
#include "models/Client.h"
#include "models/ClientSearch.h"
#include "networking/IWebRequest.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT CommandController : public ICommandController
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands READ ui_createClientViewContextCommands CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommands READ ui_findClientViewContextCommands CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommands READ ui_editClientViewContextCommands CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_rssViewContextCommands READ ui_rssViewContextCommands CONSTANT)

public:
    explicit CommandController(QObject* _parent = nullptr, IDatabaseController* databaseController = nullptr, controllers::INavigationController* navigationController = nullptr, models::Client* newClient = nullptr, models::ClientSearch* clientSearch = nullptr, networking::IWebRequest* rssWebRequest = nullptr);
    ~CommandController();

    QQmlListProperty<framework::Command> ui_createClientViewContextCommands() override;
    QQmlListProperty<framework::Command> ui_findClientViewContextCommands() override;
    QQmlListProperty<framework::Command> ui_editClientViewContextCommands() override;
    QQmlListProperty<framework::Command> ui_rssViewContextCommands() override;

public slots:
    void setSelectedClient(cm::models::Client* client) override;
    void onCreateClientSaveExecuted() override;
    void onFindClientSearchExecuted() override;
    void onEditClientSaveExecuted() override;
    void onEditClientDeleteExecuted() override;
    void onRssRefreshExecuted() override;

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //controllers
} //cm



