// Copyright 2015 H4314
#ifndef SRC_ASTNODE_H_
#define SRC_ASTNODE_H_
class ASTNode {
 public:
  virtual bool analyze(/* TODO: define the data-struct to pass */) = 0;
  virtual void exec(/* TODO: define the data-struct to pass */) = 0;
};
#endif  // SRC_ASTNODE_H_
