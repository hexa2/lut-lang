// Copyright 2015 H4314
#ifndef SRC_ASTNODE_H_
#define SRC_ASTNODE_H_

#include <string>
#include <tuple>
#include <map>
#include <cstdint>
using std::int64_t;

using std::string;
using std::tuple;
using std::map;

// varname => (has_value, is_const)
typedef map<string, tuple<bool, bool>> analyze_table;

// varname => (value, is_const)
typedef map<string, tuple<int64_t, bool>> exec_table;

/**
 * @class
 * Defines a base AST Node
 */
class ASTNode {
 public:
  /**
   * Analyzes statically the validity of the program
   */
  virtual bool analyze(analyze_table* table) = 0;

  /**
   * Executes the program
   */
  virtual int64_t exec(exec_table* table) = 0;

  /**
   * Outputs the program's code
   */
  virtual void print() = 0;
};
#endif  // SRC_ASTNODE_H_
