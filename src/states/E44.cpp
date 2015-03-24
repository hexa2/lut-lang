//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E44.h"
#include "../TokenType.h"

E44::E44() : State() { }

bool E44::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
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
      //  Reduction N°23 - 1 Level Pop - "opA->DIV"
      for ( int i = 0 ; i < 1 ; i++ ) {
        automaton->getStackASTTokenNodes()->pop();
        automaton->getStackStates()->pop();
      }
      token = ASTTokenNode(TokenType::opA);
      if ( !automaton->getStackStates()->top()->transition(
        automaton, &token)) return false;
      if ( !automaton->getStackStates()->top()->transition(
        automaton, t)) return false;
      return true;
    default:
        return false;
    }
    return false;
}
