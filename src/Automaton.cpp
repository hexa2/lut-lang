//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include <string>
#include <stack>
#include "Automaton.h"
#include "states/E0.h"
#include "ASTProgramNode.h"
#include <map>
#include <tuple>
#include <cstdint>
using std::int64_t;
using std::string;
using std::tuple;

Automaton::Automaton(string inputString) {
  lexer = new Lexer(inputString);
  stackStates.push(new E0());
  accepted = false;
}

/**
 * Push token and states on the stack : Decalage case
 */
void Automaton::decalage(ASTNode* t, State* s) {
  stackStates.push(s);
  stackASTTokenNodes.push(t);
}

/**
 * @return The wether or not the program is correct syntaxically
 */
bool Automaton::analyze() {
  setAccepted(false);
  while ( lexer->top()->getTokenType() != TokenType::ENDOFFILE ) {
    lexer->shift();
    if ( stackStates.empty() ) return false;
    ASTTokenNode *t = lexer->top();
    if ( t == NULL ) return false;  //  wrong token case
    if ( !stackStates.top()->transition(this, t) ) return false;
  }
  if ( stackStates.empty() ) return false;

  if (accepted) {
    ASTProgramNode *program = (ASTProgramNode *) stackASTTokenNodes.top();
    map<string, tuple<bool, bool>> *table = new map<string, tuple<bool, bool>>();
    return program->analyze(table);
  }
  return accepted;
}

bool Automaton::print() {
  if (accepted) {
    ASTProgramNode *program = (ASTProgramNode *) stackASTTokenNodes.top();
    program->print();
    return true;
  }
  return false;
}

int64_t Automaton::execute() {
  if (accepted) {
    map<string, tuple<int64_t, bool>> *table = new map<string, tuple<int64_t, bool>>();
    ASTProgramNode *program = (ASTProgramNode *) stackASTTokenNodes.top();
    return program->exec(table);
  }
  return 1;
}

stack<State*> *Automaton::getStackStates() {
  return &this->stackStates;
}

stack<ASTNode*> *Automaton::getStackASTNodes() {
  return &this->stackASTTokenNodes;
}

/**
 * @Accepted is set to true when the end transition is runned.
 */
void Automaton::setAccepted(bool acc) {
  this->accepted = acc;
}
