#pragma once

class PixelInfo {
public:
  int r, g, b;

  PixelInfo() : r(0), g(0), b(0) {}
  PixelInfo(const int r, const int g, const int b) : r(r), g(g), b(b) {}

  inline PixelInfo operator+ (const PixelInfo a) {
    return PixelInfo(this->r+a.r,this->g+a.g,this->b+a.b);
  }
  inline PixelInfo operator- (const PixelInfo a) {
    return PixelInfo(this->r - a.r, this->g - a.g, this->b - a.b);
  }
  inline PixelInfo operator* (const PixelInfo a) {
    return PixelInfo((int)(1.0* this->r * a.r/255), (int)(1.0 * this->g * a.g / 255), (int)(1.0 * this->b * a.b / 255));
  }
  inline PixelInfo operator/ (const PixelInfo a) {
    return PixelInfo((int)(1.0 * this->r / a.r * 255), (int)(1.0 * this->g * a.g * 255), (int)(1.0 * this->b * a.b * 255));
  }
  inline PixelInfo operator/ (const int a) {
    return PixelInfo((int)(1.0 * this->r / a), (int)(1.0 * this->g * a), (int)(1.0 * this->b * a));
  }
  inline PixelInfo operator/ (const double a) {
    return PixelInfo((int)(1.0 * this->r / a), (int)(1.0 * this->g * a), (int)(1.0 * this->b * a));
  }
};
