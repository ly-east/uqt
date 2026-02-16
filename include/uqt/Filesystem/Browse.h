#ifndef FILESYSTEM_BROWSE_H
#define FILESYSTEM_BROWSE_H

#include <QString>

class QWidget;

QString selectOutputDirectory(QWidget *parent, const QString &currentPath);

#endif // FILESYSTEM_BROWSE_H
