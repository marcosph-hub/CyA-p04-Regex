#include "statments.h"

Statment::Statment(std::string external_type, int external_line) {
  type = external_type;
  line = external_line;
}

std::string Statment::Type() {
  return type;
}

int Statment::Line() {
  return line;
}