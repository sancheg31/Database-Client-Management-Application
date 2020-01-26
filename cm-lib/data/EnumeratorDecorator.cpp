#include "EnumeratorDecorator.h"

#include <QVariant>

namespace cm {
namespace data {

class EnumeratorDecorator::Implementation
{
public:
    Implementation(EnumeratorDecorator* parent, int v,  const QHash<int, QString>& mapper = {}):
        parentEntity(parent), value(v), descriptionMapper(mapper) { }
    EnumeratorDecorator* parentEntity;
    int value;
    QHash<int, QString> descriptionMapper;
};

EnumeratorDecorator::EnumeratorDecorator(Entity* parent, const QString& key, const QString& label,
                                         int value,  const QHash<int, QString>& mapper):
    cm::data::DataDecorator(parent, key, label) {
    impl.reset(new Implementation(this, value, mapper));
}

EnumeratorDecorator::~EnumeratorDecorator() { }

int EnumeratorDecorator::value() const {
    return impl->value;
}

QString EnumeratorDecorator::valueDescription() const {
    if (impl->descriptionMapper.contains(impl->value))
        return impl->descriptionMapper[impl->value];
    return "";
}

EnumeratorDecorator& EnumeratorDecorator::setValue(int value) {
    if (value != impl->value) {
        impl->value = value;
        emit valueChanged();
    }
    return *this;
}

QJsonValue EnumeratorDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(impl->value));
}

void EnumeratorDecorator::update(const QJsonObject& jsonObject) {
    if (jsonObject.contains(key())) {
        setValue(jsonObject.value(key()).toInt());
    } else {
        setValue(0);
    }
}

} //data
} //cm
