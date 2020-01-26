#pragma once

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QHash>
#include <QScopedPointer>

#include "DataDecorator.h"
#include "EntityCollectionBase.h"
#include "cm-lib_global.h"

namespace cm {
namespace data {

class CMLIB_EXPORT Entity : public QObject
{
    Q_OBJECT
public:
    Entity(QObject* parent = nullptr, const QString& key = "");
    Entity(QObject* parent, const QString& key, const QJsonObject& jsonObject);
    virtual ~Entity();

    const QString& key() const;
    QJsonObject toJson() const;

    void update(const QJsonObject& jsonObject);

protected:
    Entity* addChild(Entity* entity, const QString& key);
    DataDecorator* addDataItem(DataDecorator* dataDecorator);
    EntityCollectionBase* addChildCollection(EntityCollectionBase* entityCollection);

signals:
    void childEntitiesChanged();
    void dataDecoratorsChanged();
    void childCollectionChanged(const QString& key);

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //data
} //cm



