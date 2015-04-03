// Copyright 2015 H4314
#ifndef SRC_ASTTOKENNODE_H_
#define SRC_ASTTOKENNODE_H_

#include <string>
#include "ASTNode.h"
#include "TokenType.h"
using std::string;

class ASTTokenNode : public ASTNode {
 private :
  string value;
 public:
  explicit ASTTokenNode(TokenType type, string value = "");

  virtual bool analyze(analyze_table* table);
  virtual int64_t exec(exec_table* table);
  virtual void print();
  virtual void transform(exec_table* table);

  string getValue();
};
#endif  // SRC_ASTTOKENNODE_H_
