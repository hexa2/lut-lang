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
    ASTDeclarationBlockNode* next) {
  this->varIdentifier = varIdentifier;
  this->enumVars = enumVars;
  this->constIdentifier = NULL;
  this->enumConsts = NULL;
  this->constValue = NULL;
  this->next = next;
}

ASTDeclarationBlockNode::ASTDeclarationBlockNode(
    ASTTokenNode* constIdentifier,
    ASTTokenNode* constValue,
    ASTEnumDeclNode* enumConsts,
    ASTDeclarationBlockNode* next) {
  this->varIdentifier = NULL;
  this->enumVars = NULL;
  this->constIdentifier = constIdentifier;
  this->enumConsts = enumConsts;
  this->constValue = constValue;
  this->next = next;
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

ASTEnumDeclNode* ASTDeclarationBlockNode::getEnumConsts() {
  return this->enumConsts;
}

ASTDeclarationBlockNode* ASTDeclarationBlockNode::getNext() {
  return this->next;
}

bool ASTDeclarationBlockNode::analyze() {
  return true;
}

void ASTDeclarationBlockNode::exec() {
}