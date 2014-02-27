#include <stdio.h>
#include <chrono>
#include <string>
#include <vector>
#include "geometry/_shapes.h"
#include "debug.h"
#include "canvas/canvas.h"
#include "canvas/color.h"
#include "math/Mat.h"

int main() {
  debug("Super cool stuff about graphics!\n");
  Canvas can = Canvas(640, 480);

  std::chrono::steady_clock::time_point start, end;
  can.clear();

  bool running = true;
  int i = 0;
  int basex = 640/2;
  int basey = 480/2;
  Mat m = Mat(4, 4);
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      if (r == c) {
        m.get(r,c) = r + c;
      } else {
        m.get(r,c) = r*c;
      }
      printf("%4d ", m.get(r,c));
    }
    printf("\n");
  }
  printf("\n\n");
  Mat p = m.multiply(m);
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      printf("%4d ", p.get(r,c));
    }
    printf("\n");
  }
  //exit(0);
  while (running) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) 
        if (e.type == SDL_QUIT)
          running = false;

    start = std::chrono::steady_clock::now();

    i++;
    i%=255;

    using namespace TwoDee;
    for (int j = 0; j < i; j++) {
      Square s = Square(Vec2i(basex - j/2,basey - j/2), j);
      s.rotate(j);
      int col = j % 255;
      can.draw_quad(s, Color(col, col, col));
    }
    debug("%d squares\n", i);

    can.render();
    can.clear();
    end = std::chrono::steady_clock::now();
    int ms = std::chrono::duration<int, std::milli>(
              std::chrono::duration_cast<
              std::chrono::duration<int, std::milli>>
              (end-start)).count();
    debug("%d ms\n", ms);

    char * title = reinterpret_cast<char*>(calloc(100, sizeof(char)));
    sprintf(title, "%d squares, %.1f fps, %.3f ms/square", i, 1000.0/ms, (float)ms/i);
    can.set_title(title);
    free(title);

  }

  //char buffer[256];
  //fgets(buffer, sizeof(buffer), stdin);

  //return 0;
}
