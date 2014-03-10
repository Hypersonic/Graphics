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
  while (running) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) 
        if (e.type == SDL_QUIT)
          running = false;

    start = std::chrono::steady_clock::now();

    std::string filename = "source_c";
    MDLParser::ParseCmd(filename.c_str(),  can, m, trans);
    m.clear();
    debug("Now, you can enter input (^D to exit)\n");
    MDLParser::ParseCmd(std::cin, can, m, trans);
    running = false;


    end = std::chrono::steady_clock::now();
    int ms = std::chrono::duration<int, std::milli>(
              std::chrono::duration_cast<
              std::chrono::duration<int, std::milli>>
              (end-start)).count();
    debug("%d ms\n", ms);

    //char * title = reinterpret_cast<char*>(calloc(100, sizeof(char)));
    //sprintf(title, "%d squares, %.1f fps, %.3f ms/square", i, 1000.0/ms, (float)ms/i);
    //can.set_title(title);
    //free(title);

  }
#endif
}
