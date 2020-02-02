/****************************************************************************
** Meta object code from reading C++ file 'Client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/models/Client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__models__Client_t {
    QByteArrayData data[16];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__models__Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__models__Client_t qt_meta_stringdata_cm__models__Client = {
    {
QT_MOC_LITERAL(0, 0, 18), // "cm::models::Client"
QT_MOC_LITERAL(1, 19, 19), // "appointmentsChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 15), // "contactsChanged"
QT_MOC_LITERAL(4, 56, 10), // "addContact"
QT_MOC_LITERAL(5, 67, 10), // "setDefault"
QT_MOC_LITERAL(6, 78, 12), // "ui_reference"
QT_MOC_LITERAL(7, 91, 26), // "cm::data::StringDecorator*"
QT_MOC_LITERAL(8, 118, 7), // "ui_name"
QT_MOC_LITERAL(9, 126, 16), // "ui_supplyAddress"
QT_MOC_LITERAL(10, 143, 20), // "cm::models::Address*"
QT_MOC_LITERAL(11, 164, 17), // "ui_billingAddress"
QT_MOC_LITERAL(12, 182, 15), // "ui_appointments"
QT_MOC_LITERAL(13, 198, 41), // "QQmlListProperty<cm::models::..."
QT_MOC_LITERAL(14, 240, 11), // "ui_contacts"
QT_MOC_LITERAL(15, 252, 37) // "QQmlListProperty<cm::models::..."

    },
    "cm::models::Client\0appointmentsChanged\0"
    "\0contactsChanged\0addContact\0setDefault\0"
    "ui_reference\0cm::data::StringDecorator*\0"
    "ui_name\0ui_supplyAddress\0cm::models::Address*\0"
    "ui_billingAddress\0ui_appointments\0"
    "QQmlListProperty<cm::models::Appointment>\0"
    "ui_contacts\0QQmlListProperty<cm::models::Contact>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__models__Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       6,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, 0x80000000 | 7, 0x00095409,
       8, 0x80000000 | 7, 0x00095409,
       9, 0x80000000 | 10, 0x00095409,
      11, 0x80000000 | 10, 0x00095409,
      12, 0x80000000 | 13, 0x00495009,
      14, 0x80000000 | 15, 0x00495009,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       1,

       0        // eod
};

void cm::models::Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appointmentsChanged(); break;
        case 1: _t->contactsChanged(); break;
        case 2: _t->addContact(); break;
        case 3: _t->setDefault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::appointmentsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::contactsChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::data::StringDecorator* >(); break;
        case 3:
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Address* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< cm::data::StringDecorator**>(_v) = _t->reference; break;
        case 1: *reinterpret_cast< cm::data::StringDecorator**>(_v) = _t->name; break;
        case 2: *reinterpret_cast< cm::models::Address**>(_v) = _t->supplyAddress; break;
        case 3: *reinterpret_cast< cm::models::Address**>(_v) = _t->billingAddress; break;
        case 4: *reinterpret_cast< QQmlListProperty<cm::models::Appointment>*>(_v) = _t->ui_appointments(); break;
        case 5: *reinterpret_cast< QQmlListProperty<cm::models::Contact>*>(_v) = _t->ui_contacts(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject cm::models::Client::staticMetaObject = { {
    &data::Entity::staticMetaObject,
    qt_meta_stringdata_cm__models__Client.data,
    qt_meta_data_cm__models__Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cm::models::Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::models::Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__models__Client.stringdata0))
        return static_cast<void*>(this);
    return data::Entity::qt_metacast(_clname);
}

int cm::models::Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = data::Entity::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void cm::models::Client::appointmentsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cm::models::Client::contactsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
