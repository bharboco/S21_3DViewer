#ifndef CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/headers/model.h"

namespace s21 {
class Controller {
 public:
  Controller(s21::Model *model);
  ~Controller();

  // SETTERS
  void setScaling(double scale_value_);
  void setRotateX(double a);
  void setRotateY(double a);
  void setRotateZ(double a);
  void setMoveX(double a);
  void setMoveY(double a);
  void setMoveZ(double a);

  // GETTERS
  std::vector<Vertex> getVertexes();
  std::vector<int> getSurfaces();

  void openFile(std::string path_to_file);

 private:
  s21::Model *model_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_