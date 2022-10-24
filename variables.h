#include <iostream>

class Variable {
  private: 
  std::string type;
  std::string name;
  int line;
  bool initialized;

  public:
  Variable();
  Variable(std::string new_type, std::string new_name, int new_line, bool new_flag);
  std::string Type();
  std::string Name();
  int Line();
  bool Iinitialized();
  void setType(std::string newType);
  void setName(std::string newName);
  void setLine(int newLine);
  void setInitialize(bool newFlag);

};