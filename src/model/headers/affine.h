#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_AFFINE_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_AFFINE_H_

#include <cmath>

#include "parser.h"

namespace s21 {
class Strategy {
 public:
  virtual ~Strategy();
  virtual std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                                      std::vector<Vertex> *source_vertexes,
                                      double value) = 0;
};

class Scale : public Strategy {
 public:
  Scale() = default;
  std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                              std::vector<Vertex> *source_vertexes,
                              double value) override;
};

class RotateX : public Strategy {
 public:
  RotateX() = default;
  std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                              std::vector<Vertex> *source_vertexes,
                              double value) override;
};

class RotateY : public Strategy {
 public:
  RotateY() = default;
  std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                              std::vector<Vertex> *source_vertexes,
                              double value) override;
};

class RotateZ : public Strategy {
 public:
  RotateZ() = default;
  std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                              std::vector<Vertex> *source_vertexes,
                              double value) override;
};

class MoveX : public Strategy {
 public:
  MoveX() = default;
  std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                              std::vector<Vertex> *source_vertexes,
                              double value) override;
};

class MoveY : public Strategy {
 public:
  MoveY() = default;
  std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                              std::vector<Vertex> *source_vertexes,
                              double value) override;
};

class MoveZ : public Strategy {
 public:
  MoveZ() = default;
  std::vector<Vertex> execute(std::vector<Vertex> *vertexes,
                              std::vector<Vertex> *source_vertexes,
                              double value) override;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_AFFINE_H_
