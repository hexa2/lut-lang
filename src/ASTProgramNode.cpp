//
//  ASTProgramNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTProgramNode.h"

ASTProgramNode::ASTProgramNode(ASTDeclarationBlockNode* declarations,
                               ASTInstructionBlockNode* instructions,
                               TokenType type) : ASTNode(type) {
  this->declarations = declarations;
  this->instructions = instructions;
}

ASTDeclarationBlockNode* ASTProgramNode::getDeclarations() {
  return this->declarations;
}

ASTInstructionBlockNode* ASTProgramNode::getInstructions() {
  return this->instructions;
}

bool ASTProgramNode::analyze() {
  return this->declarations->analyze() && this->instructions->analyze();
}
void ASTProgramNode::exec() {
  this->declarations->exec();
  this->instructions->exec();
}
