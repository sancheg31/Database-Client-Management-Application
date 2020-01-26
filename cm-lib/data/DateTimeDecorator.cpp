
#include "DateTimeDecorator.h"

#include <QVariant>

namespace cm {
namespace data {

class DateTimeDecorator::Implementation
{
public:
    Implementation(DateTimeDecorator* p, const QDateTime& dt = QDateTime{}):
        parentEntity(p), value(dt) { }
    DateTimeDecorator* parentEntity;
    QDateTime value;
};

DateTimeDecorator::DateTimeDecorator(Entity* parent, const QString& key, const QString& label, const QDateTime& value):
    DataDecorator(parent, key, label) {
    impl.reset(new Implementation(this, value));
}

DateTimeDecorator::~DateTimeDecorator() {}

QDateTime DateTimeDecorator::value() const {
    return impl->value;
}

DateTimeDecorator& DateTimeDecorator::setValue(QDateTime value) {
    if (value != impl->value) {
        impl->value = value;
        emit valueChanged();
    }
    return *this;
}

QString DateTimeDecorator::toIso8601String() const {
    if (impl->value.isNull())
        return "";
    else
        return impl->value.toString(Qt::ISODate);
}

QString DateTimeDecorator::toPrettyDateString() const {
    if (impl->value.isNull())
        return"Not Set";
    return impl->value.toString("d MMM yyyy");
}

QString DateTimeDecorator::toPrettyTimeString() const {
    if (impl->value.isNull())
        return "Not Set";
    return impl->value.toString("hh:mm ap");
}

QString DateTimeDecorator::toPrettyString() const {
    if (impl->value.isNull())
        return "Not Set";
    return impl->value.toString("dddd MMM yyyy @ HH:mm:ss");
}

QJsonValue DateTimeDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(impl->value));
}

void DateTimeDecorator::update(const QJsonObject& jsonObject) {
    if (jsonObject.contains(key())) {
        setValue(jsonObject.value(key()).toVariant().toDateTime());
    } else {
        setValue(QDateTime{});
    }
}

} //data
} //cm
