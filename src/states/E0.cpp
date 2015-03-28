//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "../State.h"
#include "../TokenType.h"
#include "../ASTDeclarationBlockNode.h"
#include "E0.h"
#include "E1.h"

E0::E0() : State() { }

bool E0::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::D:
      automaton->decalage(t, new E1());
      return true;
    case TokenType::WRITE:
    case TokenType::READ :
    case TokenType::VAR:
    case TokenType::CONST:
    case TokenType::ID:
    case TokenType::ENDOFFILE :
    {
      //  Reduction N°4 - 0 Level Pop - D->.
      ASTDeclarationBlockNode token = ASTDeclarationBlockNode(NULL);
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
