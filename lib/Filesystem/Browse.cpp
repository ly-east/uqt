#include "Filesystem/Browse.h"
#include <QDir>
#include <QFileDialog>

namespace uqt {
namespace filesystem {
QString selectOutputDirectory(QWidget *parent, const QString &currentPath) {
  QFileDialog fd{parent};
  fd.setFileMode(QFileDialog::Directory);

  QDir path{currentPath};
  if (path.cdUp())
    fd.setDirectory(path.absolutePath());
  else
    fd.setDirectory(QDir::homePath());

  if (!fd.exec())
    return {};

  auto dir = fd.selectedFiles();
  QString outputDirectory;
  if (!dir.empty())
    outputDirectory = dir.front();

  return outputDirectory;
}
} // namespace filesystem
} // namespace uqt
