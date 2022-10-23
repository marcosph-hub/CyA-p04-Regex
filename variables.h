#include <iostream>

class Variable {
  private: 
  std::string type;
  std::string name;
  int line;
  bool initialized;

  public:
  Variable();
  Variable(std::string type, std::string name, int line, bool initialized);
  std::string Type();
  std::string Name();
  int Line();
  bool Iinitialized();
  void setType(std::string newType);
  void setName(std::string newName);
  void setLine(int newLine);
  void setInitialize(bool newFlag);

};