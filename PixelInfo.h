#pragma once

class PixelInfo {
public:
  double r, g, b;

  PixelInfo() : r(0), g(0), b(0) {}
  PixelInfo(const double r, const double g, const double b) : r(r), g(g), b(b) {}

  inline PixelInfo operator+ (const PixelInfo a) {
    return PixelInfo(this->r+a.r,this->g+a.g,this->b+a.b);
  }
  inline PixelInfo operator- (const PixelInfo a) {
    return PixelInfo(this->r - a.r, this->g - a.g, this->b - a.b);
  }
  inline PixelInfo operator* (const PixelInfo a) {
    return PixelInfo(this->r * a.r, this->g * a.g ,  this->b * a.b );
  }
  inline PixelInfo operator/ (const PixelInfo a) {
    return PixelInfo(this->r / a.r ,  this->g * a.g ,  this->b * a.b );
  }
  inline PixelInfo operator/ (const double a) {
    return PixelInfo( this->r / a, this->g * a, this->b * a);
  }
};
