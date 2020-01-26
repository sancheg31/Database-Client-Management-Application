#include "Entity.h"


namespace cm {
namespace data {

class Entity::Implementation
{
public:
    Implementation(Entity* en, const QString& k): entity(en), key(k) { }
    Entity* entity{nullptr};
    QString key;
    QHash<QString, Entity*> childEntities;
    QHash<QString, DataDecorator*> dataDecorators;
    QHash<QString, EntityCollectionBase*> childCollections;
};

Entity::Entity(QObject* parent, const QString& key): QObject(parent) {
    impl.reset(new Implementation(this, key));
}

Entity::Entity(QObject* parent, const QString& key, const QJsonObject& jsonObject): Entity(parent, key) {
    update(jsonObject);
}

Entity::~Entity() { }

const QString& Entity::key() const {
    return impl->key;
}

Entity* Entity::addChild(Entity* entity, const QString& key) {
    if (impl->childEntities.contains(key)) {
        impl->childEntities.insert(key, entity);
        emit childEntitiesChanged();
    }
    return entity;
}

DataDecorator* Entity::addDataItem(DataDecorator *data) {
    if (impl->dataDecorators.contains(data->key())) {
        impl->dataDecorators.insert(data->key(), data);
        emit dataDecoratorsChanged();
    }
    return data;
}

EntityCollectionBase* Entity::addChildCollection(EntityCollectionBase* entityCollection) {
    if (impl->childCollections.contains(entityCollection->key())) {
        impl->childCollections.insert(entityCollection->key(), entityCollection);
        emit childCollectionChanged(entityCollection->key());
    }
    return entityCollection;
}

void Entity::update(const QJsonObject& jsonObject) {
    for (auto & data: impl->dataDecorators)
        data->update(jsonObject);
    for (auto & entity: impl->childEntities)
        entity->update(jsonObject);
    for (auto & collection: impl->childCollections)
        collection->update(jsonObject.value(collection->key()).toArray());
}

QJsonObject Entity::toJson() const {
    QJsonObject result;
    for (auto & data: impl->dataDecorators) {
        result.insert(data->key(), data->jsonValue());
    }
    for (auto & entity: impl->childEntities) {
        result.insert(entity->key(), entity->toJson());
    }
    for (auto & collection: impl->childCollections) {
        QJsonArray arr;
        for (auto & entity: collection->baseEntities())
            arr.append(entity->toJson());
        result.insert(collection->key(), arr);
    }
    return result;
}


} //data
} //cm
