#include "headers/mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, s21::Controller *controller)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  ui->widget->setControllerData(controller_);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_sliderScaling_valueChanged(int value) {
  ui->widget->setValueScale(value / 10.0);
  ui->inputValueScale->setValue(value / 10.0);
  ui->widget->update();
}

// ROTATE
void MainWindow::on_sliderRotateX_valueChanged(int value) {
  ui->widget->setRotateValueX(value);
  ui->inputValueRotateX->setValue(ui->sliderRotateX->value());
  ui->widget->update();
}

void MainWindow::on_sliderRotateY_valueChanged(int value) {
  ui->widget->setRotateValueY(value);
  ui->inputValueRotateY->setValue(ui->sliderRotateY->value());
  ui->widget->update();
}

void MainWindow::on_sliderRotateZ_valueChanged(int value) {
  ui->widget->setRotateValueZ(value);
  ui->inputValueRotateZ->setValue(ui->sliderRotateZ->value());
  ui->widget->update();
}

// MOVE
void MainWindow::on_sliderMoveX_valueChanged(int value) {
  ui->widget->setMoveValueX(value);
  ui->inputValueMoveX->setValue(ui->sliderMoveX->value());
  ui->widget->update();
}

void MainWindow::on_sliderMoveY_valueChanged(int value) {
  ui->widget->setMoveValueY(value);
  ui->inputValueMoveY->setValue(ui->sliderMoveY->value());
  ui->widget->update();
}

void MainWindow::on_sliderMoveZ_valueChanged(int value) {
  ui->widget->setMoveValueZ(value);
  ui->inputValueMoveZ->setValue(ui->sliderMoveZ->value());
  ui->widget->update();
}

void MainWindow::on_selectFile_clicked() {
  ui->widget->openFile();
  if (ui->widget->getStatusFilePath()) {
    setDefaultSettings();
    ui->numbOfVertex->setText(QString::number(ui->widget->getVertex()));
    ui->numbOfSurface->setText(QString::number(ui->widget->getCountEdges()));
    ui->labelNameFile->setText(ui->widget->getFileName());
  }
}

void MainWindow::setDefaultSettings() {
  on_sliderScaling_valueChanged(15);
  on_sliderRotateX_valueChanged(0);
  on_sliderRotateY_valueChanged(0);
  on_sliderRotateZ_valueChanged(0);
  on_sliderMoveX_valueChanged(0);
  on_sliderMoveY_valueChanged(0);
  on_sliderMoveZ_valueChanged(0);
  on_inputValueScale_valueChanged(1.5);
  on_inputValueRotateX_valueChanged(0);
  on_inputValueRotateY_valueChanged(0);
  on_inputValueRotateZ_valueChanged(0);
  on_inputValueMoveX_valueChanged(0);
  on_inputValueMoveY_valueChanged(0);
  on_inputValueMoveZ_valueChanged(0);
}

void MainWindow::scalingUp() {
  if (ui->widget->getValueScale() < 3) {
    ui->widget->setValueScale(ui->widget->getValueScale() + 0.1);
    ui->sliderScaling->setValue(ui->sliderScaling->value() + 1);
    ui->inputValueScale->setValue(ui->sliderScaling->value() / 10.0);
    ui->widget->update();
  }
}

void MainWindow::scalingDown() {
  if (ui->widget->getValueScale() > 0.1) {
    ui->widget->setValueScale(ui->widget->getValueScale() - 0.1);
    ui->sliderScaling->setValue(ui->sliderScaling->value() - 1);
    ui->inputValueScale->setValue(ui->sliderScaling->value() / 10.0);
    ui->widget->update();
  }
}

void MainWindow::on_scalingUp_clicked() { scalingUp(); }

void MainWindow::on_scalingDown_clicked() { scalingDown(); }

void MainWindow::on_rotateXDown_clicked() {
  if (ui->widget->getRotateValueX() > 0) {
    ui->widget->setRotateValueX(ui->widget->getRotateValueX() - 1);
    ui->sliderRotateX->setValue(ui->sliderRotateX->value() - 1);
    ui->inputValueRotateX->setValue(ui->sliderRotateX->value());
    ui->widget->update();
  }
}

void MainWindow::on_rotateXUp_clicked() {
  if (ui->widget->getRotateValueX() < 360) {
    ui->widget->setRotateValueX(ui->widget->getRotateValueX() + 1);
    ui->sliderRotateX->setValue(ui->sliderRotateX->value() + 1);
    ui->inputValueRotateX->setValue(ui->sliderRotateX->value());
    ui->widget->update();
  }
}

void MainWindow::on_inputValueRotateX_valueChanged(double arg1) {
  if (arg1 >= 0 && arg1 <= 360) {
    ui->widget->setRotateValueX(arg1);
    ui->sliderRotateX->setValue(arg1);
    ui->widget->update();
  }
}

