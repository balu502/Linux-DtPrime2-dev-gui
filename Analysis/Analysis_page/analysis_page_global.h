#ifndef ANALYSIS_PAGE_GLOBAL_H
#define ANALYSIS_PAGE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ANALYSIS_PAGE_LIBRARY)
#  define ANALYSIS_PAGESHARED_EXPORT Q_DECL_EXPORT
#else
#  define ANALYSIS_PAGESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ANALYSIS_PAGE_GLOBAL_H