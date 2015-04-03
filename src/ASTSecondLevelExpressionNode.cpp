//
//  ASTFirsLevelExpressionNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTSecondLevelExpressionNode.h"

#include <iostream>

using std::cout;
using std::endl;

ASTSecondLevelExpressionNode::ASTSecondLevelExpressionNode(ASTSecondLevelExpressionNode* leftExpression,
                                                           ASTMultiplicativeOperation* mulOp,
                                                           ASTThirdLevelExpressionNode* rightExpression,
                                                           TokenType type) : ASTNode(type) {
  this->leftExpression = leftExpression;
  this->mulOp = mulOp;
  this->rightExpression = rightExpression;
}

ASTSecondLevelExpressionNode::ASTSecondLevelExpressionNode(ASTThirdLevelExpressionNode* rightExpression,
                                                           TokenType type) : ASTNode(type) {
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
  if (this->leftExpression != NULL && !this->leftExpression->analyze(table)) {
    return false;
  }
  if (this->rightExpression != NULL && !this->rightExpression->analyze(table)) {
    return false;
  }
  return true;
}

int64_t ASTSecondLevelExpressionNode::exec(exec_table* table) {
  int64_t r = this->rightExpression->exec(table);
  if (this->leftExpression != NULL) {
    int64_t l = this->leftExpression->exec(table);
    if (this->mulOp->getSymbol()->getValue() == "*") {
      return l * r;
    } else {
      return l / r;
    }
  }
  return r;
}

void ASTSecondLevelExpressionNode::print() {
  if (this->leftExpression != NULL) {
    this->leftExpression->print();
    this->mulOp->print();
  }
  this->rightExpression->print();
}

void ASTSecondLevelExpressionNode::transform(exec_table* table) {
  if (this->leftExpression != NULL) {
    this->leftExpression->transform(table);
  }
  this->rightExpression->transform(table);
}
