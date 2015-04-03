//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E36.h"
#include "../State.h"
#include "../TokenType.h"
#include "../ASTEnumAssignNode.h"
E36::E36() : State() { }

bool E36::transition(Automaton *automaton, ASTNode *t) {
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
    {
      //  Reduction N°7 - 5 Level Pop - "L2->L2 v id eq val"
      for ( int i = 0 ; i < 5 ; i++ ) {
        automaton->getStackStates()->pop();
      }

      ASTTokenNode *value = (ASTTokenNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      automaton->getStackASTNodes()->pop();
      ASTTokenNode *identifier = (ASTTokenNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      automaton->getStackASTNodes()->pop();
      ASTEnumAssignNode *prev = (ASTEnumAssignNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTEnumAssignNode *token = new ASTEnumAssignNode(identifier, value, prev);

      if ( !automaton->getStackStates()->top()->transition(automaton, token))
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
