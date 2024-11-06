#include "headers/glview.h"

glView::glView(QWidget *parent) : QOpenGLWidget(parent) {}

glView::~glView() {}

void glView::initializeGL() { glClearColor(1.0f, 0.0f, 0.0f, 1.0f); }

void glView::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void glView::paintGL() {
  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glColor3f(0.7, 0.7, 0.7);
  controller_->setScaling(scale_value_);
  controller_->setRotateX(rotate_value_x_);
  controller_->setRotateZ(rotate_value_z_);
  controller_->setRotateY(rotate_value_y_);
  controller_->setMoveX(shift_x_);
  controller_->setMoveY(shift_y_);
  controller_->setMoveZ(shift_z_);
  std::vector<s21::Vertex> vers = controller_->getVertexes();
  std::vector<int> indcs = controller_->getSurfaces();
  glBegin(GL_LINES);
  for (int i = 0; i < indcs.size(); ++i) {
    int num_pnt = indcs.at(i);
    glVertex3f((vers.at(num_pnt - 1).x) * (scale_value_ / 10.0),
               (vers.at(num_pnt - 1).y) * (scale_value_ / 10.0),
               (vers.at(num_pnt - 1).z) * (scale_value_ / 10.0));
  }
  glEnd();
}

// ROTATE
void glView::setRotateValueX(int value) { rotate_value_x_ = value; }

void glView::setRotateValueY(int value) { rotate_value_y_ = value; }

void glView::setRotateValueZ(int value) { rotate_value_z_ = value; }

// MOVE
void glView::setMoveValueX(int value) { shift_x_ = value; }

void glView::setMoveValueY(int value) { shift_y_ = value; }

void glView::setMoveValueZ(int value) { shift_z_ = value; }

void glView::setValueScale(double value) { scale_value_ = value; }

void glView::setControllerData(s21::Controller *controller) {
  controller_ = controller;
}

// GETTERS
double glView::getValueScale() { return scale_value_; }

int glView::getRotateValueX() { return rotate_value_x_; }

int glView::getRotateValueY() { return rotate_value_y_; }

int glView::getRotateValueZ() { return rotate_value_z_; }

int glView::getMoveValueX() { return shift_x_; }

int glView::getMoveValueY() { return shift_y_; }

int glView::getMoveValueZ() { return shift_z_; }

bool glView::getStatusFilePath() { return status_file_path_; }

int glView::getVertex() { return controller_->getVertexes().size(); }

int glView::getSurface() { return controller_->getSurfaces().size(); }

int glView::getCountEdges() { return controller_->getSurfaces().size() / 4; }

QString glView::getFileName() { return file_name_; }

void glView::openFile() {
  QString path =
      QFileDialog::getOpenFileName(this, "Select.obj file", QDir::currentPath(),
                                   "OBJ Files (*.obj);;All Files (*)");
  if (!path.isEmpty()) {
    QFileInfo fileInfo(path);
    file_name_ = fileInfo.fileName();
    status_file_path_ = true;
    controller_->openFile(path.toStdString());
  } else
    status_file_path_ = false;
}
