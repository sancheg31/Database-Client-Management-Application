#include "EntityCollectionBase.h"

#include "EntityCollection.h"

namespace cm {
namespace data {


EntityCollectionBase::EntityCollectionBase(QObject* parent, const QString& k): EntityCollectionObject(parent), ckey(k) { }

EntityCollectionBase::~EntityCollectionBase() { }

QString EntityCollectionBase::key() const { return ckey; }

template <typename T>
QList<T*>& EntityCollectionBase::derivedEntities() {
    return dynamic_cast<const EntityCollection<T>&>(*this).derivedEntities();
}

template <typename T>
T* EntityCollectionBase::addEntity(T* entity) {
    return dynamic_cast<const EntityCollection<T>&>(*this).addEntity(entity);
}

} //data
} //cm

