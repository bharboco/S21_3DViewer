#include "controller.h"

namespace s21 {
s21::Controller::Controller(s21::Model *model) : model_(model) {}

s21::Controller::~Controller() {}

void s21::Controller::setScaling(double scale_value_) {
  Scale s;
  model_->affine(&s, scale_value_);
}

void s21::Controller::setRotateX(double a) {
  RotateX r_x;
  model_->affine(&r_x, a);
}

void s21::Controller::setRotateY(double a) {
  RotateY r_y;
  model_->affine(&r_y, a);
}

void s21::Controller::setRotateZ(double a) {
  RotateZ r_z;
  model_->affine(&r_z, a);
}

void s21::Controller::setMoveX(double a) {
  MoveX m_x;
  model_->affine(&m_x, a);
}

void s21::Controller::setMoveY(double a) {
  MoveY m_y;
  model_->affine(&m_y, a);
}

void s21::Controller::setMoveZ(double a) {
  MoveZ m_z;
  model_->affine(&m_z, a);
}

std::vector<s21::Vertex> s21::Controller::getVertexes() {
  return model_->getVertexes();
}

std::vector<int> s21::Controller::getSurfaces() {
  return model_->getSurfaces();
}

void s21::Controller::openFile(std::string path_to_file) {
  model_->openFile(path_to_file);
}
}  // namespace s21
