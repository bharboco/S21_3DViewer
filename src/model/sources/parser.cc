#include "../headers/parser.h"

namespace s21 {
Parser::Parser() : vertexes_() {}

Parser::~Parser() {}

bool Parser::openFile(const std::string path_file) {
  file_.open(path_file);
  if (!file_.is_open()) {
    file_.close();
    return false;
  }
  readFile();
  file_.close();
  return true;
}

void Parser::readFile() {
  std::string read_str;
  while (!file_.eof()) {
    std::getline(file_, read_str);
    char* ptr_str = const_cast<char*>(read_str.c_str());
    if (*ptr_str == 'v' && *(ptr_str + 1) == ' ') {
      size_t space_count = strspn(ptr_str + 1, " ");
      ptr_str += space_count;
      getVertexOfLine(ptr_str + 1);
    } else if (*ptr_str == 'f' && *(ptr_str + 1) == ' ') {
      size_t space_count = strspn(ptr_str + 1, " ");
      ptr_str += space_count;
      getSurfaceOfLine(ptr_str + 1);
    }
  }
}

void Parser::getVertexOfLine(std::string_view ptr_str) {
  std::string number = "";
  Vertex temp = {0, 0, 0};
  int count = 0;
  for (size_t i = 0; i <= ptr_str.size(); ++i) {
    if (((std::isdigit(ptr_str[i]) || ptr_str[i] == '-' ||
          ptr_str[i] == '.')) &&
        count < 4) {
      number += ptr_str[i];
    } else if (ptr_str[i] == ' ' || ptr_str[i] == '\0' || ptr_str[i] == '\n') {
      count++;
      if (count == 1)
        temp.x = std::stod(number);
      else if (count == 2)
        temp.y = std::stod(number);
      else if (count == 3)
        temp.z = std::stod(number);
      number.clear();
    }
  }
  vertexes_.push_back(temp);
}

void Parser::getSurfaceOfLine(std::string_view ptr_str) {
  count_f_++;
  std::string number = "";
  bool first_number = true;
  int temp = 0;
  for (size_t i = 0; i < ptr_str.size(); ++i) {
    if (ptr_str[i] == '/') {
      size_t space_pos =
          strcspn(reinterpret_cast<const char*>(ptr_str.data()) + i, " ");
      i += space_pos;
    }
    if ((std::isdigit(ptr_str[i]) || ptr_str[i] == '-' || ptr_str[i] == '.')) {
      number += ptr_str[i];
    }
    if (ptr_str[i] == ' ' || ptr_str[i] == '\0' || ptr_str[i] == '\n') {
      if (first_number) {
        temp = std::stod(number);
        surfaces_.push_back(std::stod(number));
        first_number = false;
      } else {
        surfaces_.push_back(std::stod(number));
        surfaces_.push_back(std::stod(number));
      }
      number.clear();
    }
  }

  // Добавляем оставшуюся часть строки, если она есть
  if (!number.empty()) {
    surfaces_.push_back(std::stod(number));
    surfaces_.push_back(std::stod(number));
  }

  // Добавляем temp дважды, если это необходимо
  surfaces_.push_back(temp);
}

int Parser::getCountF() { return count_f_; }

}  // namespace s21
