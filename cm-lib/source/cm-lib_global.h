#pragma once

#include <QtCore/qglobal.h>

#if defined(CMLIB_LIBRARY)
#  define CMLIB_EXPORT Q_DECL_EXPORT
#else
#  define CMLIB_EXPORT Q_DECL_IMPORT
#endif
