//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E18.h"
#include "E19.h"
#include "../TokenType.h"

E18::E18() : State() { }

bool E18::transition(Automaton *automaton, ASTTokenNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::ID:
      automaton->decalage(t, new E19());
      return true;
    default:
      return false;
  }
  return false;
}
