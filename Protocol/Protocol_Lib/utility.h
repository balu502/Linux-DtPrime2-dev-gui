#ifndef UTILITY_H
#define UTILITY_H

#if defined(PROTOCOL_LIB_LIBRARY)
#  define PROTOCOL_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PROTOCOL_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

PROTOCOL_LIBSHARED_EXPORT   int Read_XML(rt_Protocol *p, QString fn, bool only_config = false);


#endif // UTILITY_H

