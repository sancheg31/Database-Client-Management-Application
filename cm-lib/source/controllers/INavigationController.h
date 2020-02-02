#pragma once


#include <QObject>

#include "cm-lib_global.h"
#include "models/Client.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT INavigationController : public QObject
{
    Q_OBJECT

public:
    INavigationController(QObject* parent) : QObject(parent){}
    virtual ~INavigationController(){}

signals:
    void goCreateAppointmentView(cm::models::Client* client);
    void goCreateClientView();
    void goDashboardView();
    void goEditClientView(cm::models::Client* client);
    void goFindClientView();
    void goRssView();

};

} //controllers
} //cm
