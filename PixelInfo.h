#pragma once

class PixelInfo {
public:
  unsigned char r, g, b;

  PixelInfo() : r(0), g(0), b(0) {}
  PixelInfo(const unsigned char r, const unsigned char g, const unsigned char b) : r(r), g(g), b(b) {}

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
