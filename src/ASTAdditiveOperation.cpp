//
//  ASTAdditiveOperation.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTAdditiveOperation.h"

#include <iostream>

using std::cout;
using std::endl;

ASTAdditiveOperation::ASTAdditiveOperation(ASTTokenNode* symbol,
                                           TokenType type) : ASTNode(type) {
  this->symbol = symbol;
}

ASTTokenNode* ASTAdditiveOperation::getSymbol() {
  return this->symbol;
}

bool ASTAdditiveOperation::analyze(analyze_table* table) {
  return symbol->getValue() != "";
}

int64_t ASTAdditiveOperation::exec(exec_table* table) {
  return 0;
}

void ASTAdditiveOperation::print() {
  this->symbol->print();
}

void ASTAdditiveOperation::transform(exec_table* table) {
}

