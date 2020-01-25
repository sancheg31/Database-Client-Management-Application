
#include "MasterController.h"
#include "NavigationController.h"

namespace cm {
namespace controllers {

class MasterController::Implementation
{
public:
    Implementation(MasterController* mc): masterController(mc) {
        navigationController = new NavigationController(masterController);
    }

    MasterController* masterController;
    NavigationController* navigationController;
    QString welcomeMessage = "This is MasterController";
};

MasterController::MasterController(QObject *parent) : QObject(parent) {
    impl.reset(new Implementation(this));
}

MasterController::~MasterController() {}

NavigationController* MasterController::navigationController() {
    return impl->navigationController;
}

const QString& MasterController::welcomeMessage() const {
    return impl->welcomeMessage;
}


} //controllers
} //cm


