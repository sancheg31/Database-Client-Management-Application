#pragma once

#include <QObject>
#include <QtQml/QQmlListProperty>

#include "data/StringDecorator.h"
#include "data/Entity.h"
#include "data/EntityCollection.h"

#include "Address.h"
#include "Appointment.h"
#include "Contact.h"

#include "cm-lib_global.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Client: public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::StringDecorator* ui_reference MEMBER reference CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_name MEMBER name CONSTANT)
    Q_PROPERTY(cm::models::Address* ui_supplyAddress MEMBER supplyAddress CONSTANT)
    Q_PROPERTY(cm::models::Address* ui_billingAddress MEMBER billingAddress CONSTANT)
    Q_PROPERTY(QQmlListProperty<Appointment> ui_appointments READ ui_appointments NOTIFY appointmentsChanged)
    Q_PROPERTY(QQmlListProperty<Contact> ui_contacts READ ui_contacts NOTIFY contactsChanged)
public:
    explicit Client(QObject* parent = nullptr);
    Client(QObject* parent, const QJsonObject& json);

    data::StringDecorator* reference{nullptr};
    data::StringDecorator* name{nullptr};
    Address* supplyAddress{nullptr};
    Address* billingAddress{nullptr};
    data::EntityCollection<Appointment>* appointments{nullptr};
    data::EntityCollection<Contact>* contacts{nullptr};

    QQmlListProperty<cm::models::Appointment> ui_appointments();
    QQmlListProperty<cm::models::Contact>ui_contacts();

signals:
    void appointmentsChanged();
    void contactsChanged();
};

} //models
} //cm


