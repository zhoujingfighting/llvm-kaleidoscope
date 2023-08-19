#include "Parser.h"

extern std::map<char, int> BinopPrecedence;
extern std::unique_ptr<Module> TheModule;
int main() {
    Lexer lexer;
    Parser parser;
  // Install standard binary operators.
  // 1 is lowest precedence.
  BinopPrecedence['<'] = 10;
  BinopPrecedence['+'] = 20;
  BinopPrecedence['-'] = 20;
  BinopPrecedence['*'] = 40; // highest.

  // Prime the first token.
  fprintf(stderr, "ready> ");
  parser.getNextToken();

  // Run the main "interpreter loop" now.
  parser.MainLoop();

  // Print out all of the generated code.
  TheModule->print(errs(), nullptr);

  return 0;
}