#pragma once

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QHash>
#include <QScopedPointer>

#include "DataDecorator.h"
#include "StringDecorator.h"
#include "cm-lib_global.h"

#include "EntityCollection.h"
#include "controllers/DatabaseController.h"

using namespace cm::controllers;

namespace cm {
namespace data {

class CMLIB_EXPORT Entity : public QObject
{
    Q_OBJECT

public:
    Entity(QObject* parent = nullptr, const QString& key = "SomeEntityKey");
    Entity(QObject* parent, const QString& key, const QJsonObject& jsonObject);
    virtual ~Entity();

public:
    const QString& id() const;
    const QString& key() const;
    void setPrimaryKey(StringDecorator* primaryKey);
    void update(const QJsonObject& jsonObject);
    QJsonObject toJson() const;

signals:
    void childCollectionsChanged(const QString& collectionKey);
    void childEntitiesChanged();
    void dataDecoratorsChanged();

protected:
    Entity* addChild(Entity* entity, const QString& key);
    EntityCollectionBase* addChildCollection(EntityCollectionBase* entityCollection);
    DataDecorator* addDataItem(DataDecorator* dataDecorator);

protected:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //data
} //cm



