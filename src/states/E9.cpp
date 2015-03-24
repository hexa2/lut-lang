//
//  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E9.h"
#include "../State.h"
#include "../TokenType.h"

E9::E9() : State() { }

bool E9::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
    case TokenType::D:
    case TokenType::P:
    case TokenType::L1:
    case TokenType::L2:
    case TokenType::I:
    case TokenType::E:
    case TokenType::T:
    case TokenType::F:
      automaton->decalage(t, new E10());
      return true;
    case TokenType::opA:
    case TokenType::opM:

    case TokenType::VAR:
    case TokenType::CONST:
    case TokenType::ID:
      automaton->decalage(t, new E11());
      return true;
    case TokenType::VAL:
      automaton->decalage(t, new E12());
      return true;
    case TokenType::PV:
    case TokenType::V:
    case TokenType::AFF:
    case TokenType::EQ:
    case TokenType::ADD:
    case TokenType::SUB:
    case TokenType::MUL:
    case TokenType::DIV:
    case TokenType::PO:
      automaton->decalage(t, new E13());
      return true;
    case TokenType::PF:
    case TokenType::WRITE:
    case TokenType::READ :
    case TokenType::INVALID_SYMBOL:
    case TokenType::ENDOFFILE :
    default:
      return false;
  }
  return false;
}
