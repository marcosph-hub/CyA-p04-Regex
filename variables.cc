#include "variables.h"

Variable::Variable() {
  type = "default";
  name = "default";
  line = 0;
  initialized = false;
}

Variable::Variable(std::string new_type, std::string new_name, int new_line, bool new_flag) {
  type = new_type;
  name = new_name;
  line = new_line;
  initialized = new_flag;
}

std::string Variable::Type() {
  return type;
}

std::string Variable::Name() {
  return name;
}

int Variable::Line() {
  return line;
}

bool Variable::Iinitialized() {
  return initialized;
}

void Variable::setType(std::string newType) {
  type = newType;
}

void Variable::setName(std::string newName) {
  name = newName;
}

void Variable::setLine(int newLine) {
  line = newLine;
}

void Variable::setInitialize(bool newFlag) {
  initialized = newFlag;
}