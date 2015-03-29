//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E17.h"
#include "../TokenType.h"
#include "../ASTThirdLevelExpressionNode.h"
E17::E17() : State() { }

bool E17::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::VAR:
    case TokenType::CONST:
    case TokenType::ID:
    case TokenType::VAL:
    case TokenType::PV:
    case TokenType::V:
    case TokenType::AFF:
    case TokenType::EQ:
    case TokenType::MUL:
    case TokenType::DIV:
    case TokenType::ADD:
    case TokenType::SUB:
    case TokenType::PO:
    case TokenType::PF:
    case TokenType::WRITE:
    case TokenType::READ :
    case TokenType::INVALID_SYMBOL:
    case TokenType::ENDOFFILE :
    {
      //  Reduction N°19 - 3 Level pop - "F->po E pf"
      for ( int i = 0 ; i < 3 ; i++ ) {
        automaton->getStackStates()->pop();
      }

      automaton->getStackASTNodes()->pop();
      ASTFirstLevelExpressionNode *first = (ASTFirstLevelExpressionNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      automaton->getStackASTNodes()->pop();

      ASTThirdLevelExpressionNode token = ASTThirdLevelExpressionNode(first);

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
