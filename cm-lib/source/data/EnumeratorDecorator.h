#pragma once

#include "DataDecorator.h"

#include <map>

#include <QJsonObject>
#include <QJsonValue>
#include <QScopedPointer>
#include <QHash>

#include "cm-lib_global.h"



namespace cm {
namespace data {

class CMLIB_EXPORT EnumeratorDecorator : public cm::data::DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString ui_valueDescription READ valueDescription NOTIFY valueChanged)
public:
    EnumeratorDecorator(Entity * parent = nullptr, const QString& key = "", const QString& label = "", int value = 0,
                        const QHash<int, QString>& mapper = {});
    virtual ~EnumeratorDecorator();

    int value() const;
    QString valueDescription() const;
    EnumeratorDecorator& setValue(int value);

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



