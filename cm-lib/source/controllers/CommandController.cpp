#include "CommandController.h"

#include <QList>
#include <QDebug>

using namespace cm::framework;
using namespace cm::models;
using namespace cm::networking;

namespace cm {
namespace controllers {
class CommandController::Implementation
{
public:
    Implementation(CommandController* _commandController, IDatabaseController* _databaseController, INavigationController* _navigationController, Client* _newClient, ClientSearch* _clientSearch, IWebRequest* _rssWebRequest)
        : commandController(_commandController)
        , databaseController(_databaseController)
        , navigationController(_navigationController)
        , newClient(_newClient)
        , clientSearch(_clientSearch)
        , rssWebRequest(_rssWebRequest)
    {
        Command* createClientSaveCommand = new Command( commandController, QChar( 0xf0c7 ), "Save" );
        QObject::connect( createClientSaveCommand, &Command::executed, commandController, &CommandController::onCreateClientSaveExecuted );
        createClientViewContextCommands.append( createClientSaveCommand );

        Command* findClientSearchCommand = new Command( commandController, QChar( 0xf002 ), "Search" );
        QObject::connect( findClientSearchCommand, &Command::executed, commandController, &CommandController::onFindClientSearchExecuted );
        findClientViewContextCommands.append( findClientSearchCommand );

        Command* editClientDeleteCommand = new Command( commandController, QChar( 0xf235 ), "Delete" );
        QObject::connect( editClientDeleteCommand, &Command::executed, commandController, &CommandController::onEditClientDeleteExecuted );
        editClientViewContextCommands.append( editClientDeleteCommand );

        Command* editClientSaveCommand = new Command( commandController, QChar( 0xf0c7 ), "Save" );
        QObject::connect( editClientSaveCommand, &Command::executed, commandController, &CommandController::onEditClientSaveExecuted );
        editClientViewContextCommands.append( editClientSaveCommand );

        Command* rssRefreshCommand = new Command( commandController, QChar( 0xf021 ), "Refresh" );
        QObject::connect( rssRefreshCommand , &Command::executed, commandController, &CommandController::onRssRefreshExecuted );
        rssViewContextCommands.append( rssRefreshCommand  );
    }

    CommandController* commandController{nullptr};

    IDatabaseController* databaseController{nullptr};
    INavigationController* navigationController{nullptr};
    Client* newClient{nullptr};
    ClientSearch* clientSearch{nullptr};
    Client* selectedClient{nullptr};
    IWebRequest* rssWebRequest{nullptr};
    QList<Command*> createClientViewContextCommands{};
    QList<Command*> findClientViewContextCommands{};
    QList<Command*> editClientViewContextCommands{};
    QList<Command*> rssViewContextCommands{};
};

CommandController::CommandController(QObject* parent, IDatabaseController* databaseController, INavigationController* navigationController, Client* newClient, ClientSearch* clientSearch, IWebRequest* rssWebRequest)
    : ICommandController(parent)
{
    impl.reset(new Implementation(this, databaseController, navigationController, newClient, clientSearch, rssWebRequest));
}

CommandController::~CommandController()
{
}

QQmlListProperty<Command> CommandController::ui_createClientViewContextCommands()
{
    return QQmlListProperty<Command>(this, impl->createClientViewContextCommands);
}

QQmlListProperty<Command> CommandController::ui_findClientViewContextCommands()
{
    return QQmlListProperty<Command>(this, impl->findClientViewContextCommands);
}

QQmlListProperty<Command> CommandController::ui_editClientViewContextCommands()
{
    return QQmlListProperty<Command>(this, impl->editClientViewContextCommands);
}

QQmlListProperty<framework::Command> CommandController::ui_rssViewContextCommands()
{
    return QQmlListProperty<Command>(this, impl->rssViewContextCommands);
}

void CommandController::setSelectedClient(Client* client)
{
    impl->selectedClient = client;
}

void CommandController::onCreateClientSaveExecuted()
{
    qDebug() << "You executed the Save command!";

    impl->databaseController->createRow(impl->newClient->key(), impl->newClient->id(), impl->newClient->toJson());

    qDebug() << "New client saved.";

    impl->clientSearch->searchText()->setValue(impl->newClient->id());
    impl->clientSearch->search();
    impl->navigationController->goFindClientView();
    impl->newClient->setDefault();
}

void CommandController::onFindClientSearchExecuted()
{
    qDebug() << "You executed the Search command!";

    impl->clientSearch->search();
}

void CommandController::onEditClientSaveExecuted()
{
    qDebug() << "You executed the Save command!";

    impl->databaseController->updateRow(impl->selectedClient->key(), impl->selectedClient->id(), impl->selectedClient->toJson());

    qDebug() << "Updated client saved.";
}

void CommandController::onEditClientDeleteExecuted()
{
    qDebug() << "You executed the Delete command!";

    impl->databaseController->deleteRow(impl->selectedClient->key(), impl->selectedClient->id());
    impl->selectedClient = nullptr;

    qDebug() << "Client deleted.";

    impl->clientSearch->search();
    impl->navigationController->goDashboardView();
}

void CommandController::onRssRefreshExecuted()
{
    qDebug() << "You executed the RSS Refresh command!";
    impl->rssWebRequest->execute();
}

} //controllers
} //cm
