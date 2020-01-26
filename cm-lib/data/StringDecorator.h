#pragma once

#include "DataDecorator.h"

#include <QJsonObject>
#include <QJsonValue>
#include <QScopedPointer>

#include "cm-lib_global.h"

namespace cm {
namespace data {

class CMLIB_EXPORT StringDecorator : public cm::data::DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    StringDecorator(Entity* p = nullptr, const QString& key = "", const QString& label = "", const QString& value = "");
    ~StringDecorator();

    StringDecorator& setValue(const QString& value);
    const QString& value() const;

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


