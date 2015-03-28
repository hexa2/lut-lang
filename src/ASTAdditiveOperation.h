//
//  ASTAdditiveOperation.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTADDITIVEOPERATION_H_
#define SRC_ASTADDITIVEOPERATION_H_

#include "ASTNode.h"
#include "ASTTokenNode.h"

/**
 * @class
 * Defines an operation symbol (+ or -)
 */
class ASTAdditiveOperation : public ASTNode {
 public:
  /**
   * @constructor
   * @param symbol The addition symbol
   */
  explicit ASTAdditiveOperation(ASTTokenNode* symbol,
                                TokenType type = TokenType::opA);

  /**
   * @return The operation symbol
   */
  ASTTokenNode* getSymbol();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* symbol;
};

#endif  // SRC_ASTADDITIVEOPERATION_H_
