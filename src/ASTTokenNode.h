// Copyright 2015 H4314
#ifndef SRC_ASTTOKENNODE_H_
#define SRC_ASTTOKENNODE_H_

#include <string>
#include "ASTNode.h"
#include "TokenType.h"
using std::string;

class ASTTokenNode : public ASTNode {
private:
  TokenType type;
  string value;
public:
  explicit ASTTokenNode(TokenType type, string value = "");
  
  bool analyze(/* TODO: define the data-struct to pass */);
  void exec(/* TODO: define the data-struct to pass */);
  TokenType getTokenType();
  string getValue();
};
#endif  // SRC_ASTTOKENNODE_H_
