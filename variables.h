#include <iostream>
#include <vector>
#include <regex>
#include <string>

class Variable {
  private: 
  std::string type;
  std::string name;
  std::string value;
  int line;
  bool initialized;
  //std::vector<std::string> initalized_vars;
  //std::vector<std::string> uninitalized_vars;

  public:
  Variable();
  Variable(std::string new_type, std::string new_name, std::string new_value, int new_line, bool new_flag);
  std::string Type();
  std::string Name();
  int Line();
  bool Iinitialized();
  void setType(std::string newType);
  void setName(std::string newName);
  void setLine(int newLine);
  void setInitialize(bool newFlag);
  friend std::ostream& operator<<(std::ostream &os, Variable &summoner);
  //std::vector<std::string> IinitializedVariables(std::string fileline);
  //std::vector<std::string> UninitializedVariables(std::string fileline);

};