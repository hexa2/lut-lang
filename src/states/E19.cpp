//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E19.h"
#include "E20.h"
#include "../State.h"
#include "../TokenType.h"

E19::E19() : State() { }

bool E19::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::PV:
      automaton->decalage(t, new E20());
      return true;
    default:
      return false;
  }
  return false;
}
