//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E0.h"
#include "E1.h"
#include "../state.h"

E0::E0 () : State() { };

bool E0::transition (Automaton *automaton, ASTTokenNode *t) {

  if( t->getSymbol().compare("Declaration") == 0)
  {
    automaton->shift(t, new E1());
  }
  // switch(*t) {
  // case D :
  // automaton.setState(t, new E1());
  // break;
  // case I :
  // automaton.setState(t, new E1());
  //     break;
  //   default :
  //     break;
  // }
  return false;
}