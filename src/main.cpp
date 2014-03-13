#include <stdio.h>
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include "geometry/_shapes.h"
#include "debug.h"
#include "canvas/canvas.h"
#include "canvas/color.h"
#include "math/Mat.h"
#include "dw/MDL.h"
#include "test.h"
#include "geometry/bezier.h"
#include "settings.h"

int main() {
  debug("Super cool stuff about graphics!\n");
#ifdef UNIT_TESTS
  Tests::RunAllTests();
#else
  Canvas can = Canvas(640, 480);

  std::chrono::steady_clock::time_point start, end;
  can.clear();

  bool running = true;
  Mat m = Mat();
  Mat trans = Mat();
  BezierCurve b;
  b.add_point(Vec4f(100, 150, 0, 1));
  //for (int i = 0; i < 200; i++) {
    //b.add_point(Vec4f(rand()%400, rand()%400, 0, 1));
  //}
  while (running) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) 
        if (e.type == SDL_QUIT)
          running = false;
        else if (e.type == SDL_MOUSEMOTION)
          b[b.num_points() - 1] = Vec4f(e.motion.x, e.motion.y, 0, 1);
        else if (e.type == SDL_MOUSEBUTTONDOWN)
          b.add_point(Vec4f(e.button.x, e.button.y, 0, 1));

    start = std::chrono::steady_clock::now();

    //std::string filename = "source_c";
    //MDLParser::ParseCmd(filename.c_str(),  can, m, trans);
    m.clear();
    can.clear();
    m = b.edges();
    can.draw_matrix(m, Color(0, 255, 0));
    can.render();
    //debug("Now, you can enter input (^D to exit)\n");
    //MDLParser::ParseCmd(std::cin, can, m, trans);
    //running = false;


    end = std::chrono::steady_clock::now();
    int ms = std::chrono::duration<int, std::milli>(
              std::chrono::duration_cast<
              std::chrono::duration<int, std::milli>>
              (end-start)).count();
    debug("%d ms\n", ms);

    if (Settings::resolution > 10.0f)
      Settings::resolution = (Settings::resolution + Settings::resolution*(1000.0f/ms)/Settings::target_fps)/2;

    char * title = reinterpret_cast<char*>(calloc(100, sizeof(char)));
    sprintf(title, "%d points, %.1f fps, %.1f resolution", b.num_points(), 1000.0/ms, Settings::resolution);
    can.set_title(title);
    free(title);

  }
#endif
}
