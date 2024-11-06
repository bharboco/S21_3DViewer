#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace s21 {
struct Vertex {
  float x, y, z;
};

class Parser {
 public:
  Parser();
  ~Parser();

  bool openFile(const std::string path_file);

  // GETTERS
  std::vector<Vertex> getVertexes() { return vertexes_; }
  std::vector<int> getSurfaces() { return surfaces_; }
  int getCountF();

 private:
  // TOOLS
  void readFile();
  void getVertexOfLine(std::string_view ptr_str);
  void getSurfaceOfLine(std::string_view ptr_str);

 private:
  std::ifstream file_;
  std::vector<Vertex> vertexes_;
  std::vector<int> surfaces_;
  int count_f_ = 0;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_
