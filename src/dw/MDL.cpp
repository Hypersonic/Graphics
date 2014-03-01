#include "MDL.h"

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
        curr.erase(0, curr.find(' '));
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
      transform = transform.multiply(translate);
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
      points *= transform;
    } else if (cmdchar == 'v') {
      can.clear();
      can.draw_matrix(points, Color(0, 255, 0));
      can.render();
    } else if (cmdchar == 'g') {
      can.clear();
      can.draw_matrix(points, Color(0, 255, 0));
      can.render();
      can.saveCurrImage();
    }
  }
}
