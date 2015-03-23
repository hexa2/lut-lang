//
//  automaton.cpp
//  lut-lang
//
//  Created by Mehdi Kitane on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E22.h"
#include "E23.h"
#include "../State.h"
#include "../TokenType.h"

E22::E22() : State() { }

bool E22::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  
  switch ( t->getTokenType() ) {
    case TokenType::L1:
      automaton->decalage(t, new E23());
      return true;
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
      //  Reduce
      token = ASTTokenNode(TokenType::L1);
      automaton->stackStates.top()->transition(automaton, &token);
      return true;
    default:
      return false;
  }
  return false;
}