void MainWindow::on_rotateYDown_clicked() {
  if (ui->widget->getRotateValueY() > 0) {
    ui->widget->setRotateValueY(ui->widget->getRotateValueY() - 1);
    ui->sliderRotateY->setValue(ui->sliderRotateY->value() - 1);
    ui->widget->update();
  }
}

void MainWindow::on_rotateYUp_clicked() {
  if (ui->widget->getRotateValueY() < 360) {
    ui->widget->setRotateValueY(ui->widget->getRotateValueY() + 1);
    ui->sliderRotateY->setValue(ui->sliderRotateY->value() + 1);
    ui->widget->update();
  }
}

void MainWindow::on_inputValueRotateY_valueChanged(double arg1) {
  if (arg1 >= 0 && arg1 <= 360) {
    ui->widget->setRotateValueY(arg1);
    ui->sliderRotateY->setValue(arg1);
    ui->widget->update();
  }
}

void MainWindow::on_rotateZDown_clicked() {
  if (ui->widget->getRotateValueZ() > 0) {
    ui->widget->setRotateValueZ(ui->widget->getRotateValueZ() - 1);
    ui->sliderRotateZ->setValue(ui->sliderRotateZ->value() - 1);
    ui->widget->update();
  }
}

void MainWindow::on_rotateZUp_clicked() {
  if (ui->widget->getRotateValueZ() < 360) {
    ui->widget->setRotateValueZ(ui->widget->getRotateValueZ() + 1);
    ui->sliderRotateZ->setValue(ui->sliderRotateZ->value() + 1);
    ui->widget->update();
  }
}

void MainWindow::on_inputValueRotateZ_valueChanged(double arg1) {
  if (arg1 >= 0 && arg1 <= 360) {
    ui->widget->setRotateValueZ(arg1);
    ui->sliderRotateZ->setValue(arg1);
    ui->widget->update();
  }
}

void MainWindow::on_inputValueScale_valueChanged(double arg1) {
  if (arg1 >= 0.1 && arg1 <= 3) {
    ui->widget->setValueScale(arg1);
    ui->sliderScaling->setValue(arg1 * 10);
    ui->widget->update();
  }
}

void MainWindow::on_moveXDown_clicked() {
  if (ui->widget->getMoveValueX() > -15) {
    ui->widget->setMoveValueX(ui->widget->getMoveValueX() - 1);
    ui->sliderMoveX->setValue(ui->sliderMoveX->value() - 1);
    ui->widget->update();
  }
}

void MainWindow::on_moveXUp_clicked() {
  if (ui->widget->getMoveValueX() < 15) {
    ui->widget->setMoveValueX(ui->widget->getMoveValueX() + 1);
    ui->sliderMoveX->setValue(ui->sliderMoveX->value() + 1);
    ui->widget->update();
  }
}

void MainWindow::on_inputValueMoveX_valueChanged(double arg1) {
  if (arg1 >= -15 && arg1 <= 15) {
    ui->widget->setMoveValueX(arg1);
    ui->sliderMoveX->setValue(arg1);
    ui->widget->update();
  }
}

void MainWindow::on_moveYDown_clicked() {
  if (ui->widget->getMoveValueY() > -15) {
    ui->widget->setMoveValueY(ui->widget->getMoveValueY() - 1);
    ui->sliderMoveY->setValue(ui->sliderMoveY->value() - 1);
    ui->widget->update();
  }
}

void MainWindow::on_moveYUp_clicked() {
  if (ui->widget->getMoveValueY() < 15) {
    ui->widget->setMoveValueY(ui->widget->getMoveValueY() + 1);
    ui->sliderMoveY->setValue(ui->sliderMoveY->value() + 1);
    ui->widget->update();
  }
}

void MainWindow::on_inputValueMoveY_valueChanged(double arg1) {
  if (arg1 >= -15 && arg1 <= 15) {
    ui->widget->setMoveValueY(arg1);
    ui->sliderMoveY->setValue(arg1);
    ui->widget->update();
  }
}

void MainWindow::on_moveZDown_clicked() {
  if (ui->widget->getMoveValueZ() > -15) {
    ui->widget->setMoveValueZ(ui->widget->getMoveValueZ() - 1);
    ui->sliderMoveZ->setValue(ui->sliderMoveZ->value() - 1);
    ui->widget->update();
  }
}

void MainWindow::on_moveZUp_clicked() {
  if (ui->widget->getMoveValueZ() < 15) {
    ui->widget->setMoveValueZ(ui->widget->getMoveValueZ() + 1);
    ui->sliderMoveZ->setValue(ui->sliderMoveZ->value() + 1);
    ui->widget->update();
  }
}

void MainWindow::on_inputValueMoveZ_valueChanged(double arg1) {
  if (arg1 >= -15 && arg1 <= 15) {
    ui->widget->setMoveValueZ(arg1);
    ui->sliderMoveZ->setValue(arg1);
    ui->widget->update();
  }
}
