//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include "Automaton.h"
#include "states/E0.h"
using std::string;

Automaton::Automaton(string inputString) {
  lexer = new Lexer(inputString);
  stackStates.push(new E0());
  accepted = false;
}


void Automaton::decalage(ASTTokenNode* t, State* s) {
  stackStates.push(s);
  stackASTTokenNodes.push(t);
}


bool Automaton::analyze() {
   while ( lexer->top()->getTokenType() != TokenType::ENDOFFILE ) {
    lexer->shift();
    if ( stackStates.empty() ) return false;
    ASTTokenNode *t = lexer->top();
    if ( t == NULL ) return false;  //  wrong token case
    if ( !stackStates.top()->transition(this, t) ) return false;
  };
  if ( stackStates.empty() ) return false;

  return accepted;
}


stack<State*> *Automaton::getStackStates(){
  return &this->stackStates;
}

stack<ASTTokenNode*> *Automaton::getStackASTTokenNodes() {
  return &this->stackASTTokenNodes;
}

void Automaton::setAccepted(bool acc) {
  this->accepted = acc;
}