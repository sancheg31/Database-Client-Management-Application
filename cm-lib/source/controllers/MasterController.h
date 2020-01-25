#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include "cm-lib_global.h"
#include "NavigationController.h"
#include "CommandController.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
    Q_PROPERTY(cm::controllers::NavigationController* ui_navigationController READ navigationController)
    Q_PROPERTY(cm::controllers::CommandController* ui_commandController READ commandController)
public:
    explicit MasterController(QObject *parent = nullptr);
    ~MasterController();

    NavigationController* navigationController();
    CommandController* commandController();

    const QString& welcomeMessage() const;
private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //controllers
} //cm


