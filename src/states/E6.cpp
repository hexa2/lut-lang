//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E6.h"
#include "../State.h"
#include "../TokenType.h"
#include "../ASTInstructionBlockNode.h"
E6::E6() : State() { }

bool E6::transition(Automaton *automaton, ASTNode *t) {
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
      //  Reduction N°9 - 4 Level pop - "I->IeEpv"
      for ( int i = 0 ; i < 4 ; i++ ) {
        automaton->getStackStates()->pop();
      }
      automaton->getStackASTNodes()->pop();
      ASTFirstLevelExpressionNode *expression = (ASTFirstLevelExpressionNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      // ASTTokenNode *write = (ASTTokenNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTInstructionBlockNode *prev = (ASTInstructionBlockNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTInstructionBlockNode token = ASTInstructionBlockNode(expression, prev);

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
