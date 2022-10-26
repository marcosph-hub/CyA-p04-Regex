#include <iostream>

class Statment {
  private:
  std::string type;
  int line;
  public:
  Statment(std::string external_type, int external_line);
  std::string Type();
  int Line();
};