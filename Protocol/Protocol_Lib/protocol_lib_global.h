#ifndef PROTOCOL_LIB_GLOBAL_H
#define PROTOCOL_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PROTOCOL_LIB_LIBRARY)
#  define PROTOCOL_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PROTOCOL_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PROTOCOL_LIB_GLOBAL_H
