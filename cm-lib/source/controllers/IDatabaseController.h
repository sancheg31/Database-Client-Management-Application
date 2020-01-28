#pragma once

#include <QObject>
#include <QList>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>


#include "cm-lib_global.h"

namespace cm {
namespace controllers {


class CMLIB_EXPORT IDatabaseController : public QObject
{
    Q_OBJECT

public:
    IDatabaseController(QObject* parent) : QObject(parent){}
    virtual ~IDatabaseController(){}

    virtual bool createRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject) const = 0;
    virtual bool deleteRow(const QString& tableName, const QString& id) const = 0;
    virtual QJsonArray find(const QString& tableName, const QString& searchText) const = 0;
    virtual QJsonObject readRow(const QString& tableName, const QString& id) const = 0;
    virtual bool updateRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject) const = 0;
};


} //controllers
} //cm

