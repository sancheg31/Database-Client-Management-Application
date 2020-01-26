#pragma once

#include "DataDecorator.h"

#include <QJsonObject>
#include <QJsonValue>
#include <QScopedPointer>
#include <QDateTime>

#include "cm-lib_global.h"

namespace cm {
namespace data {

class CMLIB_EXPORT DateTimeDecorator : public cm::data::DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QDateTime ui_value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString ui_iso8601String READ toIso8601String NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyDateString READ toPrettyDateString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyString READ toPrettyString NOTIFY valueChanged)

public:
    DateTimeDecorator(Entity* parent = nullptr, const QString& key = "",
                      const QString& label = "", const QDateTime& dateTime = QDateTime{});
    virtual ~DateTimeDecorator();

    QDateTime value() const;
    DateTimeDecorator& setValue(QDateTime value);

    QString toIso8601String() const;
    QString toPrettyDateString() const;
    QString toPrettyTimeString() const;
    QString toPrettyString() const;

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


