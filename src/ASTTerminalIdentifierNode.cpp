// Copyright 2015 H4314
#include "ASTTerminalIdentifierNode.h"

#include <string>

ASTTerminalIdentifierNode::ASTTerminalIdentifierNode(
    string matchedRegex, string symbol) {
  this->matchedRegex = matchedRegex;
  this->symbol = symbol;
}

bool ASTTerminalIdentifierNode::analyze() {
  return true;  // noop
}

void ASTTerminalIdentifierNode::exec() {
  // noop
}

string ASTTerminalIdentifierNode::getMatchedRegex() {
  return this->matchedRegex;
}

string ASTTerminalIdentifierNode::getSymbol() {
  return this->symbol;
}
