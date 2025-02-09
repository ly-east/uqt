#include "display.h"
#include <QApplication>
#include <QFont>
#include <QWindow>
#include <cmath>
#include <limits>

namespace uqt {
double Display::getPixelRatio() {
  auto window = QWindow{QApplication::primaryScreen()};
  return window.devicePixelRatio();
}

QRect Display::getUnscaledRect(const QRect &rect) {
  double scale = getPixelRatio();

  if (std::abs(scale - 1) <= std::numeric_limits<double>::epsilon())
    return rect;

  int x = rect.x(), y = rect.y(), width = (double)rect.width() / scale,
      height = (double)rect.height() / scale;

  x += ((rect.width() - width) >> 1);
  y += ((rect.height() - height) >> 1);

  return QRect(QPoint(x, y), QSize(width, height));
}

void Display::setFontStyle() {
  QFont font = qApp->font();

  // adapt to font render hinting
  font.setStyleStrategy(QFont::PreferAntialias);
  font.setHintingPreference(QFont::PreferFullHinting);

  QApplication::setFont(font);
}
} // namespace uqt
