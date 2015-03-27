//
//  ASTAdditiveOperation.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTAdditiveOperation.h"

ASTAdditiveOperation::ASTAdditiveOperation(ASTTokenNode* symbol,
                                           TokenType type) : ASTNode(type){
  this->symbol = symbol;
}

ASTTokenNode* ASTAdditiveOperation::getSymbol() {
  return this->symbol;
}

bool ASTAdditiveOperation::analyze() {
  return true;
}

void ASTAdditiveOperation::exec() {
}
