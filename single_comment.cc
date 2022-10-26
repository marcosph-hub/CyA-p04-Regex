#include "single_comment.h"

SingleComment::SingleComment(int external_line) {
  line = external_line;
  body = "";
}

int SingleComment::Line() {
  return line;
}

std::string SingleComment::getContent() {
  return body;
}

void SingleComment::setContent(std::string new_content) {
  body = new_content;
}