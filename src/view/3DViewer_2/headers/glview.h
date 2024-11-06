#ifndef GLVIEW_H
#define GLVIEW_H

#include <QFileDialog>
#define GL_SILENCE_DEPRECATION
#include <QOpenGLWidget>
#include <QTimer>

#include "../../controller/controller.h"

class glView : public QOpenGLWidget {
 public:
  glView(QWidget *parent = 0);
  ~glView();
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void drawLines();
  // ROTATE
  void setRotateValueX(int value);
  void setRotateValueY(int value);
  void setRotateValueZ(int value);

  // MOVE
  void setMoveValueX(int value);
  void setMoveValueY(int value);
  void setMoveValueZ(int value);

  void setValueScale(double value);

  void setControllerData(s21::Controller *controller);

  // GETTERS
  double getValueScale();
  int getRotateValueX();
  int getRotateValueY();
  int getRotateValueZ();
  int getMoveValueX();
  int getMoveValueY();
  int getMoveValueZ();
  int getVertex();
  int getSurface();
  int getCountEdges();
  QString getFileName();

  void openFile();
  bool getStatusFilePath();

 private:
  int rotate_value_x_ = 0, rotate_value_y_ = 0, rotate_value_z_ = 0;
  double scale_value_ = 1.5;
  double shift_x_ = 0, shift_y_ = 0, shift_z_ = 0;
  bool status_file_path_ = false;
  s21::Controller *controller_;
  QString file_name_;
};

#endif  // GLVIEW_H
