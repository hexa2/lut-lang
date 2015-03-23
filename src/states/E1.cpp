//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "../State.h"
#include "../TokenType.h"
#include "E1.h"
#include "E21.h"
#include "E2.h"
//#include "E27.h"

E1::E1() : State() { }

bool E1::transition(Automaton *automaton, ASTTokenNode *t ) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
    case TokenType::I:
      automaton->decalage(t, new E2());
      return true;
    case TokenType::VAR:
      automaton->decalage(t, new E21());
      return true;
    case TokenType::CONST:
      //automaton->decalage(t, new E27());
      return true;
    case TokenType::ID:
    case TokenType::VAL:
    case TokenType::V:
    case TokenType::PV:
    case TokenType::AFF:
    case TokenType::EQ:
    case TokenType::ENDOFFILE:
    case TokenType::WRITE:
    case TokenType::READ:
      //Reduce
      token = ASTTokenNode(TokenType::I);
      if (!automaton->getStackStates()->top()->transition(automaton, &token)) return false;
      if (!automaton->getStackStates()->top()->transition(automaton, t)) return false;
      return true;
    default:
      return false;
  }
  return false;
}
