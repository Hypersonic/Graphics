#include <stdio.h>
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

#define UNIT_TESTS

int main() {
  debug("Super cool stuff about graphics!\n");
#ifdef UNIT_TESTS
  Tests::RunAllTests();
#else
  Canvas can = Canvas(640, 480);

  std::chrono::steady_clock::time_point start, end;
  can.clear();

  bool running = true;
  //int i = 0;
  //int basex = 640/2;
  //int basey = 480/2;
  //std::vector<Mat> matrices = std::vector<Mat>();
  Mat m = Mat();
  Mat trans = Mat();
  while (running) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) 
        if (e.type == SDL_QUIT)
          running = false;

    start = std::chrono::steady_clock::now();

    //i++;
    //i%=255;
    //if (i == 0) matrices.clear();

    //m.addCol(Vec4f(-1, -1, 0, 1));
    //m.addCol(Vec4f(-1, 1, 0, 1));

    //m.addCol(Vec4f(-1, 1, 0, 1));
    //m.addCol(Vec4f(1, 1, 0, 1));

    //m.addCol(Vec4f(1, 1, 0, 1));
    //m.addCol(Vec4f(1, -1, 0, 1));

    //m.addCol(Vec4f(1, -1, 0, 1));
    //m.addCol(Vec4f(-1, -1, 0, 1));

    //float theta = (float) i / 64;
    //Mat rotX = Mat::XRotMat(theta);
    //Mat rotY = Mat::YRotMat(theta);
    //Mat rotZ = Mat::ZRotMat(theta);
    //Mat trans = Mat::TransMat(basex, basey, 0);
    //Mat scal = Mat::ScaleMat(i, i, i);

    //m = m.multiply(scal);
    //m = m.multiply(rotX);
    //m = m.multiply(rotY);
    //m = m.multiply(rotZ);
    //m = m.multiply(trans);

    //matrices.push_back(m);

    //for (size_t j = 0; j < matrices.size(); j++) {
      //can.draw_matrix(matrices[j], Color(j, j, j));
    //}
    //debug("%d squares\n", i);

    std::string filename = "source_c";
    MDLParser::ParseCmd(filename.c_str(),  can, m, trans);
    m.clear();
    //running = false;

    //can.render();
    //can.clear();
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
