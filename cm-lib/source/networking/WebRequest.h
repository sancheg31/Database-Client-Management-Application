#pragma once


#include <QList>
#include <QObject>
#include <QSslError>
#include "networking/INetworkAccessManager.h"
#include "networking/IWebRequest.h"

namespace cm {
namespace networking {

class WebRequest : public IWebRequest
{
    Q_OBJECT

public:
    WebRequest(QObject* parent, INetworkAccessManager* networkAccessManager, const QUrl& url);
    WebRequest(QObject* parent = nullptr) = delete;
    ~WebRequest();

public:
    void execute() override;
    bool isBusy() const override;
    void setUrl(const QUrl& url) override;
    QUrl url() const override;

private slots:
    void replyDelegate();
    void sslErrorsDelegate( const QList<QSslError>& _errors );

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //networking
} //cm
