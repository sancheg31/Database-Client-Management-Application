#pragma once

#include <QObject>

#include "cm-lib_global.h"
#include "data/StringDecorator.h"
#include "data/Entity.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Address : public cm::data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::StringDecorator* ui_building MEMBER building CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_street MEMBER street CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_city MEMBER city CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_postcode MEMBER postcode CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_fullAdress READ fullAdress CONSTANT)
public:
    explicit Address(QObject *parent = nullptr);
    Address(QObject* parent, const QJsonObject& json);

    data::StringDecorator* building{nullptr};
    data::StringDecorator* street{nullptr};
    data::StringDecorator* city{nullptr};
    data::StringDecorator* postcode{nullptr};

    QString fullAdress() const;
};


} //models
} //cm


