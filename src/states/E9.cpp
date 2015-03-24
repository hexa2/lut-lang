//
//  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E9.h"
#include "E10.h"
#include "E111.h"
#include "E12.h"
#include "E12.h"
#include "../State.h"
#include "../TokenType.h"

E9::E9() : State() { }

bool E9::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
    case TokenType::F:
      automaton->decalage(t, new E10());
      return true;
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
