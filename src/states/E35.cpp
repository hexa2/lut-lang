//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E35.h"
#include "E36.h"
#include "../TokenType.h"

E35::E35() : State() { }

bool E35::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::VAL:
      automaton->decalage(t, new E36());
      return true;
    default:
        return false;
  }
  return false;
}
