//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E33.h"
#include "E34.h"
#include "../TokenType.h"

E33::E33() : State() { }

bool E33::transition(Automaton *automaton, ASTTokenNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::ID:
      automaton->decalage(t, new E34());
      return true;
    default:
        return false;
  }
  return false;
}
