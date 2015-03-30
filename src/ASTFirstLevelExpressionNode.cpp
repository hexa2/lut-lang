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
      if (!this->leftExpression->analyze(table)) {
        return false;
      }
    }
    return false;
  }
  return true;
}

int64_t ASTFirstLevelExpressionNode::exec(exec_table* table) {
  int64_t r = this->rightExpression->exec(table);
  if (this->leftExpression != NULL) {
    int64_t l = this->leftExpression->exec(table);
    if (this->addOp->getSymbol()->getValue() == "+") {
      return l + r;
    } else {
      return l - r;
    }
  }
  return r;
}

void ASTFirstLevelExpressionNode::print() {
  if (this->leftExpression != NULL) {
    this->leftExpression->print();
    this->addOp->print();
  }
  this->rightExpression->print();
}

void ASTFirstLevelExpressionNode::transform(exec_table* table) {
  if (this->leftExpression != NULL) {
    this->leftExpression->transform(table);
  }
  this->rightExpression->transform(table);
}
