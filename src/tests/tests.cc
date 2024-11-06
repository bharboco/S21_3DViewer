#include <gtest/gtest.h>

#include <sstream>

#include "../controller/controller.h"

TEST(Parser, openFileOk) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  EXPECT_EQ(parserTest->openFile("tests/main.cc"), true);
  delete parserTest;
}

TEST(Parser, openFileFail) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  EXPECT_EQ(parserTest->openFile("tests/stok.cc"), false);

  delete parserTest;
}

TEST(Parser, readFileAndPars) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test1.obj");
  EXPECT_EQ(parserTest->getVertexes().size(), 2);  // тест файл 2 вершины
  EXPECT_EQ(parserTest->getSurfaces().size(),
            12);  // тест файл 6 поверхностей x2
  delete parserTest;
}

TEST(Parser, readFileAndParsSlashSurface) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test3.obj");
  EXPECT_EQ(parserTest->getSurfaces().size(),
            6);  // тест файл 3 поверхностей x2
  delete parserTest;
}

TEST(Parser, GetSurface) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test3.obj");
  EXPECT_EQ(parserTest->getCountF(), 1);
  delete parserTest;
}

TEST(Affine, rotateX) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test2.obj");
  s21::RotateX rotateX;
  auto &&v1 = parserTest->getVertexes();
  auto &&v2 = parserTest->getVertexes();
  ASSERT_NEAR(rotateX.execute(&v1, &v2, 3.0)[0].x, 1, 0.00001);
  ASSERT_NEAR(rotateX.execute(&v1, &v2, 3.0)[0].y, 1.09905, 0.00001);
  ASSERT_NEAR(rotateX.execute(&v1, &v2, 3.0)[0].z, 0.831254, 0.00001);
  delete parserTest;
}

TEST(Affine, rotateY) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test2.obj");
  s21::RotateY rotateY;
  auto &&v1 = parserTest->getVertexes();
  auto &&v2 = parserTest->getVertexes();
  ASSERT_NEAR(rotateY.execute(&v1, &v2, 3.0)[0].x, 0.946294, 0.00001);
  ASSERT_NEAR(rotateY.execute(&v1, &v2, 3.0)[0].y, 1, 0.00001);
  ASSERT_NEAR(rotateY.execute(&v1, &v2, 3.0)[0].z, 1.14412, 0.00001);
  delete parserTest;
}
TEST(Affine, rotateZ) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test2.obj");
  s21::RotateZ rotateZ;
  auto &&v1 = parserTest->getVertexes();
  auto &&v2 = parserTest->getVertexes();
  ASSERT_NEAR(rotateZ.execute(&v1, &v2, 3.0)[0].x, 0.946294, 0.00001);
  ASSERT_NEAR(rotateZ.execute(&v1, &v2, 3.0)[0].y, 1.09905, 0.00001);
  ASSERT_NEAR(rotateZ.execute(&v1, &v2, 3.0)[0].z, 1, 0.00001);
  delete parserTest;
}

TEST(Affine, scaling) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test2.obj");
  s21::Scale scale;
  auto &&v1 = parserTest->getVertexes();
  auto &&v2 = parserTest->getVertexes();
  EXPECT_EQ(scale.execute(&v1, &v2, 3.0)[0].x, 3);
  EXPECT_EQ(scale.execute(&v1, &v2, 3.0)[0].y, 3);
  EXPECT_EQ(scale.execute(&v1, &v2, 3.0)[0].z, 3);
  delete parserTest;
}

TEST(Affine, moveX) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test2.obj");
  s21::MoveX moveX;
  auto &&v1 = parserTest->getVertexes();
  auto &&v2 = parserTest->getVertexes();
  EXPECT_EQ(moveX.execute(&v1, &v2, 3.0)[0].x, 4);
  delete parserTest;
}

TEST(Affine, moveY) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test2.obj");
  s21::MoveY moveY;
  auto &&v1 = parserTest->getVertexes();
  auto &&v2 = parserTest->getVertexes();
  EXPECT_EQ(moveY.execute(&v1, &v2, 3.0)[0].y, 4);
  delete parserTest;
}

TEST(Affine, moveZ) {
  s21::Parser *parserTest;
  parserTest = new s21::Parser();
  parserTest->openFile("tests/test_files/test2.obj");
  s21::MoveZ moveZ;
  auto &&v1 = parserTest->getVertexes();
  auto &&v2 = parserTest->getVertexes();
  EXPECT_EQ(moveZ.execute(&v1, &v2, 3.0)[0].z, 4);
  delete parserTest;
}
