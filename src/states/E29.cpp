//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E29.h"
#include "E30.h"
#include "../TokenType.h"

E29::E29() : State() { }

bool E29::transition(Automaton *automaton, ASTTokenNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::VAL:
      automaton->decalage(t, new E30());
      return true;
    default:
      return false;
  }
  return false;
}
