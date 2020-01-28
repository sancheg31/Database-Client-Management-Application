

#include "MasterController.h"
#include "NavigationController.h"
#include "DatabaseController.h"

#include "models/Client.h"
#include "models/ClientSearch.h"

using namespace cm::models;

namespace cm {
namespace controllers {

class MasterController::Implementation
{
public:
    Implementation(MasterController* mc) : masterController(mc) {
        databaseController = new DatabaseController(masterController);
        navigationController = new NavigationController(masterController);
        newClient = new Client(masterController);
        clientSearch = new ClientSearch(masterController, databaseController);
        commandController = new CommandController(masterController, databaseController, navigationController, newClient, clientSearch);
    }

    MasterController* masterController{nullptr};
    CommandController* commandController{nullptr};
    DatabaseController* databaseController{nullptr};
    NavigationController* navigationController{nullptr};
    Client* newClient{nullptr};
    ClientSearch* clientSearch{nullptr};
    QString welcomeMessage = "Welcome to the Client Management system!";
};

MasterController::MasterController(QObject* parent): QObject(parent) {
    impl.reset(new Implementation(this));
}

MasterController::~MasterController() { }

CommandController* MasterController::commandController() {
    return impl->commandController;
}

DatabaseController* MasterController::databaseController() {
    return impl->databaseController;
}

NavigationController* MasterController::navigationController() {
    return impl->navigationController;
}

Client* MasterController::newClient() {
    return impl->newClient;
}

ClientSearch* MasterController::clientSearch() {
    return impl->clientSearch;
}

const QString& MasterController::welcomeMessage() const {
    return impl->welcomeMessage;
}

void MasterController::selectClient(Client* client) {
    impl->navigationController->goEditClientView(client);
}


} //controllers
} //cm


