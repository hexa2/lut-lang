//
//  ASTDeclarationBlockNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 20/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTDeclarationBlockNode.h"

ASTDeclarationBlockNode::ASTDeclarationBlockNode(
    ASTTokenNode* varIdentifier,
    ASTEnumDeclNode* enumVars,
    ASTDeclarationBlockNode* prev) {
  this->varIdentifier = varIdentifier;
  this->enumVars = enumVars;
  this->constIdentifier = NULL;
  this->enumConsts = NULL;
  this->constValue = NULL;
  this->prev = prev;
}

ASTDeclarationBlockNode::ASTDeclarationBlockNode(
    ASTTokenNode* constIdentifier,
    ASTTokenNode* constValue,
    ASTEnumAssignNode* enumConsts,
    ASTDeclarationBlockNode* prev) {
  this->varIdentifier = NULL;
  this->enumVars = NULL;
  this->constIdentifier = constIdentifier;
  this->enumConsts = enumConsts;
  this->constValue = constValue;
  this->prev = prev;
}

ASTTokenNode* ASTDeclarationBlockNode::getVarIdentifier() {
  return this->varIdentifier;
}

ASTEnumDeclNode* ASTDeclarationBlockNode::getEnumVars() {
  return this->enumVars;
}

ASTTokenNode* ASTDeclarationBlockNode::getConstIdentifier() {
  return this->constIdentifier;
}

ASTTokenNode* ASTDeclarationBlockNode::getConstValue() {
  return this->constValue;
}

ASTEnumAssignNode* ASTDeclarationBlockNode::getEnumConsts() {
  return this->enumConsts;
}

ASTDeclarationBlockNode* ASTDeclarationBlockNode::getPrev() {
  return this->prev;
}

bool ASTDeclarationBlockNode::analyze(analyze_table* table) {
  return true;
}

int64_t ASTDeclarationBlockNode::exec(exec_table* table) {
  return 0;
}

void ASTDeclarationBlockNode::print() {
}
