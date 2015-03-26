//
//  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E25.h"
#include "E26.h"
#include "../State.h"
#include "../TokenType.h"

E25::E25() : State() { }

bool E25::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
    case TokenType::ID:
      automaton->decalage(t, new E26());
      return true;
    default:
      return false;
  }
  return false;
}
