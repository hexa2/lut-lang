//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E28.h"
#include "E29.h"
#include "../State.h"
#include "../TokenType.h"

E28::E28() : State() { }

bool E28::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::EQ:
      automaton->decalage(t, new E29());
      return true;
    default:
      return false;
  }
  return false;
}
