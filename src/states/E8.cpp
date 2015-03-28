//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E8.h"
#include "E9.h"
#include "E43.h"
#include "E44.h"
#include "../ASTFirstLevelExpressionNode.h"

E8::E8() : State() { }

bool E8::transition(Automaton *automaton, ASTNode *t) {
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
    case TokenType::PF:
    case TokenType::WRITE:
    case TokenType::READ :
    case TokenType::ENDOFFILE :
    {
      //  Reduction N°13 - 3 Level pop - "E->E opA T"
      for ( int i = 0 ; i < 3 ; i++ ) {
        automaton->getStackStates()->pop();
      }
      ASTSecondLevelExpressionNode *second = (ASTSecondLevelExpressionNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTAdditiveOperation* operation = (ASTAdditiveOperation *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTFirstLevelExpressionNode *prev = (ASTFirstLevelExpressionNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTFirstLevelExpressionNode *token = new ASTFirstLevelExpressionNode(prev, operation, second);

      if (!automaton->getStackStates()->top()->transition(automaton, token))
        return false;
      if (!automaton->getStackStates()->top()->transition(automaton, t))
        return false;
      return true;
    }
    case TokenType::opM:
      automaton->decalage(t, new E9());
      return true;
    case TokenType::MUL:
      automaton->decalage(t, new E43());
      return true;
    case TokenType::DIV:
      automaton->decalage(t, new E44());
      return true;
        case TokenType::PO:
   default:
      return false;
  }
  return false;
}
