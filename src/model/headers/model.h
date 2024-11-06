#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_H_

#include "affine.h"
#include "parser.h"

namespace s21 {
class Model {
 public:
  ~Model();

  // GETTERS
  std::vector<Vertex> getVertexes();
  std::vector<int> getSurfaces();
  static Model *getInst();

  // FUNCTIONS
  void openFile(std::string path_to_file);
  void affine(s21::Strategy *affine, double value);

 private:
  Model();
  s21::Strategy *affine_;
  s21::Parser *parser_;
  static s21::Model *instance_;
  std::vector<Vertex> vertexes_ = {{0, 0, 0}}, source_vertexes_ = {{0, 0, 0}};
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_H_
