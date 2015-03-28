//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E37.h"
#include "E38.h"
#include "../TokenType.h"

E37::E37() : State() { }

bool E37::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::AFF:
      automaton->decalage(t, new E38());
      return true;
    default:
        return false;
  }
  return false;
}
