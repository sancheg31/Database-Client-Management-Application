#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <functional>

#include "cm-lib_global.h"

namespace cm {
namespace framework {

class CMLIB_EXPORT Command : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_iconCharacter READ iconCharacter CONSTANT)
    Q_PROPERTY(QString ui_description READ description CONSTANT)
    Q_PROPERTY(bool ui_canExecute READ canExecute NOTIFY canExecuteChanged)
public:
    explicit Command(QObject *parent = nullptr, const QString& icon = "", const QString& desc = "",
                     std::function<bool()> canExecute = [](){ return true; });

    ~Command();
    const QString& iconCharacter() const;
    const QString& description() const;
    bool canExecute() const;

signals:
    void canExecuteChanged();
    void executed();

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //framework
} //cm


