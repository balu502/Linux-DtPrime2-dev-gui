#ifndef PROTOCOL_INFO_GLOBAL_H
#define PROTOCOL_INFO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PROTOCOL_INFO_LIBRARY)
#  define PROTOCOL_INFOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PROTOCOL_INFOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PROTOCOL_INFO_GLOBAL_H
