#include "bmp.h"

bmp::bmp(const int width, const int height, std::vector<PixelInfo> getPix) : width(width), height(height), pixData(getPix) {

  bfOffBits = 54;
  biBitCount = 24;
  biCompression = 0;
  PaddingSize = width * 3 % 4 == 0 ? 0 : 4 - width * 3 % 4;
  biSizeImage = 3 * width * height;
  fileSize = 14 + 44 + biSizeImage;
  biXPixPerMeter = 0;
  biYPixPerMeter = 0;
  biClrUsed = 0;
  biCirImportant = 0;
}

bmp::bmp(std::istream &cin) {
  if (cin) {
    std::string loadFileName;
    cin >> loadFileName;
    std::ifstream loadFile(loadFileName,std::ios::binary | std::ios::in);
    if (loadFile.is_open()) {
      loadFile.seekg(0, std::ios_base::end);
      int _filesize = loadFile.tellg();
      loadFile.seekg(0, std::ios_base::beg);
      std::vector<char> buffer(_filesize);
      loadFile.read(&buffer[0],_filesize);

      std::cout << buffer[2];
    } else {
      std::cout << "cant open" << std::endl;
    }
  }
}

void bmp::Output(const char* fileName) {
  file = std::ofstream(fileName, std::ios::binary | std::ios::out);
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
    for (int x = 0; x < width; x++) {
      BinaryWrite(IntMax(pixData[(int)(y * width + x)].b), 1);
      BinaryWrite(IntMax(pixData[(int)(y * width + x)].g), 1);
      BinaryWrite(IntMax(pixData[(int)(y * width + x)].r), 1);
    }
    for (int x = 0; x < PaddingSize; x++) {
      BinaryWrite(0, 1);
    }
  }
}

int IntMax(const double getInt) {
  if (getInt > 1.0) {
    return 255;
  } else {
    return (int)(getInt * 255);
  }
}
