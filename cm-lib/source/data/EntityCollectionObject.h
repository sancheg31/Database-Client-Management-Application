#pragma once

#include <QObject>

#include "cm-lib_global.h"

namespace cm {
namespace data {

class CMLIB_EXPORT EntityCollectionObject : public QObject
{
    Q_OBJECT
public:
    explicit EntityCollectionObject(QObject *parent = nullptr): QObject(parent) { }
    virtual ~EntityCollectionObject() { }

signals:
    void collectionChanged();
};

} //data
} //cm





