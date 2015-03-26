//
//  ASTEnumAssignNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTEnumAssignNode.h"

ASTEnumAssignNode::ASTEnumAssignNode(ASTTokenNode* identifier,
                                     ASTTokenNode* value,
                                     ASTEnumAssignNode* prev) {
  this->identifier = identifier;
  this->value = value;
  this->prev = prev;
}

ASTTokenNode* ASTEnumAssignNode::getIdentifier() {
  return this->value;
}

ASTTokenNode* ASTEnumAssignNode::getValue() {
  return this->identifier;
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
}
