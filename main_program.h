#include <iostream>

class MainProgramm {
  private: 
  bool main_flag;

  public: 
  MainProgramm(bool new_flag);
  bool GetFlag();
  void SetFlag(bool new_flag);
};