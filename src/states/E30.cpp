//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E30.h"
#include "E31.h"
#include "../TokenType.h"
#include "../ASTEnumAssignNode.h"
E30::E30() : State() { }

bool E30::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::L2:
      automaton->decalage(t, new E31());
      return true;
    case TokenType::VAR:
    case TokenType::CONST:
    case TokenType::ID:
    case TokenType::VAL:
    case TokenType::PV:
    case TokenType::V:
    case TokenType::AFF:
    case TokenType::EQ:
    case TokenType::ADD:
    case TokenType::SUB:
    case TokenType::MUL:
    case TokenType::DIV:
    case TokenType::PO:
    case TokenType::PF:
    case TokenType::WRITE:
    case TokenType::READ :
    case TokenType::INVALID_SYMBOL:
    case TokenType::ENDOFFILE :
    {
      //  Reduction N°8 - 0 Level pop - "L2->."
      ASTEnumAssignNode token = ASTEnumAssignNode(NULL, NULL);

      if ( !automaton->getStackStates()->top()->transition(automaton, &token))
        return false;
      if ( !automaton->getStackStates()->top()->transition(automaton, t))
        return false;
      return true;
    }
    default:
        return false;
  }
  return false;
}
