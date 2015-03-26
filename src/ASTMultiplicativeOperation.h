//
//  ASTMultiplicativeOperation.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTMULTIPLICATIVEOPERATION_H_
#define SRC_ASTMULTIPLICATIVEOPERATION_H_

#include <cstdint>
using std::int64_t;

#include "ASTNode.h"
#include "ASTTokenNode.h"

/**
 * @class
 * Defines an operation symbol (* or /)
 */
class ASTMultiplicativeOperation : public ASTNode {
 public:
  /**
   * @constructor
   * @param symbol The multiplication symbol
   */
  explicit ASTMultiplicativeOperation(ASTTokenNode* symbol);

  /**
   * @return The operation symbol
   */
  ASTTokenNode* getSymbol();

  virtual bool analyze(analyze_table* table);
  virtual int64_t exec(exec_table* table);
  virtual void print();

 private:
  ASTTokenNode* symbol;
};

#endif  // SRC_ASTMULTIPLICATIVEOPERATION_H_
