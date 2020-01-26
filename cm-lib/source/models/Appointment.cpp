#include "Appointment.h"


namespace cm {
namespace models {


Appointment::Appointment(QObject* parent): data::Entity(parent) {
    startTime = static_cast<data::DateTimeDecorator*>(addDataItem(new data::DateTimeDecorator(this, "startTime", "StartTime")));
    endTime = static_cast<data::DateTimeDecorator*>(addDataItem(new data::DateTimeDecorator(this, "endTime", "EndTime")));
    notes = static_cast<data::StringDecorator*>(addDataItem(new data::StringDecorator(this, "notes", "Notes")));
}

Appointment::Appointment(QObject* parent, const QJsonObject& json): Appointment(parent) {
    update(json);
}


} //models
} //cm
