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
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands READ createClientViewContextCommands CONSTANT)

public:
    explicit CommandController(QObject *parent = nullptr);
    ~CommandController();

    QQmlListProperty<cm::framework::Command> createClientViewContextCommands();

public slots:
    void onCreateClientSaveExecuted();

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //controllers
} //cm



