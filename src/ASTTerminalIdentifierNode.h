// Copyright 2015 H4314
#ifndef SRC_ASTTERMINALIDENTIFIERNODE_H_
#define SRC_ASTTERMINALIDENTIFIERNODE_H_

#include <string>
#include "ASTNode.h"

using std::string;

class ASTTerminalIdentifierNode : public ASTNode {
 private:
  string matchedRegex;
  string symbol;
 public:
  ASTTerminalIdentifierNode(string matchedRegex, string symbol);
  bool analyze(/* TODO: define the data-struct to pass */);
  void exec(/* TODO: define the data-struct to pass */);
  string getMatchedRegex();
  string getSymbol();
};
#endif  // SRC_ASTTERMINALIDENTIFIERNODE_H_
