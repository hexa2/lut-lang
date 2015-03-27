//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E34.h"
#include "E35.h"
#include "../TokenType.h"

E34::E34() : State() { }

bool E34::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::EQ:
      automaton->decalage(t, new E35());
      return true;
    default:
        return false;
  }
  return false;
}
