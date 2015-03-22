// Copyright 2015 H4314
#include "ASTTokenNode.h"

#include <string>


ASTTokenNode::ASTTokenNode(TokenType type, string value ) {
  this->type = type;
  this->value = value;
}

bool ASTTokenNode::analyze() {
  return true;  // noop
}

void ASTTokenNode::exec() {
  // noop
}

TokenType ASTTokenNode::getTokenType() {
  return this->type;
}

string ASTTokenNode::getValue() {
  return this->value;
}
