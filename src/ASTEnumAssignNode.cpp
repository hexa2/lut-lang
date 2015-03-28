//
//  ASTEnumAssignNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTEnumAssignNode.h"

#include <iostream>

using std::cout;
using std::endl;

ASTEnumAssignNode::ASTEnumAssignNode(ASTTokenNode* identifier,
                                     ASTTokenNode* value,
                                     ASTEnumAssignNode* prev,
                                     TokenType type) : ASTNode(type) {
  this->identifier = identifier;
  this->value = value;
  this->prev = prev;
}

ASTTokenNode* ASTEnumAssignNode::getIdentifier() {
  return this->identifier;
}

ASTTokenNode* ASTEnumAssignNode::getValue() {
  return this->value;
}

ASTEnumAssignNode* ASTEnumAssignNode::getPrev() {
  return this->prev;
}

bool ASTEnumAssignNode::analyze(analyze_table* table) {
  return true;
}

int64_t ASTEnumAssignNode::exec(exec_table* table) {
  return 0;
}

void ASTEnumAssignNode::print() {
  if (this->prev != NULL) {
    this->prev->print();
  }
  cout << ", ";
  this->identifier->print();
  cout << " = ";
  this->value->print();
}
