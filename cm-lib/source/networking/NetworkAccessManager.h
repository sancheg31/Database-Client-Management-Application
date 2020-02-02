#pragma once

#include <QObject>
#include <QScopedPointer>

#include "networking/INetworkAccessManager.h"

namespace cm {
namespace networking {

class NetworkAccessManager : public QObject, public INetworkAccessManager
{
    Q_OBJECT

public:
    explicit NetworkAccessManager(QObject* parent = nullptr);
    ~NetworkAccessManager();

    QNetworkReply* get(const QNetworkRequest& request) override;
    bool isNetworkAccessible() const override;

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

}}
