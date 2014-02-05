#include <stdio.h>
#include "geometry/point.h"
#include "canvas/canvas.h"

int main(int argc, char** argv) {
  printf("Super cool stuff about graphics!\n");
  Canvas can = Canvas(640, 480);
  can.clear();

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      can.putpixel(i, j, 255, 0, 0, 0);
    }
  }
  can.render();

  char buffer[256];
  fgets(buffer, sizeof(buffer), stdin);

  return 0;
}
