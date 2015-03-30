//  automaton.cpp
//  lut-lang
//
//  Created by Mehdi Kitane on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E23.h"
#include "E24.h"
#include "E25.h"
#include "../ErrorHandler.h"

E23::E23() : State() { }

bool E23::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
  case TokenType::V:
    automaton->decalage(t, new E25());
    return true;
  case TokenType::PV:
    automaton->decalage(t, new E24());
    return true;
  default:
      ErrorHandler::getInstance().SyntaxErrorSymbole(automaton->getLexer()->getLine(), automaton->getLexer()->getColumn(), ", ou ;");
    return false;
  }
  return false;
}
