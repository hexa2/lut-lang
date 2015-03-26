//
//  ASTInstructionBlockNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTInstructionBlockNode.h"

ASTInstructionBlockNode::ASTInstructionBlockNode(
    ASTFirstLevelExpressionNode* expression,
    ASTInstructionBlockNode* next) {
  this->expression = expression;
  this->identifier = NULL;
  this->next = next;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(
    ASTTokenNode* identifier,
    ASTInstructionBlockNode* next) {
  this->expression = NULL;
  this->identifier = identifier;
  this->next = next;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(
    ASTFirstLevelExpressionNode* expression,
    ASTTokenNode* identifier,
    ASTInstructionBlockNode* next) {
  this->expression = expression;
  this->identifier = identifier;
  this->next = next;
}

ASTFirstLevelExpressionNode* ASTInstructionBlockNode::getExpression() {
  return this->expression;
}

ASTTokenNode* ASTInstructionBlockNode::getIdentifier() {
  return this->identifier;
}

ASTInstructionBlockNode* ASTInstructionBlockNode::getNext() {
  return this->next;
}

bool ASTInstructionBlockNode::analyze() {
  return true;
}

void ASTInstructionBlockNode::exec() {
}
