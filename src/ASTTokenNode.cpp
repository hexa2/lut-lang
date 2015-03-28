// Copyright 2015 H4314
#include "ASTTokenNode.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;


ASTTokenNode::ASTTokenNode(TokenType type, string value) : ASTNode(type) {
  this->value = value;
}

string ASTTokenNode::getValue() {
  return this->value;
}

bool ASTTokenNode::analyze(analyze_table* table) {
  return true;  // noop
}

int64_t ASTTokenNode::exec(exec_table* table) {
  return 0;  // noop
}

void ASTTokenNode::print() {
  cout << this->value;
}
