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
  stackStates = new stack<State*>;
};


bool Automaton::Exists(State *s, ASTTokenNode *t) {
  // return transitions.find(s) != transition.end()
  // && transitions[s].find(t) != transition.end();
  return true;
}

bool Automaton::Accepts() {
  stackStates->push( new E0() );
  bool epsilon = true;
  while (!stackStates->empty()) {
    State *s = stackStates->top();
    stackStates->pop();
    
    ASTTokenNode *t = lexer->top();
    if (!this->Exists(s, t)) {
      return false;
    }
    s->transition(this, t);
    if (epsilon) {
    }
  }
  return true;
}
