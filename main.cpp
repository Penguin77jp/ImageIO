#include <vector>
#include <iostream>
#include "bmp.h"

int main() {
  std::vector<PixelInfo> pix;
  for (int i = 0; i < 403*500; i++) {
    pix.push_back(PixelInfo((int)(255.0*i/403/500),0,0));
  }

  //auto test = bmp(400, 500,pix);
  //test.Output("test.bmp");

  auto test = bmp(std::cin);
}
