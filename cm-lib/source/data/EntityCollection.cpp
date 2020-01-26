#include "EntityCollection.h"

namespace cm {
namespace data {

template<typename T>
EntityCollection::EntityCollection(QObject* parent, const QString& key): EntityCollectionBase(parent, key) { }

template<typename T>
EntityCollection::~EntityCollection() { }

void EntityCollection::clear() {
    for (auto entity: collection) {
        entity->deleteLater();
    }
    collection.clear();
}

template<typename T>
void EntityCollection::update(const QJsonArray& jsonArray) {
    clear();
    for (const auto & jsonValue: jsonArray)
        addEntity(new T(this, jsonValue.toObject()));
}

template<typename T>
QVector<Entity*> EntityCollection::baseEntities() {
    QVector<Entity*> result;
    for (auto & entity: collection) {
        result.push_back(entity);
    }
    return result;
}

template<typename T>
QList<T*>& EntityCollection::derivedEntities() {
    return collection;
}

template<typename T>
T* EntityCollection::addEntity(cm::data::T* entity) {
    if (!collection.contains(entity)) {
        collection.append(entity);
        EntityCollectionObject::collectionChanged();
    }
    return entity;
}


} //data
} //cm
