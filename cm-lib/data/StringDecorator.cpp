#include "StringDecorator.h"

#include <QVariant>

namespace cm {
namespace data {

class StringDecorator::Implementation
{
public:
    Implementation(StringDecorator* parent, const QString& v): stringDecorator(parent), value(v) {}
    StringDecorator* stringDecorator;
    QString value;
};

StringDecorator::StringDecorator(Entity* parentEntity, const QString& key, const QString& label, const QString& value): cm::data::DataDecorator(parentEntity, key, label) {
    impl.reset(new Implementation(this, value));
}

StringDecorator::~StringDecorator() {}

const QString& StringDecorator::value() const {
    return impl->value;
}

StringDecorator& StringDecorator::setValue(const QString& value) {
    if (value != impl->value) {
        impl->value = value;
        emit valueChanged();
    }
    return *this;
}

QJsonValue StringDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(impl->value));
}

void StringDecorator::update(const QJsonObject &jsonObject) {
    if (jsonObject.contains(key())) {
        setValue(jsonObject.value(key()).toString());
    } else {
        setValue("");
    }
}

} //data
} //cm
