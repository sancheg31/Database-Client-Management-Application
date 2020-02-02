#pragma once

#include <QObject>
#include "framework/IObjectFactory.h"

namespace cm {
namespace framework {

class MockObjectFactory : public IObjectFactory
{
public:
    MockObjectFactory(){}

    models::Client* createClient(QObject* ) const override { return nullptr; }
    models::ClientSearch* createClientSearch(QObject* , controllers::IDatabaseController*) const override { return nullptr; }
    controllers::ICommandController* createCommandController(QObject* , controllers::IDatabaseController*, controllers::INavigationController* , models::Client* , models::ClientSearch* , networking::IWebRequest* ) const override { return nullptr; }
    controllers::IDatabaseController* createDatabaseController(QObject* ) const override { return nullptr; }
    controllers::INavigationController* createNavigationController(QObject* ) const override { return nullptr; }
    networking::INetworkAccessManager* createNetworkAccessManager(QObject* ) const override { return nullptr; }
    networking::IWebRequest* createWebRequest(QObject* , networking::INetworkAccessManager* , const QUrl& ) const override { return nullptr; }
};

}}
