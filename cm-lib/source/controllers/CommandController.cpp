#include "CommandController.h"

#include <QList>
#include <QDebug>

using namespace cm::framework;


namespace cm {
namespace controllers {

class CommandController::Implementation
{
public:
    Implementation(CommandController* cc): commandController(cc) {
        Command* clientSaveCommand = new Command(commandController, QChar(0xf0c7), "Save");
        QObject::connect(clientSaveCommand, SIGNAL(executed()), commandController, SLOT(onCreateClientSaveExecuted()));
        clientViewContextCommands.append(clientSaveCommand);
    }
    CommandController* commandController;
    QList<Command*> clientViewContextCommands{};
};

CommandController::CommandController(QObject* parent): QObject(parent) {
    impl.reset(new Implementation(this));
}

CommandController::~CommandController() { }

QQmlListProperty<cm::framework::Command> CommandController::createClientViewContextCommands() {
    return QQmlListProperty<cm::framework::Command>(this, impl->clientViewContextCommands);
}

void CommandController::onCreateClientSaveExecuted() {
    qDebug() << "Save command executed";
}

} //controllers
} //cm
