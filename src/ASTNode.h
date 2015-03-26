// Copyright 2015 H4314
#ifndef SRC_ASTNODE_H_
#define SRC_ASTNODE_H_

/**
 * @class
 * Defines a base AST Node
 */
class ASTNode {
 public:
  /**
   * Analyzes statically the validity of the program
   * @todo define the data-struct to pass
   */
  virtual bool analyze() = 0;

  /**
   * Executes the program
   * @todo define the data-struct to pass
   */
  virtual void exec() = 0;
};
#endif  // SRC_ASTNODE_H_
