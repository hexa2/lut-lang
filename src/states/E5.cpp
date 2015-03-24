//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E5.h"
#include "E7.h"
#include "E6.h"
#include "E41.h"
#include "E42.h"
#include "../State.h"
#include "../TokenType.h"

E5::E5() : State() { }

bool E5::transition(Automaton *automaton, ASTTokenNode *t) {
  ASTTokenNode token = ASTTokenNode(TokenType::D);
  switch ( t->getTokenType() ) {
    case TokenType::opA:
      automaton->decalage(t, new E7());
      return true;
    case TokenType::PV:
      automaton->decalage(t, new E6());
      return true;
    case TokenType::ADD:
      automaton->decalage(t, new E41());
      return true;
    case TokenType::SUB:
      automaton->decalage(t, new E42());
      return true;
    default:
      return false;
  }
  return false;
}
