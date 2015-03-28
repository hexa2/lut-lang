//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E7.h"
#include "E8.h"
#include "E14.h"
#include "E11.h"
#include "E12.h"
#include "E13.h"
#include "../State.h"
#include "../TokenType.h"

E7::E7() : State() { }

bool E7::transition(Automaton *automaton, ASTNode *t) {
  switch ( t->getTokenType() ) {
    case TokenType::T:
      automaton->decalage(t, new E8());
      return true;
    case TokenType::F:
      automaton->decalage(t, new E14());
      return true;
    case TokenType::opA:
    case TokenType::opM:
    case TokenType::ID:
      automaton->decalage(t, new E11());
      return true;
    case TokenType::VAL:
      automaton->decalage(t, new E12());
      return true;
    case TokenType::PO:
      automaton->decalage(t, new E13());
      return true;
    default:
      return false;
  }
  return false;
}
