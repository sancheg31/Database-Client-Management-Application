#include "Contact.h"

namespace cm {
namespace models {

Contact::Contact(QObject* parent): Entity(parent) {
    contactType = static_cast<data::EnumeratorDecorator*>(addDataItem(new data::EnumeratorDecorator(this, "contactType", "ContactType")));
    address = static_cast<data::StringDecorator*>(addDataItem(new data::StringDecorator(this, "address", "Address")));
}

Contact::Contact(QObject* parent, const QJsonObject& json): Contact(parent) {
    update(json);
}


} //models
} //cm

