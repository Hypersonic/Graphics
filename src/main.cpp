#include <stdio.h>
#include "geometry/point.h"
#include "canvas/canvas.h"
#include "canvas/color.h"

int main(int argc, char** argv) {
  printf("Super cool stuff about graphics!\n");
  Canvas can = Canvas(640, 480);
  can.clear();

  Vec2i p1 = Vec2i(10, 10);
  Vec2i p2 = Vec2i(100, 50);
  Line l = Line(p1, p2);
  Color col = Color(255, 0, 0);

  Vec2i p3 = Vec2i(10, 20);
  Vec2i p4 = Vec2i(10, 50);
  Line l2 = Line(p4, p3);

  can.draw_line(l, col);
  can.draw_line(l2, col);
  can.render();

  char buffer[256];
  fgets(buffer, sizeof(buffer), stdin);

  return 0;
}
