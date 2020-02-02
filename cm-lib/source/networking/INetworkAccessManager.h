#pragma once


#include <QNetworkReply>
#include <QNetworkRequest>

namespace cm {
namespace networking {

class INetworkAccessManager
{
public:
    INetworkAccessManager(){}
    virtual ~INetworkAccessManager(){}

    virtual QNetworkReply* get(const QNetworkRequest& request) = 0;
    virtual bool isNetworkAccessible() const = 0;
};

} //networking
} //cm
