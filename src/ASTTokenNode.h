// Copyright 2015 H4314
#ifndef SRC_ASTTOKENNODE_H_
#define SRC_ASTTOKENNODE_H_

#include <string>

using std::string;

/**
 * @class
 * A token returned by the Lexer
 */
class ASTTokenNode {
 public:
  /**
   * @constructor
   * @param matchedRegex The regex that matched the token
   * @param symbol The symbol returned by the lexer
   */
  explicit ASTTokenNode(string matchedRegex  = "", string symbol = "");

  /**
   * @return The Token Type that matched the token
   */
  TokenType getTokenType();

  /**
   * @return symbol The symbol returned by the lexer
   */
  string getValue();

 private:
  TokenType type;
  string value;
};

#endif  // SRC_ASTTOKENNODE_H_
