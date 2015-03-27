//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E40.h"
#include "../TokenType.h"
#include "../ASTInstructionBlockNode.h"
E40::E40() : State() { }

bool E40::transition(Automaton *automaton, ASTNode *t) {
  ASTInstructionBlockNode token = ASTInstructionBlockNode();
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
      //  Reduction N°11 - 5 Level Pop - "I->I id af E pv"
      for ( int i = 0 ; i < 5 ; i++ ) {
        automaton->getStackASTNodes()->pop();
        automaton->getStackStates()->pop();
      }

      if ( !automaton->getStackStates()->top()->transition(automaton, &token))
        return false;
      if ( !automaton->getStackStates()->top()->transition(automaton, t))
        return false;
      return true;
    default:
        return false;
    }
    return false;
}
