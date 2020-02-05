#include <vector>
#include <iostream>
#include "bmp.h"

int main() {
  std::vector<PixelInfo> pix(403*500);
  for (int i = 0; i < 403*500; i++) {
    pix[i] = PixelInfo(1.0*i/403/500,0,0);
  }

  bmp("test.bmp", 400, 500,pix);
  bmp("padding1.bmp", 401, 500,pix);
  bmp("padding2.bmp", 402, 500,pix);
  bmp("padding3.bmp", 403, 500,pix);
}
