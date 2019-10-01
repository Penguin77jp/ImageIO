#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "PixelInfo.h"

#include <stdio.h>

class bmp {
public:
  std::basic_ofstream<char, std::char_traits<char> > file;
  char* fileName;
  int width, height;
  PixelInfo* pixelInfo;

  bmp(const char* fileName, const int width, const int height,PixelInfo *getPix) : file(std::ofstream(fileName, std::ios::binary | std::ios::out)), width(width), height(height) {
    pixelInfo = getPix;

    const int bfOffBits = 54;
    const int biBitCount = 24;
    const int biCompression = 0;
    const int PaddingSize = width*3%4==0?0: 4 - width * 3 % 4;
    const int biSizeImage = 3 * width * height;
    const int fileSize = 14 + 44 + biSizeImage;
    const int biXPixPerMeter = 0;
    const int biYPixPerMeter = 0;
    const int biClrUsed = 0;
    const int biCirImportant = 0;

    BinaryWrite('MB', 2);
    BinaryWrite(fileSize, 4);
    BinaryWrite(0, 2);
    BinaryWrite(0, 2);
    BinaryWrite(bfOffBits, 4);
    BinaryWrite(40, 4);
    BinaryWrite(width, 4);
    BinaryWrite(height, 4);
    BinaryWrite(1, 2);
    BinaryWrite(biBitCount, 2);
    BinaryWrite(biCompression, 4);
    BinaryWrite(biSizeImage, 4);
    BinaryWrite(biXPixPerMeter, 4);
    BinaryWrite(biYPixPerMeter, 4);
    BinaryWrite(biClrUsed, 4);
    BinaryWrite(biCirImportant, 4);

    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width ; x++) {
        BinaryWrite(pixelInfo[y*width+x].b, 1);
        BinaryWrite(pixelInfo[y * width + x].g, 1);
        BinaryWrite(pixelInfo[y * width + x].r, 1);
      }
      for (int x = 0; x < PaddingSize; x++) {
        BinaryWrite(0, 1);
      }
    }
  }

private:
  template<typename T>
  void BinaryWrite(T getData, int getSize) {
    file.write(reinterpret_cast<char*>(&getData), getSize);
  }
};
