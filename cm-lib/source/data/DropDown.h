#pragma once
#include <QObject>
#include <QtQml/QQmlListProperty>

#include <QHash>
#include "cm-lib_global.h"
#include "data/DropDownValue.h"

namespace cm {
namespace data {

class CMLIB_EXPORT DropDown : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::data::DropDownValue> ui_values READ ui_values CONSTANT)

public:
    explicit DropDown(QObject* _parent = nullptr, const std::map<int, QString>& values = std::map<int, QString>());
    ~DropDown();

public:
    QQmlListProperty<DropDownValue> ui_values();

public slots:
    QString findDescriptionForDropdownValue(int valueKey) const;

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}
