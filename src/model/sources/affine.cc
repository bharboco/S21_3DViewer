#include "../headers/affine.h"

namespace s21 {
Strategy::~Strategy() {}

std::vector<Vertex> Scale::execute(std::vector<Vertex> *vertexes,
                                   std::vector<Vertex> *source_vertexes,
                                   double value) {
  for (int i = 0; i < static_cast<int>(vertexes->size()); ++i) {
    vertexes->at(i).x = source_vertexes->at(i).x * abs(value);
    vertexes->at(i).y = source_vertexes->at(i).y * abs(value);
    vertexes->at(i).z = source_vertexes->at(i).z * abs(value);
  }
  return *vertexes;
}

std::vector<Vertex> RotateX::execute(std::vector<Vertex> *vertexes,
                                     std::vector<Vertex> *source_vertexes,
                                     double value) {
  source_vertexes = source_vertexes;
  for (int i = 0; i < static_cast<int>(vertexes->size()); ++i) {
    double temp_y = vertexes->at(i).y * cos(value * M_PI / 180.0) +
                    vertexes->at(i).z * sin(value * M_PI / 180.0);
    double temp_z = vertexes->at(i).z * cos(value * M_PI / 180.0) -
                    vertexes->at(i).y * sin(value * M_PI / 180.0);

    vertexes->at(i).y = temp_y;
    vertexes->at(i).z = temp_z;
    vertexes->at(i).x = vertexes->at(i).x;
  }
  return *vertexes;
}

std::vector<Vertex> RotateY::execute(std::vector<Vertex> *vertexes,
                                     std::vector<Vertex> *source_vertexes,
                                     double value) {
  source_vertexes = source_vertexes;
  for (int i = 0; i < static_cast<int>(vertexes->size()); ++i) {
    double temp_x = vertexes->at(i).x * cos(value * M_PI / 180.0) -
                    vertexes->at(i).z * sin(value * M_PI / 180.0);
    double temp_z = vertexes->at(i).z * cos(value * M_PI / 180.0) +
                    vertexes->at(i).x * sin(value * M_PI / 180.0);

    vertexes->at(i).x = temp_x;
    vertexes->at(i).z = temp_z;
    vertexes->at(i).y = vertexes->at(i).y;
  }
  return *vertexes;
}

std::vector<Vertex> RotateZ::execute(std::vector<Vertex> *vertexes,
                                     std::vector<Vertex> *source_vertexes,
                                     double value) {
  source_vertexes = source_vertexes;

  for (int i = 0; i < static_cast<int>(vertexes->size()); ++i) {
    double temp_x = vertexes->at(i).x * cos(value * M_PI / 180.0) -
                    vertexes->at(i).y * sin(value * M_PI / 180.0);
    double temp_y = vertexes->at(i).x * sin(value * M_PI / 180.0) +
                    vertexes->at(i).y * cos(value * M_PI / 180.0);

    vertexes->at(i).x = temp_x;
    vertexes->at(i).y = temp_y;
    vertexes->at(i).z = vertexes->at(i).z;
  }
  return *vertexes;
}

std::vector<Vertex> MoveX::execute(std::vector<Vertex> *vertexes,
                                   std::vector<Vertex> *source_vertexes,
                                   double value) {
  source_vertexes = source_vertexes;
  for (int i = 0; i < static_cast<int>(vertexes->size()); ++i) {
    vertexes->at(i).x += value;
  }
  return *vertexes;
}

std::vector<Vertex> MoveY::execute(std::vector<Vertex> *vertexes,
                                   std::vector<Vertex> *source_vertexes,
                                   double value) {
  source_vertexes = source_vertexes;
  for (int i = 0; i < static_cast<int>(vertexes->size()); ++i) {
    vertexes->at(i).y += value;
  }
  return *vertexes;
}

std::vector<Vertex> MoveZ::execute(std::vector<Vertex> *vertexes,
                                   std::vector<Vertex> *source_vertexes,
                                   double value) {
  source_vertexes = source_vertexes;
  for (int i = 0; i < static_cast<int>(vertexes->size()); ++i) {
    vertexes->at(i).z += value;
  }
  return *vertexes;
}
}  // namespace s21
