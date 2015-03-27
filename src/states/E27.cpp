//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E27.h"
#include "E28.h"
#include "../TokenType.h"

E27::E27() : State() { }

bool E27::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::ID:
      automaton->decalage(t, new E28());
      return true;
    default:
      return false;
  }
  return false;
}
