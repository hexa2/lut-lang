//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "../State.h"
#include "../TokenType.h"
#include "../ASTProgramNode.h"
#include "E2.h"
#include "E37.h"
#include "E18.h"
#include "E4.h"

E2::E2() : State() { }

bool E2::transition(Automaton *automaton, ASTNode *t ) {
  switch ( t->getTokenType() ) {
    case TokenType::ENDOFFILE:
    {
      automaton->setAccepted(true);
      //  Reduction N°1 - 2 Level Pop - "P->DI"
      for ( int i = 0 ; i < 2 ; i++ ) {
        automaton->getStackStates()->pop();
      }

      ASTInstructionBlockNode *instructions = (ASTInstructionBlockNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTDeclarationBlockNode *declarations = (ASTDeclarationBlockNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTProgramNode *token = new ASTProgramNode(declarations, instructions);
      automaton->getStackASTNodes()->push(token);

      return true;
    }
    case TokenType::ID:
      automaton->decalage(t, new E37());
      return true;
    case TokenType::VAL:
    case TokenType::V:
    case TokenType::PV:
    case TokenType::AFF:
    case TokenType::EQ:
    case TokenType::PO:
    case TokenType::PF:
    {
      //  Reduction N°1 - 2 Level Pop - "P->DI"
      for ( int i = 0 ; i < 2 ; i++ ) {
        automaton->getStackStates()->pop();
      }

      ASTInstructionBlockNode *instructions = (ASTInstructionBlockNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();
      ASTDeclarationBlockNode *declarations = (ASTDeclarationBlockNode *) automaton->getStackASTNodes()->top();
      automaton->getStackASTNodes()->pop();

      ASTProgramNode *token = new ASTProgramNode(declarations, instructions);
      if (!automaton->getStackStates()->top()->transition(automaton, token))
        return false;
      if (!automaton->getStackStates()->top()->transition(automaton, t))
        return false;
      return true;
    }
    case TokenType::WRITE:
      automaton->decalage(t, new E4());
      return true;
    case TokenType::READ:
      automaton->decalage(t, new E18());
      return true;
    default:
      return false;
  }
  return false;
}
