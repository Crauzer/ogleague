#pragma once
#include <oglib/base/types.hpp>
namespace OG {
  struct Color
  {
    uint8 blue, green, red, alpha;
    Color(int red, int green, int blue, int alpha = 255.0f)
      : blue(blue)
      , green(green)
      , red(red)
      , alpha(alpha)
    {}
    Color(float red, float green, float blue, float alpha = 255.0f)
      : blue(blue)
      , green(green)
      , red(red)
      , alpha(alpha)
    {}
  };
}