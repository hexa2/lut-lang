//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E0.h"
#include "E1.h"
#include "../State.h"
#include "../TokenType.h"

E0::E0() : State() { }

bool E0::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
    case TokenType::D:
      automaton->decalage(t, new E1());
      return true;
    case TokenType::WRITE:
    case TokenType::READ :
    case TokenType::VAR:
    case TokenType::CONST:
    case TokenType::ID:
    case TokenType::ENDOFFILE :
      //  Reduce
      token = ASTTokenNode(TokenType::D);
      automaton->stackStates.top()->transition(automaton, &token);
      return true;
    default:
      return false;
  }
  return false;
}
