//
//  ASTInstructionBlockNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTInstructionBlockNode.h"

#include <iostream>

using std::cout;
using std::endl;

ASTInstructionBlockNode::ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                                                 ASTInstructionBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
  this->expression = expression;
  this->identifier = NULL;
  this->prev = prev;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(ASTTokenNode* identifier,
                                                 ASTInstructionBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
  this->expression = NULL;
  this->identifier = identifier;
  this->prev = prev;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                                                 ASTTokenNode* identifier,
                                                 ASTInstructionBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
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

bool ASTInstructionBlockNode::analyze(analyze_table* table) {
  return true;
}

int64_t ASTInstructionBlockNode::exec(exec_table* table) {
  return 0;
}

void ASTInstructionBlockNode::print() {
  if (this->expression != NULL && this->identifier != NULL) {  // Assignment
    this->identifier->print();
    cout << " := ";
    this->expression->print();
  } else if (this->expression != NULL) {  // Write
    cout << "ecrire ";
    this->expression->print();
  } else if (this->identifier != NULL) {  // Read
    cout << "lire ";
    this->identifier->print();
  }
  cout << ";" << endl;
}
