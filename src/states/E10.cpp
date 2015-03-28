//
//  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E10.h"
#include "../State.h"
#include "../TokenType.h"
#include "../ASTSecondLevelExpressionNode.h"
E10::E10() : State() { }

bool E10::transition(Automaton *automaton, ASTNode *t) {
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
      //  Reduction N°15 - 3 Level pop - "T->T opM F"
      for ( int i = 0 ; i < 3 ; i++ ) {
        automaton->getStackStates()->pop();
      }

      ASTThirdLevelExpressionNode *second = (ASTThirdLevelExpressionNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTMultiplicativeOperation *operation = (ASTMultiplicativeOperation *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTSecondLevelExpressionNode *prev = (ASTSecondLevelExpressionNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTSecondLevelExpressionNode token = ASTSecondLevelExpressionNode(prev, operation, second);

      if (!automaton->getStackStates()->top()->transition(automaton, &token))
        return false;
      if (!automaton->getStackStates()->top()->transition(automaton, t))
        return false;
      return true;
    }
    default:
      return false;
  }
  return false;
}
