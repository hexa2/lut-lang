//
//  ASTInstructionBlockNode.cpp
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#include "ASTInstructionBlockNode.h"

#include <tuple>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

ASTInstructionBlockNode::ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                                                 ASTInstructionBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
  this->expression = expression;
  this->identifier = NULL;
  this->prev = prev;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(ASTTokenNode* identifier,
                                                 ASTInstructionBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
  this->expression = NULL;
  this->identifier = identifier;
  this->prev = prev;
}

ASTInstructionBlockNode::ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                                                 ASTTokenNode* identifier,
                                                 ASTInstructionBlockNode* prev,
                                                 TokenType type) : ASTNode(type) {
  this->expression = expression;
  this->identifier = identifier;
  this->prev = prev;
}

ASTFirstLevelExpressionNode* ASTInstructionBlockNode::getExpression() {
  return this->expression;
}

ASTTokenNode* ASTInstructionBlockNode::getIdentifier() {
  return this->identifier;
}

ASTInstructionBlockNode* ASTInstructionBlockNode::getPrev() {
  return this->prev;
}

bool ASTInstructionBlockNode::analyze(analyze_table* table) {
  if (this->prev != NULL) {
    if (!this->prev->analyze(table)) {
      return false;
    }
  }

  if (this->expression != NULL) {
    if (!this->expression->analyze(table)) {
      return false;
    }
  }

  if (this->identifier != NULL) {
    if (table->count(this->identifier->getValue()) < 1) {
#warning "variable ou constante non assignee"
      return false;
    }

    bool isConst = std::get<1>((*table)[this->identifier->getValue()]);
    if (isConst) {
      return false;
    }
  }

  return true;
}

int64_t ASTInstructionBlockNode::exec(exec_table* table) {
  if (this->prev != NULL) {
    this->prev->exec(table);
  }

  if (this->expression != NULL && this->identifier != NULL) {  // Assignment
    int64_t value = this->expression->exec(table);

    bool isConst = std::get<1>((*table)[this->identifier->getValue()]);
    if (!isConst) {
      (*table)[this->identifier->getValue()] = std::make_tuple(value, isConst);
    }
  } else if (this->expression != NULL) {  // Write
    cout << this->expression->exec(table) << endl;
  } else if (this->identifier != NULL) {  // Read
    string line;
    getline(cin, line);
    stringstream ss;
    ss << line;
    int64_t value;
    ss >> value;

    bool isConst = std::get<1>((*table)[this->identifier->getValue()]);
    if (!isConst) {
      (*table)[this->identifier->getValue()] = std::make_tuple(value, isConst);
    }
  }

  return 0;
}

void ASTInstructionBlockNode::print() {
  if (this->prev != NULL) {
    this->prev->print();
  }

  if (this->expression != NULL && this->identifier != NULL) {  // Assignment
    this->identifier->print();
    cout << " := ";
    this->expression->print();
  } else if (this->expression != NULL) {  // Write
    cout << "ecrire ";
    this->expression->print();
  } else if (this->identifier != NULL) {  // Read
    cout << "lire ";
    this->identifier->print();
  }

  cout << ";" << endl;
}
