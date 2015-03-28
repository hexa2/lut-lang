//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E31.h"
#include "E32.h"
#include "E33.h"
#include "../TokenType.h"

E31::E31() : State() { }

bool E31::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::V:
      automaton->decalage(t, new E33());
      return true;
    case TokenType::PV:
      automaton->decalage(t, new E32());
      return true;
    default:
        return false;
  }
  return false;
}
