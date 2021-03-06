// Copyright 2015 H4314

#include "ASTEnumDeclNode.h"

#include <iostream>
#include <tuple>
#include <utility>
#include <string>
using std::cout;
using std::endl;
using std::pair;

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
  if (this->prev != NULL && !this->prev->analyze(table)) {
    return false;
  }

  if (table->count(this->identifier->getValue()) > 0) {
#warning "variable deja assignée"
    return false;
  }

  (*table)[this->identifier->getValue()] = std::make_tuple(false, false, false);

  return true;
}

int64_t ASTEnumDeclNode::exec(exec_table* table) {
  if (this->prev != NULL) {
    this->prev->exec(table);
  }

  (*table)[this->identifier->getValue()] = std::make_tuple(0, false);

  return 0;
}

void ASTEnumDeclNode::print() {
  if (this->prev != NULL) {
    this->prev->print();
  }
  cout << "var ";
  this->identifier->print();
  cout << ";" << endl;
}

void ASTEnumDeclNode::transform(exec_table* table) {
}
