#include <iostream>
#include <vector>

class Comment {
  private:
    bool begin;
    bool content;
    bool end;
    std::vector<std::string> body;
    int line;
    public:
    Comment(bool external_begin, bool external_content, bool external_end, std::vector<std::string> external_body, int external_line);
    bool BeginBool();
    bool ContentBool();
    bool EndBool();
    std::vector<std::string> GetContent();
    int GetLine();
    void setBody(std::vector<std::string> new_body);
    //friend std::ostream& operator<<(std::ostream &os, Comment &summoner);
};