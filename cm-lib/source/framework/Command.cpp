#include "Command.h"


namespace cm {
namespace framework {

class Command::Implementation {
public:
    Implementation(const QString& icon, const QString& desc, std::function<bool()> canExec):
        iconCharacter(icon), description(desc), canExecute(canExec) { }
    QString iconCharacter;
    QString description;
    std::function<bool()> canExecute;
};

Command::Command(QObject* parent, const QString& icon, const QString& desc, std::function<bool()> canExec): QObject(parent) {
    impl.reset(new Implementation(icon, desc, canExec));
}

Command::~Command() { }

const QString& Command::iconCharacter() const {
    return impl->iconCharacter;
}

const QString& Command::description() const {
    return impl->description;
}

bool Command::canExecute() const {
    return impl->canExecute();
}

} //framework
} //cm
