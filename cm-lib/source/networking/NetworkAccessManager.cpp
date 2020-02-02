#include "NetworkAccessManager.h"

#include <QNetworkAccessManager>

namespace cm {
namespace networking {

class NetworkAccessManager::Implementation
{
public:
    Implementation() {}
    QNetworkAccessManager networkAccessManager;
};

NetworkAccessManager::NetworkAccessManager(QObject *parent)
    : QObject(parent), INetworkAccessManager() {
    impl.reset(new Implementation());
}

NetworkAccessManager::~NetworkAccessManager() { }

QNetworkReply* NetworkAccessManager::get(const QNetworkRequest& request) {
    return impl->networkAccessManager.get(request);
}

bool NetworkAccessManager::isNetworkAccessible() const {
    return impl->networkAccessManager.networkAccessible() == QNetworkAccessManager::Accessible;
}

} //networking
} //cm
