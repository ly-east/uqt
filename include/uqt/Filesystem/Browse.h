#ifndef FILESYSTEM_BROWSE_H
#define FILESYSTEM_BROWSE_H

#include "uqt_global.h"
#include <QString>

class QWidget;

UQT_EXPORT QString selectOutputDirectory(QWidget *parent,
                                         const QString &currentPath);

#endif // FILESYSTEM_BROWSE_H
