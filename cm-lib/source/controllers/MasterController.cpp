

#include "MasterController.h"
#include "networking/NetworkAccessManager.h"
#include "networking/WebRequest.h"

#include "models/Client.h"
#include "models/ClientSearch.h"

using namespace cm::models;
using namespace cm::networking;
using namespace cm::framework;
using namespace cm::rss;

namespace cm {
namespace controllers {

class MasterController::Implementation
{
public:
    Implementation(MasterController* _masterController, IObjectFactory* _objectFactory)
        : masterController(_masterController)
        , objectFactory(_objectFactory)
    {
        databaseController = objectFactory->createDatabaseController(masterController);
        clientSearch = objectFactory->createClientSearch(masterController, databaseController);
        navigationController = objectFactory->createNavigationController(masterController);
        networkAccessManager = objectFactory->createNetworkAccessManager(masterController);
        rssWebRequest = objectFactory->createWebRequest(masterController, networkAccessManager, QUrl("http://feeds.bbci.co.uk/news/world/rss.xml"));
        QObject::connect(rssWebRequest, &IWebRequest::requestComplete, masterController, &MasterController::onRssReplyReceived);
        newClient = objectFactory->createClient(masterController);
        commandController = objectFactory->createCommandController(masterController, databaseController, navigationController, newClient, clientSearch, rssWebRequest);
    }

    MasterController* masterController{nullptr};
    IObjectFactory* objectFactory{nullptr};
    ICommandController* commandController{nullptr};
    IDatabaseController* databaseController{nullptr};
    INavigationController* navigationController{nullptr};
    Client* newClient{nullptr};
    ClientSearch* clientSearch{nullptr};
    INetworkAccessManager* networkAccessManager{nullptr};
    IWebRequest* rssWebRequest{nullptr};
    RssChannel* rssChannel{nullptr};
    QString welcomeMessage = "Welcome to the Client Management system!";
};

MasterController::MasterController(QObject* parent, IObjectFactory* objectFactory)
    : QObject(parent)
{
    impl.reset(new Implementation(this, objectFactory));
}

MasterController::~MasterController()
{
}

ICommandController* MasterController::commandController()
{
    return impl->commandController;
}

IDatabaseController* MasterController::databaseController()
{
    return impl->databaseController;
}

INavigationController* MasterController::navigationController()
{
    return impl->navigationController;
}

Client* MasterController::newClient()
{
    return impl->newClient;
}

ClientSearch* MasterController::clientSearch()
{
    return impl->clientSearch;
}

RssChannel* MasterController::rssChannel()
{
    return impl->rssChannel;
}

const QString& MasterController::welcomeMessage() const
{
    return impl->welcomeMessage;
}

void MasterController::selectClient(Client* client)
{
    impl->navigationController->goEditClientView(client);
}

void MasterController::onRssReplyReceived(int statusCode, QByteArray body)
{
    qDebug() << "Received RSS request response code " << statusCode << ":";
    qDebug() << body;

    if(impl->rssChannel) {
        impl->rssChannel->deleteLater();
        impl->rssChannel = nullptr;
        emit rssChannelChanged();
    }

    impl->rssChannel = RssChannel::fromXml(body, this);
    emit rssChannelChanged();
}


} //controllers
} //cm


