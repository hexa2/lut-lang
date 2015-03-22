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
  lexer->shift();
  stackStates.push(new E0());
};


void Automaton::decalage(ASTTokenNode* t, State* s) {
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
  
  
  while( lexer->top()->getTokenType() != TokenType::ENDOFFILE )
  {
    if( stackStates.empty() ) return false;
    ASTTokenNode *t = lexer->top() ;
    if ( t == NULL ) return false;  //Mauvais symbole
    if( !stackStates.top()->transition(this, t) ) return false;
    lexer->shift();
  }
  
  if(stackStates.empty()) return false;
  return stackStates.top()->stateNumber() == 2 ;
}
