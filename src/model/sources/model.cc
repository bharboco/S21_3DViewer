#include "../headers/model.h"

namespace s21 {
s21::Model::Model() {
  parser_ = new s21::Parser();
  source_vertexes_ = parser_->getVertexes();
  vertexes_ = source_vertexes_;
}

s21::Model::~Model() {
  delete parser_;
  delete instance_;
  vertexes_.clear();
  source_vertexes_.clear();
}

void Model::affine(s21::Strategy* affine, double value) {
  if (affine) affine->execute(&vertexes_, &source_vertexes_, value);
}

std::vector<s21::Vertex> s21::Model::getVertexes() { return vertexes_; }
Model* Model::getInst() {
  if (instance_ == nullptr) {
    instance_ = new Model();
  }
  return instance_;
}

Model* Model::instance_ = nullptr;

std::vector<int> s21::Model::getSurfaces() { return parser_->getSurfaces(); }

void s21::Model::openFile(std::string path_to_file) {
  delete parser_;
  parser_ = new s21::Parser();
  parser_->openFile(path_to_file);
  source_vertexes_ = parser_->getVertexes();
  vertexes_ = source_vertexes_;
}
}  // namespace s21
