#include "variables.h"

Variable::Variable() {
  type = "default";
  name = "default";
  line = 0;
  initialized = false;
}

Variable::Variable(std::string new_type, std::string new_name, std::string new_value, int new_line, bool new_flag) {
  type = new_type;
  name = new_name;
  value = new_value;
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
std::ostream& operator<<(std::ostream &os, Variable &summoner) {
  if (summoner.initialized) {
    os << "[Line: " << summoner.line << "]  " << summoner.type << ": " << summoner.name 
    << " = " << summoner.value;
  } else {
    os << "[Line: " << summoner.line << "]  " << summoner.type << ": " << summoner.name;
  }
  return os;
}
/*
std::vector<std::string> Variable::IinitializedVariables(std::string fileline) {
  std::string str_filedata;
  std::smatch match_buffer;
  std::regex initialize_var_regex("(int|double)\\s(\\w+\\s?[=]\\s?([0-9]*(\\.[0-9]*)*[;]))$");
  std::regex_match(str_filedata, match_buffer, initialize_var_regex);
  for (unsigned int i = 0; i < match_buffer.size(); i++) {
    initalized_vars.push_back(match_buffer[i]);
  }
  
}
*/