// Copyright 2015 H4314
#ifndef SRC_ASTTOKENNODE_H_
#define SRC_ASTTOKENNODE_H_

#include <string>
#include "ASTNode.h"

using std::string;

class ASTTokenNode : public ASTNode {
 private:
  string matchedRegex;
  string symbol;
 public:
  explicit ASTTokenNode(string matchedRegex = "", string symbol = "");
  bool analyze(/* TODO: define the data-struct to pass */);
  void exec(/* TODO: define the data-struct to pass */);
  string getMatchedRegex();
  string getSymbol();
};
#endif  // SRC_ASTTOKENNODE_H_
