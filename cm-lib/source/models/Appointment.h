#pragma once

#include <QObject>
#include <QJsonObject>

#include "data/Entity.h"
#include "data/StringDecorator.h"
#include "data/DateTimeDecorator.h"

#include "cm-lib_global.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Appointment: public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(data::DateTimeDecorator* ui_startTime MEMBER startTime CONSTANT)
    Q_PROPERTY(data::DateTimeDecorator* ui_endTime MEMBER endTime CONSTANT)
    Q_PROPERTY(data::StringDecorator* ui_notes MEMBER notes CONSTANT)
public:
    explicit Appointment(QObject *parent = nullptr);
    Appointment(QObject* parent, const QJsonObject& json);

    data::DateTimeDecorator* startTime{nullptr};
    data::DateTimeDecorator* endTime{nullptr};
    data::StringDecorator* notes{nullptr};

};


} //models
} //cm

