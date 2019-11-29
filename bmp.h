#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <string>
#include "PixelInfo.h"

class bmp {
public:
  std::basic_ofstream<char, std::char_traits<char> > file;
  char* fileName;
  int width, height;
  std::vector<PixelInfo> pixData;
  int bfOffBits, biBitCount, biCompression, PaddingSize, biSizeImage, fileSize, biXPixPerMeter, biYPixPerMeter, biClrUsed , biCirImportant;

  bmp(const int width, const int height, std::vector<PixelInfo> getPix);
  bmp(std::istream&);

  void Output(const char* fileName);

private:
  template<typename T>
  void BinaryWrite(T getData, int getSize) {
    file.write(reinterpret_cast<char*>(&getData), getSize);
  }
};

int IntMax(const double);
