//
//  ASTThirdLevelExpressionNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTThirdLevelExpressionNode.h"

#include <tuple>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::pair;
using std::stringstream;

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
  if (expression != NULL && !expression->analyze(table)) {
    return false;
  } else if (this->identifierOrValue->getTokenType() == TokenType::ID &&
             table->count(this->identifierOrValue->getValue()) < 1) {
#warning "variable identifier non assignee"
    return false;
  }
  return true;
}

int64_t ASTThirdLevelExpressionNode::exec(exec_table* table) {
  if (this->identifierOrValue != NULL) {
    if (this->identifierOrValue->getTokenType() == TokenType::ID) {
      return std::get<0>((*table)[this->identifierOrValue->getValue()]);
    } else {
      stringstream ss;
      ss << this->identifierOrValue->getValue();
      int64_t value;
      ss >> value;
      return value;
    }
  } else {
    return expression->exec(table);
  }
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

void ASTThirdLevelExpressionNode::transform(exec_table* table) {
  if (this->identifierOrValue->getTokenType() == TokenType::ID &&
      table->count(this->identifierOrValue->getValue()) > 0) {
    std::tuple<int64_t, bool> constTerm = (*table)[this->identifierOrValue->getValue()];
    if (std::get<1>(constTerm)) {
      stringstream ss;
      ss << std::get<0>(constTerm);
      string val = ss.str();
      this->identifierOrValue = new ASTTokenNode(TokenType::VAL, val);
    }
  }
}
