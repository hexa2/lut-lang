//
//  ASTMultiplicativeOperation.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTMultiplicativeOperation.h"

ASTMultiplicativeOperation::ASTMultiplicativeOperation(ASTTokenNode* symbol) {
  this->symbol = symbol;
}

ASTTokenNode* ASTMultiplicativeOperation::getSymbol() {
  return this->symbol;
}

bool ASTMultiplicativeOperation::analyze() {
  return true;
}

void ASTMultiplicativeOperation::exec() {
}
