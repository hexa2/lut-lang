//
//  ASTFirsLevelExpressionNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTFirstLevelExpressionNode.h"

#include <iostream>

using std::cout;
using std::endl;

ASTFirstLevelExpressionNode::ASTFirstLevelExpressionNode(ASTFirstLevelExpressionNode* leftExpression,
                                                         ASTAdditiveOperation* addOp,
                                                         ASTSecondLevelExpressionNode* rightExpression,
                                                         TokenType type) : ASTNode(type) {
  this->leftExpression = leftExpression;
  this->addOp = addOp;
  this->rightExpression = rightExpression;
}

ASTFirstLevelExpressionNode::ASTFirstLevelExpressionNode(ASTSecondLevelExpressionNode* rightExpression,
                                                         TokenType type) : ASTNode(type) {
  this->leftExpression = NULL;
  this->addOp = NULL;
  this->rightExpression = rightExpression;
}

ASTFirstLevelExpressionNode* ASTFirstLevelExpressionNode::getLeftExpression() {
  return this->leftExpression;
}

ASTAdditiveOperation* ASTFirstLevelExpressionNode::getAddOp() {
  return this->addOp;
}

ASTSecondLevelExpressionNode*
    ASTFirstLevelExpressionNode::getRightExpression() {
  return this->rightExpression;
}

bool ASTFirstLevelExpressionNode::analyze(analyze_table* table) {
  if (rightExpression->analyze(table)) {
    if (this->leftExpression != NULL) {
        return this->leftExpression->analyze(table) && this->addOp->analyze(table);
    }
    return false;
  } else {
    return true;
  }
}

int64_t ASTFirstLevelExpressionNode::exec(exec_table* table) {
  return 0;
}

void ASTFirstLevelExpressionNode::print() {
  if (this->leftExpression != NULL) {
    this->leftExpression->print();
    this->addOp->print();
  }
  this->rightExpression->print();
}
