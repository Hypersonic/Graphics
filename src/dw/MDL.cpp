#include "MDL.h"
#include <unistd.h>

void MDLParser::ParseCmd(const char* cmd, Canvas& can, Mat& points, Mat& transform) {
  std::ifstream file = std::ifstream(cmd);
  std::string curr;

  while (!file.eof()) {
    file >> curr;
    char cmdchar = curr[0];
    if (cmdchar == 'l') {
      Vec4f p1 = Vec4f();
      Vec4f p2 = Vec4f();
      for (int i = 0; i < 3; i++) {
        file >> p1[i];
      }

      for (int i = 0; i < 3; i++) {
        file >> p2[i];
      }

      // Put the points into our matrix
      points.addCol(p1);
      points.addCol(p2);
    } else if (cmdchar == 'i') {
      transform.clear();
      transform.addCol(Vec4f(1, 0, 0, 0));
      transform.addCol(Vec4f(0, 1, 0, 0));
      transform.addCol(Vec4f(0, 0, 1, 0));
      transform.addCol(Vec4f(0, 0, 0, 1));
    } else if (cmdchar == 's') {
      float factors[3];
      for (int i = 0; i < 3; i++) {
        file >> factors[i];
      }
      Mat scale = Mat::ScaleMat(factors[0], factors[1], factors[2]);

      transform *= scale;
      printf("\n");
    } else if (cmdchar == 't') {
      float factors[3];
      for (int i = 0; i < 3; i++) {
        file >> factors[i];
      }
      Mat translate = Mat::TransMat(factors[0], factors[1], factors[2]);
      printf("\n\nTranslate:\n");
      for (int j = 0; j < translate.cols(); j++) {
        for (int i = 0; i < 4; i++) {
          printf("%10.1f ", translate.get(j,i));
        }
        printf("\n");
      }
      printf("\n\nTransform pre:\n");
      for (int j = 0; j < transform.cols(); j++) {
        for (int i = 0; i < 4; i++) {
          printf("%10.1f ", transform.get(j,i));
        }
        printf("\n");
      }
      transform = transform.multiply(translate);
      printf("\n\nTransform post:\n");
      for (int j = 0; j < transform.cols(); j++) {
        for (int i = 0; i < 4; i++) {
          printf("%10.1f ", transform.get(j,i));
        }
        printf("\n");
      }
    } else if (cmdchar == 'x') {
      float factor;
      file >> factor;
      Mat rot = Mat::XRotMat(factor * 180 / M_PI);
      transform *= rot;
    } else if (cmdchar == 'y') {
      float factor;
      file >> factor;
      Mat rot = Mat::YRotMat(factor * 180 / M_PI);
      transform *= rot;
    } else if (cmdchar == 'z') {
      float factor;
      file >> factor;
      Mat rot = Mat::ZRotMat(factor * 180 / M_PI);
      transform *= rot;
    } else if (cmdchar == 'a') {
      printf("\n\nPoints (before):\n");
      for (int j = 0; j < points.cols(); j++) {
        for (int i = 0; i < 4; i++) {
          printf("%10.1f ", points.get(i,j));
        }
        printf("\n");
      }
      points = transform.multiply(points);
      printf("\n\nPoints (after):\n");
      for (int j = 0; j < points.cols(); j++) {
        for (int i = 0; i < 4; i++) {
          printf("%10.1f ", points.get(i,j));
        }
        printf("\n");
      }
    } else if (cmdchar == 'v') {
      debug("drawing\n");
      can.clear();
      can.draw_matrix(points, Color(0, 255, 0));
      can.render();
      sleep(1);
    } else if (cmdchar == 'g') {
      can.clear();
      can.draw_matrix(points, Color(0, 255, 0));
      can.render();
      can.saveCurrImage();
    }
  }
}
