// Copyright 2015 H4314

#include "ASTEnumDeclNode.h"

ASTEnumDeclNode::ASTEnumDeclNode(ASTTokenNode* varName,
                                 ASTTokenNode* identifier,
                                 ASTEnumDeclNode* next) {
  this->varName = varName;
  this->identifier = identifier;
  this->next = next;
}

ASTTokenNode* ASTEnumDeclNode::getVarName() {
  return this->varName;
}

ASTTokenNode* ASTEnumDeclNode::getIdentifier() {
  return this->identifier;
}

ASTEnumDeclNode* ASTEnumDeclNode::getNext() {
  return this->next;
}

bool ASTEnumDeclNode::analyze() {
  return true;
}

void ASTEnumDeclNode::exec() {
}
