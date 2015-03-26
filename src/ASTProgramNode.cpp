//
//  ASTProgramNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTProgramNode.h"

ASTProgramNode::ASTProgramNode(ASTDeclarationBlockNode* declarations,
                               ASTInstructionBlockNode* instructions) {
  this->declarations = declarations;
  this->instructions = instructions;
}

ASTDeclarationBlockNode* ASTProgramNode::getDeclarations() {
  return this->declarations;
}

ASTInstructionBlockNode* ASTProgramNode::getInstructions() {
  return this->instructions;
}

bool ASTProgramNode::analyze(analyze_table* table) {
  return
    this->declarations->analyze(table) &&
    this->instructions->analyze(table);
}

int64_t ASTProgramNode::exec(exec_table* table) {
  return this->declarations->exec(table) || this->instructions->exec(table);
}

void ASTProgramNode::print() {
}
