#ifndef DISPLAY_H
#define DISPLAY_H

#include "uqt_global.h"
#include <QRect>

namespace uqt {
class UQT_EXPORT Display {
public:
  // Adapt to Hi-DPI environments

  // Scale
  // Example: returns 1.0 for 100% scale, and 1.5 for 150% scale
  static double getPixelRatio();

  // Get geometry which is not affected by scale
  static QRect getUnscaledRect(const QRect &rect);

  // PreferAntialias, PreferFullHinting
  static void setFontStyle();
};
} // namespace uqt

#endif // DISPLAY_H
