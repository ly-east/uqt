#include "String/TitleLimitation.h"

namespace uqt {
namespace string {
QString titleLimitation(const QString &title, Limitation limitation) {
  const unsigned title_max_size = static_cast<unsigned>(limitation);
  auto str{title};

  if (str.size() > title_max_size) {
    str.resize(title_max_size);
    str.append("...");
  }

  return str;
}
} // namespace string
} // namespace uqt
