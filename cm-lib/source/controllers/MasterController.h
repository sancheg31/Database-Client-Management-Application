#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include "cm-lib_global.h"
#include "ICommandController.h"
#include "IDatabaseController.h"
#include "INavigationController.h"
#include "framework/IObjectFactory.h"
#include "models/Client.h"
#include "models/ClientSearch.h"
#include "rss/RssChannel.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString ui_welcomeMessage READ welcomeMessage CONSTANT )
    Q_PROPERTY( cm::controllers::INavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY( cm::controllers::ICommandController* ui_commandController READ commandController CONSTANT )
    Q_PROPERTY( cm::controllers::IDatabaseController* ui_databaseController READ databaseController CONSTANT )
    Q_PROPERTY( cm::models::Client* ui_newClient READ newClient CONSTANT )
    Q_PROPERTY( cm::models::ClientSearch* ui_clientSearch READ clientSearch CONSTANT )
    Q_PROPERTY( cm::rss::RssChannel* ui_rssChannel READ rssChannel NOTIFY rssChannelChanged )

public:
    explicit MasterController(QObject* parent = nullptr, framework::IObjectFactory* objectFactory = nullptr);
    ~MasterController();

    ICommandController* commandController();
    IDatabaseController* databaseController();
    INavigationController* navigationController();
    models::Client* newClient();
    models::ClientSearch* clientSearch();
    rss::RssChannel* rssChannel();
    const QString& welcomeMessage() const;

public slots:
    void selectClient(cm::models::Client* client);
    void onRssReplyReceived(int statusCode, QByteArray body);

signals:
    void rssChannelChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //controllers
} //cm


