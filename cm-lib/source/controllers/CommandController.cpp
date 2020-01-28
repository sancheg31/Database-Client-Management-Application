#include "CommandController.h"

#include <QList>
#include <QDebug>

using namespace cm::framework;
using namespace cm::models;

namespace cm {
namespace controllers {

class CommandController::Implementation
{
public:
    Implementation(CommandController* _commandController, IDatabaseController* _databaseController, NavigationController* _navigationController, Client* _newClient, ClientSearch* _clientSearch)
        : commandController(_commandController)
        , databaseController(_databaseController)
        , navigationController(_navigationController)
        , newClient(_newClient)
        , clientSearch(_clientSearch)
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
    }

    CommandController* commandController{nullptr};

    IDatabaseController* databaseController{nullptr};
    NavigationController* navigationController{nullptr};
    Client* newClient{nullptr};
    ClientSearch* clientSearch{nullptr};
    Client* selectedClient{nullptr};
    QList<Command*> createClientViewContextCommands{};
    QList<Command*> findClientViewContextCommands{};
    QList<Command*> editClientViewContextCommands{};
};

CommandController::CommandController(QObject* parent, IDatabaseController* databaseController, NavigationController* navigationController, Client* newClient, ClientSearch* clientSearch)
    : QObject(parent)
{
    impl.reset(new Implementation(this, databaseController, navigationController, newClient, clientSearch));
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
} //controllers
} //cm
