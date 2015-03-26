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
                                     ASTEnumAssignNode* next) {
  this->identifier = identifier;
  this->value = value;
  this->next = next;
}

ASTTokenNode* ASTEnumAssignNode::getIdentifier() {
  return this->value;
}

ASTTokenNode* ASTEnumAssignNode::getValue() {
  return this->identifier;
}

ASTEnumAssignNode* ASTEnumAssignNode::getNext() {
  return this->next;
}

bool ASTEnumAssignNode::analyze() {
  return true;
}

void ASTEnumAssignNode::exec() {
}
