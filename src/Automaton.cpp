//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include "Automaton.h"
#include "states/E0.h"

Automaton::Automaton(std::string filepath) {
  lexer = new Lexer(filepath);
  stackStates.push(new E0());
};


void Automaton::shift(ASTTokenNode* t, State* s) {
  stackStates.push(s);
  stackASTTokenNodes.push(t);
}


void Automaton::reduce(int i) {
  for(int j = 0; j < i ; j++) {
    stackStates.pop();
    stackASTTokenNodes.pop();
  }
}


bool Automaton::accepts() {
  bool epsilon = true;
  while (!stackStates.empty()) {
    State *s = stackStates.top();
    stackStates.pop();
    
    ASTTokenNode *t = lexer->top();
    s->transition(this, t);
    if (epsilon) {
    }
  }
  return true;
}
