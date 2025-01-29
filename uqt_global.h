#ifndef UQT_GLOBAL_H
#define UQT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UQT_LIBRARY)
#define UQT_EXPORT Q_DECL_EXPORT
#else
#define UQT_EXPORT Q_DECL_IMPORT
#endif

#endif // UQT_GLOBAL_H
