// Copyright 2015 H4314

#include "ASTEnumDeclNode.h"

ASTEnumDeclNode::ASTEnumDeclNode(ASTTokenNode* identifier,
                                 ASTEnumDeclNode* next) {
  this->identifier = identifier;
  this->next = next;
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
