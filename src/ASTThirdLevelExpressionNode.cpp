//
//  ASTThirdLevelExpressionNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTThirdLevelExpressionNode.h"

#include <iostream>

using std::cout;
using std::endl;

ASTThirdLevelExpressionNode::ASTThirdLevelExpressionNode(ASTTokenNode* identifierOrValue,
                                                         TokenType type) : ASTNode(type) {
  this->identifierOrValue = identifierOrValue;
  this->expression = NULL;
}

ASTThirdLevelExpressionNode::ASTThirdLevelExpressionNode(ASTFirstLevelExpressionNode* expression,
                                                         TokenType type) : ASTNode(type) {
  this->identifierOrValue = NULL;
  this->expression = expression;
}

ASTTokenNode* ASTThirdLevelExpressionNode::getIdentifierOrValue() {
  return this->identifierOrValue;
}

ASTFirstLevelExpressionNode* ASTThirdLevelExpressionNode::getExpression() {
  return this->expression;
}

bool ASTThirdLevelExpressionNode::analyze(analyze_table* table) {
  return true;
}

int64_t ASTThirdLevelExpressionNode::exec(exec_table* table) {
  return 0;
}

void ASTThirdLevelExpressionNode::print() {
  if (this->identifierOrValue != NULL) {
    this->identifierOrValue->print();
  } else {
    cout << "(";
    this->expression->print();
    cout << ")";
  }
}
