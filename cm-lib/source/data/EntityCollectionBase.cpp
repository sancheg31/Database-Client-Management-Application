#include "EntityCollectionBase.h"

#include "EntityCollection.h"

namespace cm {
namespace data {


EntityCollectionBase::EntityCollectionBase(QObject* parent, const QString& k): EntityCollectionObject(parent), ckey(k) { }

EntityCollectionBase::~EntityCollectionBase() { }

QString EntityCollectionBase::key() const { return ckey; }


} //data
} //cm

