#include <stdio.h>
#include "geometry/point.h"
#include "canvas/canvas.h"
#include "canvas/color.h"

int main(int argc, char** argv) {
  printf("Super cool stuff about graphics!\n");
  Canvas can = Canvas(640, 480);
  can.clear();

  Vec2i p1 = Vec2i(300, 10);
  Vec2i p2 = Vec2i(250, 50);
  Line l = Line(p1, p2);
  
  Color col  = Color(255, 0, 0);
  Color col2 = Color(0, 255, 0);

  Vec2i p3 = Vec2i(10, 20);
  Vec2i p4 = Vec2i(10, 30);
  Line l2 = Line(p4, p3);

  Circle c = Circle(Vec2i(100, 100), 40);
  Circle c2 = Circle(Vec2i(200, 100), 40);
  Circle c3 = Circle(Vec2i(100, 200), 40);

  can.draw_line(l, col);
  can.draw_line(l2, col2);
  can.draw_circle(c, col);
  can.draw_circle2(c2, col);
  can.draw_circle3(c3, col);
  can.render();

  char buffer[256];
  fgets(buffer, sizeof(buffer), stdin);

  return 0;
}
