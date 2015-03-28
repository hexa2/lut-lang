//
//  automaton.cpp
//  lut-lang
//
//  Created by Mehdi Kitane on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "../State.h"
#include "../TokenType.h"
#include "E21.h"
#include "E22.h"
E21::E21() : State() { }

bool E21::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::ID:
      automaton->decalage(t, new E22());
      return true;
    default:
      return false;
  }
  return false;
}
