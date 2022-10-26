#include <iostream>

class SingleComment {
  private: 
  std::string body;
  int line;

  public:
  SingleComment(int external_line);
  int Line();
  std::string getContent();
  void setContent(std::string new_content);
};