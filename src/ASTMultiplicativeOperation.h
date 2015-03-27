//
//  ASTMultiplicativeOperation.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTMULTIPLICATIVEOPERATION_H_
#define SRC_ASTMULTIPLICATIVEOPERATION_H_

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
  explicit ASTMultiplicativeOperation(ASTTokenNode* symbol, TokenType type = TokenType::opM);

  /**
   * @return The operation symbol
   */
  ASTTokenNode* getSymbol();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* symbol;
};

#endif  // SRC_ASTMULTIPLICATIVEOPERATION_H_
