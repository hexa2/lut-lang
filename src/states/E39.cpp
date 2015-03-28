//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E39.h"
#include "E41.h"
#include "E42.h"
#include "E40.h"
#include "E7.h"
#include "../TokenType.h"

E39::E39() : State() { }

bool E39::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::ADD:
      automaton->decalage(t, new E41());
      return true;
    case TokenType::SUB:
      automaton->decalage(t, new E42());
      return true;
    case TokenType::PV:
      automaton->decalage(t, new E40());
      return true;
    case TokenType::opA:
      automaton->decalage(t, new E7());
      return true;
    default:
      return false;
  }
  return false;
}
