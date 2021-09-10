#ifndef GRAPH_FLUOR_GLOBAL_H
#define GRAPH_FLUOR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GRAPH_FLUOR_LIBRARY)
#  define GRAPHFLUORSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GRAPHFLUORSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GRAPH_FLUOR_GLOBAL_H
