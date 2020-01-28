#pragma once

#include "DataDecorator.h"

#include <QJsonObject>
#include <QJsonValue>
#include <QScopedPointer>

#include "cm-lib_global.h"

namespace cm {
namespace data {

class CMLIB_EXPORT IntDecorator : public cm::data::DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)

public:
    IntDecorator(Entity* parent = nullptr, const QString& key = "", const QString& label = "", int value = 0);
    virtual ~IntDecorator();

    int value() const;
    IntDecorator& setValue(int value);

    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObject) override;

signals:
    void valueChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //data
} //cm


