#pragma once

#include <QObject>
#include <QList>
#include <QHash>

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>


#include "EntityCollectionBase.h"

namespace cm {
namespace data {

template <typename T>
class EntityCollection: public EntityCollectionBase
{
public:
    EntityCollection(QObject* parent = nullptr, const QString& key = "");

    virtual ~EntityCollection();

    void clear() override;
    void update(const QJsonArray &jsonArray) override;

    QVector<Entity *> baseEntities() override;
    QList<T*>& derivedEntities();

    T* addEntity(T* entity);

private:
    QList<T*> collection;
};

} //data
} //cm


