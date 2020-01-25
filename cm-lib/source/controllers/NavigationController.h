#pragma once

#include <QObject>

#include "models/Client.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT NavigationController: public QObject
{
    Q_OBJECT
public:
    explicit NavigationController(QObject* parent = nullptr): QObject(parent) { }

signals:
    void createClientView();
    void goDashboardView();
    void goEditClientView(cm::models::Client* client);
    void goFindClientView();

};


} //controllers
} //cm
