//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E8.h"
#include "../State.h"
#include "../TokenType.h"

E8::E8() : State() { }

bool E8::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
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
      //  Reduction N°13 - 3 Level pop
      for(int i=0; i<3; i++)
      {
        automaton->getStackASTTokenNodes()->pop();
        automaton->getStackStates()->pop();
      }
      token = ASTTokenNode(TokenType::E);
      if (!automaton->getStackStates()->top()->transition(automaton, &token)) return false;
      if (!automaton->getStackStates()->top()->transition(automaton, t)) return false;
      return true;
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
