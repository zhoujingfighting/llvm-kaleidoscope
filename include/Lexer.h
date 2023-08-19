#include <ctype.h>
#include <string>
// Def basic tokens for
enum Token {
  tok_eof = -1,
  // commands
  tok_def = -2,
  tok_extern = -3,

  // primary
  tok_identifier = -4,
  tok_number = -5
};

class Lexer {
  // Declare a string to store the basic string identifier
  std::string IdentifierStr;

  // Declare a double val to store a number val
  double NumVal;

public:
  int gettok();
  double getNumVal() { return NumVal; }
  std::string getIdentifier() { return IdentifierStr; }
};
