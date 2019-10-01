#pragma once

class PixelInfo {
public:
  int r, g, b;

  PixelInfo() : r(0), g(0), b(0) {}
  PixelInfo(const int r, const int g, const int b) : r(r), g(g), b(b) {}
};
