#ifndef GRAPH_TEMPERATURE_GLOBAL_H
#define GRAPH_TEMPERATURE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GRAPH_TEMPERATURE_LIBRARY)
#  define GRAPHTEMPERATURESHARED_EXPORT Q_DECL_EXPORT
#else
#  define GRAPHTEMPERATURESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GRAPH_TEMPERATURE_GLOBAL_H