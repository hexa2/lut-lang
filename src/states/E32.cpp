//
//  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E32.h"
#include "../State.h"
#include "../TokenType.h"
#include "../ASTDeclarationBlockNode.h"
E32::E32() : State() { }

bool E32::transition(Automaton *automaton, ASTNode *t) {
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
      //  Reduction N°3 - 7 Level Pop - "D->D const id eq val L2 pv"
      for ( int i = 0 ; i < 7 ; i++ ) {
        automaton->getStackStates()->pop();
      }

      automaton->getStackASTNodes()->pop();
      ASTEnumAssignNode *enumConsts = (ASTEnumAssignNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTTokenNode *constValue = (ASTTokenNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      automaton->getStackASTNodes()->pop();
      ASTTokenNode *constIdentifier = (ASTTokenNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      automaton->getStackASTNodes()->pop();
      ASTDeclarationBlockNode *prev = (ASTDeclarationBlockNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTDeclarationBlockNode *token = new ASTDeclarationBlockNode(constIdentifier, constValue, enumConsts, prev);

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
