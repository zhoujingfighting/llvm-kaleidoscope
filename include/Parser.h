#include "AST.h"
#include "Lexer.h"
#include <map>
#include <memory>
#include <utility>
class Parser {
public:
  Lexer Lex;
  int CurTok;
  int getNextToken() { return CurTok = Lex.gettok(); }

public:
  Parser(/* args */){};
  ~Parser(){};

  int GetTokPrecedence();
  std::unique_ptr<ExprAST> ParseExpression();
  std::unique_ptr<ExprAST> ParseNumberExpr();
  std::unique_ptr<ExprAST> ParseParenExpr();
  std::unique_ptr<ExprAST> ParseIdentifierExpr();
  std::unique_ptr<ExprAST> ParsePrimary();
  std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrec,
                                         std::unique_ptr<ExprAST> LHS);
  std::unique_ptr<PrototypeAST> ParsePrototype();
  std::unique_ptr<FunctionAST> ParseDefinition();
  std::unique_ptr<FunctionAST> ParseTopLevelExpr();
  std::unique_ptr<PrototypeAST> ParseExtern();
  void HandleDefinition();
  void HandleExtern();
  void HandleTopLevelExpression();
  // Entry point for parsing
  void MainLoop();
};
