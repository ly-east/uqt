#ifndef FILESYSTEM_BROWSE_H
#define FILESYSTEM_BROWSE_H

#include "uqt_global.h"
#include <QString>

class QWidget;

namespace uqt {
namespace filesystem {
UQT_EXPORT QString selectOutputDirectory(QWidget *parent,
                                         const QString &currentPath);
} // namespace filesystem
} // namespace uqt

#endif // FILESYSTEM_BROWSE_H
