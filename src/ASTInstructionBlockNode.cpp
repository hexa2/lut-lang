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
    ASTInstructionBlockNode* prev) {
  this->expression = expression;
  this->identifier = NULL;
  this->prev = prev;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(
    ASTTokenNode* identifier,
    ASTInstructionBlockNode* prev) {
  this->expression = NULL;
  this->identifier = identifier;
  this->prev = prev;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(
    ASTFirstLevelExpressionNode* expression,
    ASTTokenNode* identifier,
    ASTInstructionBlockNode* prev) {
  this->expression = expression;
  this->identifier = identifier;
  this->prev = prev;
}

ASTFirstLevelExpressionNode* ASTInstructionBlockNode::getExpression() {
  return this->expression;
}

ASTTokenNode* ASTInstructionBlockNode::getIdentifier() {
  return this->identifier;
}

ASTInstructionBlockNode* ASTInstructionBlockNode::getPrev() {
  return this->prev;
}

bool ASTInstructionBlockNode::analyze() {
  return true;
}

void ASTInstructionBlockNode::exec() {
}
