//
//  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E24.h"
#include "../State.h"
#include "../TokenType.h"
#include "../ASTDeclarationBlockNode.h"

E24::E24() : State() { }

bool E24::transition(Automaton *automaton, ASTNode *t) {
  ASTDeclarationBlockNode token = ASTDeclarationBlockNode(NULL);
  
  switch ( t->getTokenType() ) {
    case TokenType::ADD :
    case TokenType::MUL :
    case TokenType::SUB :
    case TokenType::DIV :
    case TokenType::VAR :
    case TokenType::CONST :
    case TokenType::ID :
    case TokenType::VAL :
    case TokenType::V :
    case TokenType::PV :
    case TokenType::AFF :
    case TokenType::EQ :
    case TokenType::ENDOFFILE :
    case TokenType::PO :
    case TokenType::PF :
    case TokenType::READ :
    case TokenType::WRITE :
      //  Reduction N°2 - 4 Level pop - "D->D var id L1 pv"
      for ( int i = 0 ; i < 5 ; i++ ) {
        automaton->getStackASTNodes()->pop();
        automaton->getStackStates()->pop();
      }
      if (!automaton->getStackStates()->top()->transition(automaton, &token))
        return false;
      if (!automaton->getStackStates()->top()->transition(automaton, t))
        return false;
      return true;
    default:
      return false;
  }
  return false;
}
