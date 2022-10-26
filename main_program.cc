#include "main_program.h"

MainProgramm::MainProgramm(bool new_flag) {
  main_flag = new_flag;
}

bool MainProgramm::GetFlag() {
  return main_flag;
}

void MainProgramm::SetFlag(bool new_flag) {
  main_flag = new_flag;
}