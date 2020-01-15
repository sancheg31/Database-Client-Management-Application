#pragma once

#include <QObject>

#include "cm-lib_global.h"

namespace cm
{
namespace controllers
{

class Q_DECL_EXPORT MasterController : public QObject
{
    Q_OBJECT
public:
    explicit MasterController(QObject *parent = nullptr);

};

} //controllers
} //cm


