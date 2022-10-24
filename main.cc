#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

void FileManagment(const std::string INPUT_FILENAME, const std::string OUTPUT_FILENAME) {
  std::ifstream input(INPUT_FILENAME);
  std::ofstream ouput(OUTPUT_FILENAME);
  std::vector<std::string> filedata;
  std::string str_filedata;
  std::smatch str_match;
  const std::regex initialize_var_regex("(int|double)\s(\w+)\s?=(\s?[+|-]?\d+\.?\d*)");
  while(!input.eof()) {
    std::getline(input,str_filedata);
    std::regex_match(str_filedata, str_match, initialize_var_regex);
    for (auto i : str_match) {
      filedata.push_back(i);
    }
    //filedata.push_back(str_filedata);
  }

  for (unsigned int i = 0; i < filedata.size(); i++) {
    std::cout << filedata[i] << std::endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc - 1 != 2) {
    if (argc - 1 == 1) {
      std::string help = argv[1];
      if (help == "--help") {
        std::cout << "Este programa muestra la estrucutura de un fichero de código de c++ ";
        std::cout << "Debes introducir tres parámetros:" << std::endl;
        std::cout << "./p01_strings filein.txt fileout.txt opcode\n";
        std::cout << "code.cc: un fichero .cc que especifica el código a analizar\n";
        std::cout << "codeschema.txt: un fichero .txt de salida el análisis del fichero de código analizado\n";
        return 1;
      } 
    }
    std::cerr << "ERROR: Modo de empleo: ./p04_code_anlyzer code.cc codeschema.txt\n";
    std::cerr << "Pruebe ./p04_code_anlyzer --help’ para más información.\n";
    return 1;
  }
  const std::string INPUT_FILENAME(argv[1]);
  const std::string OUTPUT_FILENAME(argv[2]);

  FileManagment(INPUT_FILENAME, OUTPUT_FILENAME);
}
// TODO: crear clase variable, recorrer fichero en busca de varibales y probar si funciona