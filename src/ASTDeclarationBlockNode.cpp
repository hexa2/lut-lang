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
    ASTEnumDeclNode* enumVars = NULL,
    ASTDeclarationBlockNode* next = NULL) {
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
    ASTEnumDeclNode* enumConsts = NULL,
    ASTDeclarationBlockNode* next = NULL) {
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

ASTTokenNode* ASTDeclarationBlockNode::getEnumVars() {
  return this->enumVars;
}

ASTTokenNode* ASTDeclarationBlockNode::getConstIdentifier() {
  return this->constIdentifier;
}

ASTTokenNode* ASTDeclarationBlockNode::getConstValue() {
  return this->constValue;
}

ASTTokenNode* ASTDeclarationBlockNode::getEnumConsts() {
  return this->enumConsts;
}

ASTTokenNode* ASTDeclarationBlockNode::getNext() {
  return this->next;
}
