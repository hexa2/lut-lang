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

Automaton::Automaton(string filepath) {
  lexer = new Lexer(filepath);
  lexer->shift();
  stackStates.push(new E0());
}


void Automaton::decalage(ASTTokenNode* t, State* s) {
  stackStates.push(s);
  stackASTTokenNodes.push(t);
}


bool Automaton::accepts() {
  while ( lexer->has_next() ) {
    if ( stackStates.empty() ) return false;
    ASTTokenNode *t = lexer->top();
    if ( t == NULL ) return false;  //  wrong token case
    if ( !stackStates.top()->transition(this, t) ) return false;
    lexer->shift();
  }
  if ( stackStates.empty() ) return false;
  return stackStates.top()->stateNumber() == 2;
}
