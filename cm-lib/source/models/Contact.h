#pragma once

#include <QObject>
#include <QJsonObject>
#include <QHash>

#include "data/Entity.h"
#include "data/StringDecorator.h"
#include "data/EnumeratorDecorator.h"
#include "cm-lib_global.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Contact : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(data::EnumeratorDecorator* ui_contactType MEMBER contactType CONSTANT)
    Q_PROPERTY(data::StringDecorator* ui_address MEMBER address CONSTANT)
public:
    explicit Contact(QObject *parent = nullptr);
    Contact(QObject* parent, const QJsonObject& json);

    enum ContactType {
        Unknown = 0,
        Telephone,
        Email,
        Fax
    };

    data::EnumeratorDecorator* contactType{};
    data::StringDecorator* address{};

private:
    static const QHash<ContactType, QString> contactTypeMapper;
};

const QHash<Contact::ContactType, QString> Contact::contactTypeMapper = QHash<Contact::ContactType, QString>{
    { Contact::ContactType::Unknown, "" },
    { Contact::ContactType::Telephone, "Telephone" },
    { Contact::ContactType::Email, "Email" },
    { Contact::ContactType::Fax, "Fac" }
};


} //models
} //cm



