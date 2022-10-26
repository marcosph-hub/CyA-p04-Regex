#include "comments.h"

Comment::Comment(bool external_begin, bool external_content, bool external_end, std::vector<std::string> external_body, int external_line) {
  begin = external_begin;
  content = external_content;
  end = external_end;
  body = external_body;
  line = external_line;
}

bool Comment::BeginBool() {
  return begin;
}

bool Comment::ContentBool() {
  return content;
}

bool Comment::EndBool() {
  return end;
}

std::vector<std::string> Comment::GetContent() {
  return body;
}

int Comment::GetLine() {
  return line;
}

void Comment::setBody(std::vector<std::string> new_body) {
  body = new_body;
}