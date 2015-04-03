//
//  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E20.h"
#include "../State.h"
#include "../TokenType.h"
#include "../ASTInstructionBlockNode.h"
E20::E20() : State() { }

bool E20::transition(Automaton *automaton, ASTNode *t) {
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
    case TokenType::PO:
    case TokenType::PF:
    case TokenType::WRITE:
    case TokenType::READ :
    case TokenType::INVALID_SYMBOL:
    case TokenType::ENDOFFILE :
    {
      //  Reduction N°10 - 4 Level pop - "I->I li id pv"
      for ( int i = 0 ; i < 4 ; i++ ) {
        automaton->getStackStates()->pop();
      }

      automaton->getStackASTNodes()->pop();
      ASTTokenNode *identifier = (ASTTokenNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      // ASTTokenNode *read = (ASTTokenNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTInstructionBlockNode *prev = (ASTInstructionBlockNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTInstructionBlockNode *token = new ASTInstructionBlockNode(identifier, prev);
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
