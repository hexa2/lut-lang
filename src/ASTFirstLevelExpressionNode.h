//
//  ASTFirstLevelExpressionNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTFIRSTLEVELEXPRESSIONNODE_H_
#define SRC_ASTFIRSTLEVELEXPRESSIONNODE_H_

#include "ASTNode.h"
#include "ASTAdditiveOperation.h"
#include "ASTSecondLevelExpressionNode.h"

// Declare to the compiler the class exists and avoid circular issues
class ASTSecondLevelExpressionNode;

class ASTFirstLevelExpressionNode : public ASTNode {
 public:
  /**
   * @constructor
   * @param leftExpression Left part, recursive 1st lvl expr
   * @param addOp An additive operator
   * @param rightExpression Right part, goes to the 2nd lvl expr
   */
  ASTFirstLevelExpressionNode(ASTFirstLevelExpressionNode* leftExpression,
                              ASTAdditiveOperation* addOp,
                              ASTSecondLevelExpressionNode* rightExpression);

  /**
   * @constructor
   * @param rightExpression Right part, goes to the 2nd lvl expr
   */
  explicit ASTFirstLevelExpressionNode(
      ASTSecondLevelExpressionNode* rightExpression);

  /**
   * @return The left expression or Null
   */
  ASTFirstLevelExpressionNode* getLeftExpression();

  /**
   * @return The additive operation or Null
   */
  ASTAdditiveOperation* getAddOp();

  /**
   * @return The right expression
   */
  ASTSecondLevelExpressionNode* getRightExpression();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTFirstLevelExpressionNode* leftExpression;
  ASTAdditiveOperation* addOp;
  ASTSecondLevelExpressionNode* rightExpression;
};


#endif  // SRC_ASTFIRSTLEVELEXPRESSIONNODE_H_
