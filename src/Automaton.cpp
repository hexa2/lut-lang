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
using std::string;

Automaton::Automaton(string inputString) {
  lexer = new Lexer(inputString);
  stackStates.push(new E0());
  accepted = false;
}

/**
 * Push token and states on the stack : Decalage case
 */
void Automaton::decalage(ASTTokenNode* t, State* s) {
  stackStates.push(s);
  stackASTTokenNodes.push(t);
}

/**
 * @return The wether or not the program is correct syntaxically
 */
bool Automaton::analyze() {
  while ( lexer->top()->getTokenType() != TokenType::ENDOFFILE ) {
    lexer->shift();
    if ( stackStates.empty() ) return false;
    ASTTokenNode *t = lexer->top();
    if ( t == NULL ) return false;  //  wrong token case
    if ( !stackStates.top()->transition(this, t) ) return false;
  }
  if ( stackStates.empty() ) return false;

  return accepted;
}

stack<State*> *Automaton::getStackStates() {
  return &this->stackStates;
}

stack<ASTTokenNode*> *Automaton::getStackASTTokenNodes() {
  return &this->stackASTTokenNodes;
}


void Automaton::reduce(ASTTokenNode tokenToReduce, int redNb) {
      for ( int i = 0 ; i < 1 ; i++ ) {
        this->getStackASTTokenNodes()->pop();
        this->getStackStates()->pop();
      }
}

/**
 * @Accepted is set to true when the end transition is runned.
 */
void Automaton::setAccepted(bool acc) {
  this->accepted = acc;
}
