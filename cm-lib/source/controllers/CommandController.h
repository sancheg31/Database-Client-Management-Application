#pragma once

#include <QObject>
#include <QtQml/QQmlListProperty>
#include "cm-lib_global.h"
#include "framework/Command.h"

namespace cm {
namespace controllers {

class CMLIB_EXPORT CommandController : public QObject
{
    Q_OBJECT
public:
    explicit CommandController(QObject *parent = nullptr): QObject(parent) { }

signals:

};

} //controllers
} //cm



