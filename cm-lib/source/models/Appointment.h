#pragma once

#include <QObject>
#include <QJsonObject>

#include "data/Entity.h"
#include "data/StringDecorator.h"
#include "data/DateTimeDecorator.h"

#include "cm-lib_global.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Appointment : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::DateTimeDecorator* ui_startAt MEMBER startAt CONSTANT)
    Q_PROPERTY(cm::data::DateTimeDecorator* ui_endAt MEMBER endAt CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_notes MEMBER notes CONSTANT)
public:
    explicit Appointment(QObject* parent = nullptr);
    Appointment(QObject* parent, const QJsonObject& json);

    data::DateTimeDecorator* startAt{nullptr};
    data::DateTimeDecorator* endAt{nullptr};
    data::StringDecorator* notes{nullptr};
};


} //models
} //cm

