#include "MDL.h"

void MDLParser::ParseCmd(const char* cmd, Canvas& can, Mat& points, Mat& transform) {
  std::ifstream file = std::ifstream(cmd);
  ParseCmd(file, can, points, transform);
}

void MDLParser::ParseCmd(std::istream& file, Canvas& can, Mat& points, Mat& transform) {
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
      p1[3] = 1;
      p2[3] = 1;

      // Put the points into our matrix
      points.addCol(p1);
      points.addCol(p2);
    } else if (cmdchar == 'i') {
      transform = Mat::Identity();
    } else if (cmdchar == 's') {
      float factors[3];
      for (int i = 0; i < 3; i++) {
        file >> factors[i];
      }
      Mat scale = Mat::ScaleMat(factors[0], factors[1], factors[2]);

      transform *= scale;
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
      points = transform.multiply(points);
    } else if (cmdchar == 'v') {
      can.clear();
      can.draw_matrix(points, Color(0, 255, 0));
      can.render();
    } else if (cmdchar == 'g') {
      std::string filename = "img.ppm";
      can.clear();
      can.draw_matrix(points, Color(0, 255, 0));
      can.render();
      can.saveCurrImage(filename.c_str());
    }
  }
}
