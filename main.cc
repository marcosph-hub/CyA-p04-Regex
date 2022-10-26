#include <fstream>
#include "variables.h"
#include "comments.h"
#include "single_comment.h"
#include "statments.h"
#include "main_program.h"


void FileManagment(const std::string INPUT_FILENAME, const std::string OUTPUT_FILENAME) {
  std::ifstream input(INPUT_FILENAME);
  std::ofstream output(OUTPUT_FILENAME);

  std::vector<Variable> variables_vector;
  std::vector<Comment> comments_vector;
  std::vector<SingleComment> single_comments_vector;
  std::vector<Statment> statments_vector;
  MainProgramm main_program_obj(false);

  std::regex initialize_var_regex("(int|double)\\s((\\w+)\\s?[=]\\s?([0-9]*(\\.[0-9]*)*)[;])$");
  std::regex uninitialize_var_regex("(int|double)\\s((\\w+)[;])$");
  std::regex comment_begin_regex("(\\/\\*+)");
  std::regex comment_content_regex("((\\s*\\w*\\s*)*)|((\\*\\s*\\w*\\s*)*)");
  std::regex comment_end_regex("(\\*+\\/)");
  std::regex single_comment_regex("(^\\/\\/(.*))");
  std::regex statments_regex("(for|while)\\s");
  std::regex main_regex(".*\\smain\\s\\(");
  
  std::smatch search_buffer_init_var;
  std::smatch search_buffer_uninit_var;
  std::smatch multicomm_buffer;
  std::smatch singcomm_buffer;
  std::smatch statment_buffer;
  std::smatch main_buffer;

  std::string str_filedata;
  const std::string UNDEFINED_STR = "UNDEFINED";
  const std::string END_MULTICOMMENT = "*/";
  std::string comment_body = UNDEFINED_STR;

  int line = 1;
  while(!input.eof()) {
    std::getline(input,str_filedata);

    // ---VARIABLES---

    if (std::regex_search(str_filedata, search_buffer_init_var, initialize_var_regex)) {
      Variable file_variable(search_buffer_init_var[1], search_buffer_init_var[3], search_buffer_init_var[4], line, true);
      variables_vector.push_back(file_variable);
    }

    if (std::regex_search(str_filedata, search_buffer_uninit_var, uninitialize_var_regex)) {
      Variable file_variable(search_buffer_uninit_var[1], search_buffer_uninit_var[3], UNDEFINED_STR, line, false);
      variables_vector.push_back(file_variable);
    }

    // ---COMENTARIOS---
    std::vector<std::string> comment_content;
    if (std::regex_search(str_filedata,multicomm_buffer,comment_begin_regex)) {
      Comment first_comment(true, false, false, {}, line);
      while (str_filedata != END_MULTICOMMENT) {
        std::getline(input,str_filedata);
        comment_content.push_back(str_filedata);
        line++;
      }
      
      first_comment.setBody(comment_content);
      comments_vector.push_back(first_comment);

    }
    if (std::regex_search(str_filedata,multicomm_buffer,comment_end_regex)) {
      Comment last_comment(false, false, true, {}, line);
      comments_vector.push_back(last_comment);
    }

    if (std::regex_search(str_filedata,singcomm_buffer,single_comment_regex)) {
      std::string content = singcomm_buffer[0];
      SingleComment single_comment(line);
      single_comment.setContent(content);
      single_comments_vector.push_back(single_comment);
    }

    // ---STATMENTS--
    if (std::regex_search(str_filedata, statment_buffer, statments_regex)) {
      Statment statment(statment_buffer[0], line);
      statments_vector.push_back(statment);
    }
    // ---MAIN PROGRAM--
    if (std::regex_search(str_filedata, main_buffer, main_regex)) {
      main_program_obj.SetFlag(true);
    }


    line++;
  }

  
  output << "DESCRIPTION:\n";
  for (unsigned int comments_iterator = 0; comments_iterator < comments_vector.size(); comments_iterator++) {
    if(comments_vector[comments_iterator].BeginBool()) {
      for (unsigned int i = 0; i < comments_vector[comments_iterator].GetContent().size(); i++) {
        output << comments_vector[comments_iterator].GetContent()[i] << std::endl;
      }
      //std::cout << "comentario content\n" << first_comment.GetContent()
    } else {
      output << "/* UNDEFINED DESCRIPTION */\n"; 
    }
  }
  output << "\nMAIN PROGRAMM:\n";
  if (main_program_obj.GetFlag()) {
    output << "True\n";
  } else {
    output << "False\n";
  }
  output << "\nCOMMENTS:\n";
  for (unsigned int comments_iterator = 0; comments_iterator < comments_vector.size(); comments_iterator++) {
    if (comments_vector[comments_iterator].BeginBool()) {
      output << "Line[" << comments_vector[comments_iterator].GetLine() << " - ";
    }
    if (comments_vector[comments_iterator].EndBool()) {
      output << comments_vector[comments_iterator].GetLine() << "]\n";
    }
  }
  for (unsigned int comments_iterator = 0; comments_iterator < single_comments_vector.size(); comments_iterator++) {
    output << "Line[" << single_comments_vector[comments_iterator].Line() << "] " 
    << single_comments_vector[comments_iterator].getContent() << "\n";
  }
  output << "\nVARIABLES\n";
  for(unsigned int i = 0; i < variables_vector.size(); i++) {
    output << variables_vector[i] << "\n";
  }
  output << "\nSTATMENTS:\n";
  for (unsigned int statment_iterator = 0; statment_iterator < statments_vector.size(); statment_iterator++) {
    if (statments_vector[statment_iterator].Type() == "for " || statments_vector[statment_iterator].Type() == "while ") {
      output << "Line[" << statments_vector[statment_iterator].Line() << "] LOOP: " << statments_vector[statment_iterator].Type() << "\n";
    }
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

/*
  //std::regex initialize_var_regex("(int|double)\\s(\\w+)\\s?=(\\s?[+|-]?\\d+\\.?\\d*)");
  //std::regex initialize_var_regex("(int|double)[[:space:]]([a-zA-Z]+)[[:space:]]?=([[:space:]][+|-]?[0-9]+.?[0-9]*)");
  //std::regex initialize_var_regex("(int|double)\\s((\\w+[;])|(\\w+\\s[=]\\s[0-9]*(\\.[0-9]*)*[;]))$");
  //std::regex initialize_var_regex("(int|double)\\s(\\w+\\s[=]\\s[0-9]*(\\.[0-9]*)*)$");

    if (std::regex_search(str_filedata, initvar_buffer, initialize_var_regex)) {
      str_vector_init_va.push_back(initvar_buffer.str(0));
    }
    if (std::regex_search(str_filedata, uninitvar_buffer, uninitialize_var_regex)) {
      str_vector_uninit_va.push_back(uninitvar_buffer.str(0));
    }
    std::cout << "initialize_vector" << std::endl;
    for (unsigned int i = 0; i < str_vector_init_va.size(); i++) {
     std::cout << "[" << str_vector_init_va[i] << "] ";
    }
    std::cout << std::endl;

    std::cout << "uninitialize_vector" << std::endl;
    for (unsigned int i = 0; i < str_vector_uninit_va.size(); i++) {
     std::cout << str_vector_uninit_va[i] << "  ";
    }
    std::cout << std::endl;


    ************************************************************
        for (unsigned int i = 0; i < initvar_buffer.size(); i++) {
      initialize_match_vector.push_back(initvar_buffer[i]);
    }
    for (unsigned int i = 0; i < initialize_match_vector.size(); i++) {
      std::cout << "[" << initialize_match_vector[i] << "] ";
    }
  std::cout << std::endl;




  std::cout << "uninitial std::regex_match()" << std::endl;
  std::regex_match(str_filedata, uninitvar_buffer, uninitialize_var_regex);
  for (unsigned int i = 0; i < uninitvar_buffer.size(); i++) {
    uninitialize_match_vector.push_back(uninitvar_buffer[i]);
  }
  for (unsigned int i = 0; i < uninitialize_match_vector.size(); i++) {
    //std::cout << "[" << uninitialize_match_vector[i] << "] ";
  }
  //std::cout << std::endl;

  ********************************************
  for(unsigned int i = 0; i < variables_vector.size(); i++) {
      std::cout << variables_vector[i] << std::endl;
    }

*/