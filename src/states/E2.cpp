//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E2.h"
#include "E37.h"
#include "E18.h"
#include "E4.h"
#include "../State.h"
#include <iostream>
using std::cout;

E2::E2() : State() { }

bool E2::transition(Automaton *automaton, ASTTokenNode *t ) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
    case TokenType::ENDOFFILE:
      cout << "Valid Automaton";
      return true;
    case TokenType::ID:
      automaton->decalage(t, new E37());
      return true;
    case TokenType::VAL:
      token = ASTTokenNode(TokenType::P);
      automaton->stackStates.top()->transition(automaton, &token);
      return true;
    case TokenType::WRITE:
      automaton->decalage(t, new E18());
      return true;
    case TokenType::READ:
      automaton->decalage(t, new E4());
      return true;
    default:
      return false;
      break;
  }
  return false;
}
