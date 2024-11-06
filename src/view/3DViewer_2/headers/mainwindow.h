#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QGridLayout>
#include <QMainWindow>

#include "glview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent, s21::Controller *controller);
  ~MainWindow();

 private:
  void scalingUp();
  void scalingDown();
  void setDefaultSettings();

 private slots:
  void on_sliderScaling_valueChanged(int value);

  void on_sliderRotateX_valueChanged(int value);

  void on_sliderRotateZ_valueChanged(int value);

  void on_sliderRotateY_valueChanged(int value);

  void on_sliderMoveX_valueChanged(int value);

  void on_sliderMoveY_valueChanged(int value);

  void on_sliderMoveZ_valueChanged(int value);

  void on_selectFile_clicked();

  void on_scalingUp_clicked();

  void on_scalingDown_clicked();

  void on_rotateYUp_clicked();

  void on_rotateXDown_clicked();

  void on_rotateYDown_clicked();

  void on_rotateXUp_clicked();

  void on_rotateZUp_clicked();

  void on_rotateZDown_clicked();

  void on_inputValueScale_valueChanged(double arg1);

  void on_moveXDown_clicked();

  void on_moveXUp_clicked();

  void on_moveYDown_clicked();

  void on_moveYUp_clicked();

  void on_moveZDown_clicked();

  void on_moveZUp_clicked();

  void on_inputValueRotateX_valueChanged(double arg1);

  void on_inputValueRotateY_valueChanged(double arg1);

  void on_inputValueRotateZ_valueChanged(double arg1);

  void on_inputValueMoveX_valueChanged(double arg1);

  void on_inputValueMoveY_valueChanged(double arg1);

  void on_inputValueMoveZ_valueChanged(double arg1);

 private:
  Ui::MainWindow *ui;
  s21::Controller *controller_;
};
#endif  // MAINWINDOW_H
