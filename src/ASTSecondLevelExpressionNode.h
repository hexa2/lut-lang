//
//  ASTFirsLevelExpressionNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTSECONDLEVELEXPRESSIONNODE_H_
#define SRC_ASTSECONDLEVELEXPRESSIONNODE_H_

#include "ASTNode.h"
#include "ASTMultiplicativeOperation.h"
#include "ASTThirdLevelExpressionNode.h"

// Declare to the compiler the class exists and avoid circular issues
class ASTThirdLevelExpressionNode;

class ASTSecondLevelExpressionNode : public ASTNode {
 public:
  /**
   * @constructor
   * @param leftExpression Left part, recursive 2nd lvl expr
   * @param addOp A multiplicative operator
   * @param rightExpression Right part, goes to the 3rd lvl expr
   */
  ASTSecondLevelExpressionNode(ASTSecondLevelExpressionNode* leftExpression,
                               ASTMultiplicativeOperation* mulOp,
                               ASTThirdLevelExpressionNode* rightExpression,
                               TokenType type = TokenType::T);

  /**
   * @constructor
   * @param rightExpression Right part, goes to the 3rd lvl expr
   */
  explicit ASTSecondLevelExpressionNode(ASTThirdLevelExpressionNode* rightExpression,
                                        TokenType type = TokenType::T);

  /**
   * @return The left expression or Null
   */
  ASTSecondLevelExpressionNode* getLeftExpression();

  /**
   * @return The Multiplicative operation or Null
   */
  ASTMultiplicativeOperation* getMulOp();

  /**
   * @return The right expression
   */
  ASTThirdLevelExpressionNode* getRightExpression();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTSecondLevelExpressionNode* leftExpression;
  ASTMultiplicativeOperation* mulOp;
  ASTThirdLevelExpressionNode* rightExpression;
};


#endif  // SRC_ASTSECONDLEVELEXPRESSIONNODE_H_
