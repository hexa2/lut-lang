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

bool ASTProgramNode::analyze(analyze_table* table) {
  bool declarationsOutput = true;
  bool instructionsOutput = true;
  if (this->declarations != NULL) {
    declarationsOutput = this->declarations->analyze(table);
  }
  if (this->instructions != NULL) {
    instructionsOutput = this->instructions->analyze(table);
  }
  return declarationsOutput && instructionsOutput;
}

int64_t ASTProgramNode::exec(exec_table* table) {
  int64_t declarationsOutput = 0;
  int64_t instructionsOutput = 0;
  if (this->declarations != NULL) {
    declarationsOutput = this->declarations->exec(table);
  }
  if (this->instructions != NULL) {
    instructionsOutput = this->instructions->exec(table);
  }
  return declarationsOutput || instructionsOutput;
}

void ASTProgramNode::print() {
  if (this->declarations != NULL) {
    this->declarations->print();
  }
  if (this->instructions != NULL) {
    this->instructions->print();
  }
}
