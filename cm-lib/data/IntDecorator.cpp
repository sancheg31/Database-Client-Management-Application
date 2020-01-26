#include "IntDecorator.h"

#include <QVariant>

namespace cm {
namespace data {


class IntDecorator::Implementation
{
public:
    Implementation(IntDecorator* p, int v): parentEntity(p), value(v) { }
    IntDecorator* parentEntity;
    int value;
};

IntDecorator::IntDecorator(Entity* parent, const QString& key, const QString& label, int value):
    cm::data::DataDecorator(parent, key, label) {
    impl.reset(new Implementation(this, value));
}

IntDecorator::~IntDecorator() { }

int IntDecorator::value() const {
    return impl->value;
}

IntDecorator& IntDecorator::setValue(int value) {
    if (value == impl->value) {
        impl->value = value;
        emit valueChanged();
    }
    return *this;
}

QJsonValue IntDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(impl->value));
}

void IntDecorator::update(const QJsonObject& jsonObject) {
    if (jsonObject.contains(key())) {
        setValue(jsonObject.value(key()).toInt());
    } else {
        setValue(0);
    }
}


} //data
} //cm
