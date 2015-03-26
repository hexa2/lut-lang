//
//  ASTFirsLevelExpressionNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTSecondLevelExpressionNode.h"

ASTSecondLevelExpressionNode::ASTSecondLevelExpressionNode(
    ASTSecondLevelExpressionNode* leftExpression,
    ASTMultiplicativeOperation* mulOp,
    ASTThirdLevelExpressionNode* rightExpression) {
  this->leftExpression = leftExpression;
  this->mulOp = mulOp;
  this->rightExpression = rightExpression;
}

ASTSecondLevelExpressionNode::ASTSecondLevelExpressionNode(
    ASTThirdLevelExpressionNode* rightExpression) {
  this->leftExpression = NULL;
  this->mulOp = NULL;
  this->rightExpression = rightExpression;
}

ASTSecondLevelExpressionNode*
    ASTSecondLevelExpressionNode::getLeftExpression() {
  return this->leftExpression;
}

ASTMultiplicativeOperation* ASTSecondLevelExpressionNode::getMulOp() {
  return this->mulOp;
}

ASTThirdLevelExpressionNode*
    ASTSecondLevelExpressionNode::getRightExpression() {
  return this->rightExpression;
}

bool ASTSecondLevelExpressionNode::analyze(analyze_table* table) {
  return true;
}

int64_t ASTSecondLevelExpressionNode::exec(exec_table* table) {
  return 0;
}

void ASTSecondLevelExpressionNode::print() {
}
