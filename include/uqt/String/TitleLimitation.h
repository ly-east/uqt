#ifndef STRING_TITLELIMITATION_H
#define STRING_TITLELIMITATION_H

#include "uqt_global.h"
#include <QString>
#include <filesystem>

namespace uqt {
namespace string {
enum class Limitation : unsigned { Short = 38, Medium = 42, Long = 46 };

UQT_EXPORT QString titleLimitation(const QString &title,
                                   Limitation limitation = Limitation::Medium);

inline QString fromStdPath(const std::filesystem::path &path) {
#if defined(_WIN32)
  return QString::fromStdWString(path.wstring());
#elif defined(__linux__)
  return QString::fromStdString(path.string());
#endif
}
} // namespace string
} // namespace uqt

#endif // STRING_TITLELIMITATION_H
