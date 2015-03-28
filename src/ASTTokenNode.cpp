// Copyright 2015 H4314
#include "ASTTokenNode.h"

#include <string>


ASTTokenNode::ASTTokenNode(TokenType type, string value) : ASTNode(type) {
  this->value = value;
}

bool ASTTokenNode::analyze() {
  return true;  // noop
}

void ASTTokenNode::exec() {
  // noop
}

string ASTTokenNode::getValue() {
  return this->value;
}
