#pragma once

#include <QObject>
#include <QList>
#include <QVector>

#include "EntityCollectionObject.h"



namespace cm {
namespace data {

class Entity;

class EntityCollectionBase: public EntityCollectionObject
{
public:
    EntityCollectionBase(QObject* parent = nullptr, const QString& k = "");

    virtual ~EntityCollectionBase();
    QString key() const;

    virtual void clear() = 0;
    virtual void update(const QJsonArray& json) = 0;
    virtual QVector<Entity*> baseEntities() = 0;

    template <typename T>
    QList<T*>& derivedEntities();

    template <typename T>
    T* addEntity(T* entity);

private:
    QString ckey;
};

} //data
} //cm


