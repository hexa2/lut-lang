//
//  ASTThirdLevelExpressionNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTTHIRDLEVELEXPRESSIONNODE_H_
#define SRC_ASTTHIRDLEVELEXPRESSIONNODE_H_

#include "ASTNode.h"
#include "ASTTokenNode.h"
#include "ASTFirstLevelExpressionNode.h"

// Declare to the compiler the class exists and avoid circular issues
class ASTFirstLevelExpressionNode;

class ASTThirdLevelExpressionNode : public ASTNode {
 public:
  /**
   * @constructor
   * @param identifier A variable identifier or a value
   */
  explicit ASTThirdLevelExpressionNode(ASTTokenNode* identifierOrValue);

  /**
   * @constructor
   * @param expression A first level expression
   */
  explicit ASTThirdLevelExpressionNode(ASTFirstLevelExpressionNode* expression);

  /**
   * @return The variable identifier or a value or Null
   */
  ASTTokenNode* getIdentifierOrValue();

  /**
   * @return The first level expression or Null
   */
  ASTFirstLevelExpressionNode* getExpression();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* identifierOrValue;
  ASTFirstLevelExpressionNode* expression;
};


#endif  // SRC_ASTTHIRDLEVELEXPRESSIONNODE_H_