#pragma once

#include <QObject>
#include <QJsonObject>
#include <QHash>

#include "data/Entity.h"
#include "data/StringDecorator.h"
#include "data/EnumeratorDecorator.h"
#include "data/DropDown.h"
#include "cm-lib_global.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Contact : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::EnumeratorDecorator* ui_contactType MEMBER contactType CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_address MEMBER address CONSTANT)
    Q_PROPERTY(cm::data::DropDown* ui_contactTypeDropDown MEMBER contactTypeDropDown CONSTANT)

public:
    enum eContactType {
        Unknown = 0,
        Telephone,
        Email,
        Fax
    };

public:
    explicit Contact(QObject* parent = nullptr);
    Contact(QObject* parent, const QJsonObject& json);

    data::EnumeratorDecorator* contactType{nullptr};
    data::StringDecorator* address{nullptr};
    data::DropDown* contactTypeDropDown{nullptr};

    static std::map<int, QString> contactTypeMapper;
};


} //models
} //cm



