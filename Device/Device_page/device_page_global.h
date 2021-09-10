#ifndef DEVICE_PAGE_GLOBAL_H
#define DEVICE_PAGE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DEVICE_PAGE_LIBRARY)
#  define DEVICE_PAGESHARED_EXPORT Q_DECL_EXPORT
#else
#  define DEVICE_PAGESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DEVICE_PAGE_GLOBAL_H
