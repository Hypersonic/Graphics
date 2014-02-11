#include <stdio.h>
#include <chrono>
#include "geometry/_shapes.h"
#include "debug.h"
#include "canvas/canvas.h"
#include "canvas/color.h"

int main(int argc, char** argv) {
  debug("Super cool stuff about graphics!\n");
  Canvas can = Canvas(640, 480);

  std::chrono::steady_clock::time_point start, end;
  start = std::chrono::steady_clock::now();
  can.clear();

  Vec2i p1 = Vec2i(300, 10);
  Vec2i p2 = Vec2i(250, 300);
  Line l = Line(p1, p2);
  
  Color col  = Color(255, 0, 0);
  Color col2 = Color(0, 255, 0);
  Color col3 = col + col2;

  Color inter1 = Color(0, 255, 0);
  Color inter2 = Color(255, 0, 0);


  Vec2i p3 = Vec2i(10, 20);
  Vec2i p4 = Vec2i(10, 30);
  Line l2 = Line(p4, p3);

  Circle c = Circle(Vec2i(100, 100), 40);
  Circle c2 = Circle(Vec2i(200, 100), 40);
  Circle c3 = Circle(Vec2i(100, 200), 40);

  Tri t = Tri(Vec2i(230, 250), Vec2i(200, 300), Vec2i(250, 340)); 

  Quad q = Quad(Vec2i(50, 50), Vec2i(80, 70), Vec2i(23, 55), Vec2i(90, 120));

  Rect r = Rect(Vec2i(3, 4), Vec2i(120, 10));

  Square s = Square(Vec2i(300, 300), 40);

  can.draw_line(l, inter1.interpolate(inter2, 100));
  can.draw_line(l2, col2);

  can.draw_tri(t, col);

  can.draw_circle(c, col);
  can.draw_circle2(c2, col);
  can.draw_circle3(c3, col);

  can.draw_quad(q, col2);

  can.draw_rect(r, col);

  can.draw_rect(s, col3);

  //for (int i = 0; i < 1000; i++) {
    //Line l = Line(Vec2i(rand() % 640, rand() % 480), Vec2i(rand() % 640, rand() % 480));
    //Color c = Color(rand() % 255, rand() % 255, rand() % 255);
    //can.draw_line(l, c);
  //}

  can.render();
  
  end = std::chrono::steady_clock::now();

  debug("%d ms\n", std::chrono::duration<int, std::milli>(std::chrono::duration_cast<std::chrono::duration<int, std::milli> >(end-start)).count());

  char buffer[256];
  fgets(buffer, sizeof(buffer), stdin);

  return 0;
}
