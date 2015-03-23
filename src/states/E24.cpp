//
//  automaton.cpp
//  lut-lang
//
//  Created by Mehdi Kitane on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "../State.h"
#include "../TokenType.h"
#include "E24.h"

E24::E24() : State() { }

bool E24::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
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
      //  Reduce
      //depiler de 4
      for(int i=0; i<5; i++)
      {
        automaton->getStackASTTokenNodes()->pop();
        automaton->getStackStates()->pop();
      }
      
      token = ASTTokenNode(TokenType::D);
      if (!automaton->getStackStates()->top()->transition(automaton, &token)) return false;
      if (!automaton->getStackStates()->top()->transition(automaton, t)) return false;
      return true;
    default:
      return false;
  }
  return false;
}
