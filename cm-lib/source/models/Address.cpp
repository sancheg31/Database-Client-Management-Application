#include "Address.h"


namespace cm {
namespace models {

Address::Address(QObject* parent): Entity(parent) {
    building = static_cast<data::StringDecorator*>(addDataItem(new data::StringDecorator(this, "building", "Building")));
    street = static_cast<data::StringDecorator*>(addDataItem(new data::StringDecorator(this, "street", "Street")));
    city = static_cast<data::StringDecorator*>(addDataItem(new data::StringDecorator(this, "city", "City")));
    postcode = static_cast<data::StringDecorator*>(addDataItem(new data::StringDecorator(this, "postcode", "Postcode")));
}

Address::Address(QObject* parent, const QJsonObject& json): Address(parent) {
    update(json);
}

QString Address::fullAdress() const {
    return building->value() + " " + street->value() + '\n' + city->value() + '\n' + postcode->value();
}

} //models
} //cm


