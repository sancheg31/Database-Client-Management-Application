#pragma once


#include <QObject>

#include <cm-lib_global.h>
#include "models/Client.h"
#include "controllers/INavigationController.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT NavigationController : public INavigationController
{
    Q_OBJECT

public:
    explicit NavigationController(QObject* parent = nullptr) : INavigationController(parent){}

};

} //controllers
} //cm
