#ifndef THINGSPEAKQT_GLOBAL_H
#define THINGSPEAKQT_GLOBAL_H

#include <QtCore/qglobal.h>

// Used for importing/exporting symbols from shared library.
#if defined(THINGSPEAKQT_LIBRARY)
#  define THINGSPEAKQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define THINGSPEAKQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // THINGSPEAKQT_GLOBAL_H
