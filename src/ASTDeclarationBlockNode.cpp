//
//  ASTDeclarationBlockNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 20/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTDeclarationBlockNode.h"
#include "ErrorHandler.h"

#include <tuple>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::pair;
using std::stringstream;

ASTDeclarationBlockNode::ASTDeclarationBlockNode(ASTTokenNode* varIdentifier,
                                                 ASTEnumDeclNode* enumVars,
                                                 ASTDeclarationBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
  this->varIdentifier = varIdentifier;
  this->enumVars = enumVars;
  this->constIdentifier = NULL;
  this->enumConsts = NULL;
  this->constValue = NULL;
  this->prev = prev;
}

ASTDeclarationBlockNode::ASTDeclarationBlockNode(ASTTokenNode* constIdentifier,
                                                 ASTTokenNode* constValue,
                                                 ASTEnumAssignNode* enumConsts,
                                                 ASTDeclarationBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
  this->varIdentifier = NULL;
  this->enumVars = NULL;
  this->constIdentifier = constIdentifier;
  this->enumConsts = enumConsts;
  this->constValue = constValue;
  this->prev = prev;
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

ASTEnumAssignNode* ASTDeclarationBlockNode::getEnumConsts() {
  return this->enumConsts;
}

ASTDeclarationBlockNode* ASTDeclarationBlockNode::getPrev() {
  return this->prev;
}

bool ASTDeclarationBlockNode::analyze(analyze_table* table) {
  if (this->prev != NULL && !this->prev->analyze(table)) {
    return false;
  }

  if (this->varIdentifier != NULL) {  // Var assignments case
    if (table->count(this->varIdentifier->getValue()) > 0) {
      ErrorHandler::getInstance().DoubleDeclaration(this->varIdentifier->getValue());
      return false;
    }

    (*table)[this->varIdentifier->getValue()] = std::make_tuple(false, false, false);

    if (this->enumVars != NULL && !this->enumVars->analyze(table)) {
      return false;
    }
  }

  if (this->constIdentifier != NULL) {  // Const assignments case
    if (table->count(this->constIdentifier->getValue()) > 0) {
      ErrorHandler::getInstance().DoubleDeclarationConst(this->varIdentifier->getValue());
      return false;
    }

    (*table)[this->constIdentifier->getValue()] = std::make_tuple(true, true, false);

    if (this->enumConsts != NULL && !this->enumConsts->analyze(table)) {
      return false;
    }
  }

  return true;
}

int64_t ASTDeclarationBlockNode::exec(exec_table* table) {
  if (this->prev != NULL) {
    this->prev->exec(table);
  }

  if (this->varIdentifier != NULL) {  // Var assignments case
    (*table)[this->varIdentifier->getValue()] = std::make_tuple(0, false);

    if (this->enumVars != NULL) {
      this->enumVars->exec(table);
    }
  }

  if (this->constIdentifier != NULL) {  // Const assignments case
    stringstream ss;
    ss << this->constValue->getValue();
    int64_t value;
    ss >> value;
    (*table)[this->constIdentifier->getValue()] = std::make_tuple(value, true);

    if (this->enumConsts != NULL) {
      this->enumConsts->exec(table);
    }
  }
  return 0;
}

void ASTDeclarationBlockNode::print() {
  if (this->prev != NULL) {
    this->prev->print();
  }

  if (this->varIdentifier != NULL) {  // Var assignments case
    cout << "var ";
    this->varIdentifier->print();
    cout << ";" << endl;
    if (this->enumVars != NULL) {
      this->enumVars->print();
    }
  }

  if (this->constIdentifier != NULL) {  // Const assignments case
    cout << "const ";
    this->constIdentifier->print();
    cout << " = ";
    this->constValue->print();
    cout << ";" << endl;
    if (this->enumConsts != NULL) {
      this->enumConsts->print();
    }
  }
}

void ASTDeclarationBlockNode::transform(exec_table* table) {
  if (this->prev != NULL) {
    this->prev->transform(table);
  }

  if (this->constIdentifier != NULL) {
    stringstream ss;
    ss << this->constValue->getValue();
    int64_t value;
    ss >> value;
    (*table)[this->constIdentifier->getValue()] = std::make_tuple(value, true);

    if (this->enumConsts != NULL) {
      this->enumConsts->transform(table);
    }
  }
}
