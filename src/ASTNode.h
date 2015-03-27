// Copyright 2015 H4314
#ifndef SRC_ASTNODE_H_
#define SRC_ASTNODE_H_

#include <iostream>
#include <string>
#include "TokenType.h"

using std::string;
/**
 * @class
 * Defines a base AST Node
 */
class ASTNode {
 private:
  TokenType type;
 public:
  explicit ASTNode(TokenType type);
  /**
   * Analyzes statically the validity of the program
   * @todo define the data-struct to pass
   */
  virtual bool analyze() = 0;

  /**
   * Executes the program
   * @todo define the data-struct to pass
   */
  virtual void exec() = 0;

  TokenType getTokenType();
};
#endif  // SRC_ASTNODE_H_
