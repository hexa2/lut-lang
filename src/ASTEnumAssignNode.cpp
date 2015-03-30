//
//  ASTEnumAssignNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTEnumAssignNode.h"

#include <tuple>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::pair;
using std::stringstream;

ASTEnumAssignNode::ASTEnumAssignNode(ASTTokenNode* identifier,
                                     ASTTokenNode* value,
                                     ASTEnumAssignNode* prev,
                                     TokenType type) : ASTNode(type) {
  this->identifier = identifier;
  this->value = value;
  this->prev = prev;
}

ASTTokenNode* ASTEnumAssignNode::getIdentifier() {
  return this->identifier;
}

ASTTokenNode* ASTEnumAssignNode::getValue() {
  return this->value;
}

ASTEnumAssignNode* ASTEnumAssignNode::getPrev() {
  return this->prev;
}

bool ASTEnumAssignNode::analyze(analyze_table* table) {
  if (this->prev != NULL && !this->prev->analyze(table)) {
    return false;
  }

  if (table->count(this->identifier->getValue()) > 0) {
#warning "constante deja assignée"
    return false;
  }

  (*table)[this->identifier->getValue()] = std::make_tuple(true, true);

  return true;
}

int64_t ASTEnumAssignNode::exec(exec_table* table) {
  if (this->prev != NULL) {
    this->prev->exec(table);
  }

  stringstream ss;
  ss << this->value->getValue();
  int64_t value;
  ss >> value;
  table->insert(pair<string, tuple<bool, bool>>(this->identifier->getValue(),
                                                std::make_tuple(value, false)));

  return 0;
}

void ASTEnumAssignNode::print() {
  if (this->prev != NULL) {
    this->prev->print();
  }
  cout << ", ";
  this->identifier->print();
  cout << " = ";
  this->value->print();
}
