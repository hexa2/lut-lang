// Copyright 2015 H4314

#include "ASTEnumDeclNode.h"

ASTEnumDeclNode::ASTEnumDeclNode(ASTTokenNode* identifier,
                                 ASTEnumDeclNode* prev,
                                 TokenType type) : ASTNode(type) {
  this->identifier = identifier;
  this->prev = prev;
}

ASTTokenNode* ASTEnumDeclNode::getIdentifier() {
  return this->identifier;
}

ASTEnumDeclNode* ASTEnumDeclNode::getPrev() {
  return this->prev;
}

bool ASTEnumDeclNode::analyze(analyze_table* table) {
  return true;
}

int64_t ASTEnumDeclNode::exec(exec_table* table) {
  return 0;
}

void ASTEnumDeclNode::print() {
}
