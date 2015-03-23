//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E1.h"
#include "../State.h"

E1::E1() : State() { }

bool E1::transition(Automaton *automaton, ASTTokenNode *t ) {
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
