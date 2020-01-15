#pragma once

#include <QObject>

#include "cm-lib_global.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_welcomeMessage MEMBER welcomeMessage CONSTANT)
public:
    explicit MasterController(QObject *parent = nullptr);

private:
    QString welcomeMessage = "This is MasterController";
};

} //controllers
} //cm


