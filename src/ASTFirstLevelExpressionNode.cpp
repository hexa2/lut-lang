//
//  ASTFirsLevelExpressionNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTFirstLevelExpressionNode.h"

ASTFirstLevelExpressionNode::ASTFirstLevelExpressionNode(
    ASTFirstLevelExpressionNode* leftExpression,
    ASTAdditiveOperation* addOp,
    ASTSecondLevelExpressionNode* rightExpression) {
  this->leftExpression = leftExpression;
  this->addOp = addOp;
  this->rightExpression = rightExpression;
}

ASTFirstLevelExpressionNode::ASTFirstLevelExpressionNode(
    ASTSecondLevelExpressionNode* rightExpression) {
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
  return true;
}

int64_t ASTFirstLevelExpressionNode::exec(exec_table* table) {
  return 0;
}

void ASTFirstLevelExpressionNode::print() {
}
