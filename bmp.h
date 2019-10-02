#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "PixelInfo.h"

class bmp {
public:
  std::basic_ofstream<char, std::char_traits<char> > file;
  char* fileName;
  int width, height;
  PixelInfo* pixelInfo;

  bmp(const char* fileName, const int width, const int height, PixelInfo* getPix);

private:
  template<typename T>
  void BinaryWrite(T getData, int getSize) {
    file.write(reinterpret_cast<char*>(&getData), getSize);
  }
};
