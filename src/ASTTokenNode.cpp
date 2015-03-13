// Copyright 2015 H4314
#include "ASTTokenNode.h"

#include <string>

ASTTokenNode::ASTTokenNode(string matchedRegex, string symbol) {
  this->matchedRegex = matchedRegex;
  this->symbol = symbol;
}

bool ASTTokenNode::analyze() {
  return true;  // noop
}

void ASTTokenNode::exec() {
  // noop
}

string ASTTokenNode::getMatchedRegex() {
  return this->matchedRegex;
}

string ASTTokenNode::getSymbol() {
  return this->symbol;
}
