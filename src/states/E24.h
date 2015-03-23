//
//  action.h
//  lut-lang
//
//  Created by Mehdi Kitane on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_STATES_E24_H_
#define SRC_STATES_E24_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E24 : public State {
public:
  E24();
  bool transition(Automaton *automaton, ASTTokenNode *t);
  inline int stateNumber(){return 24;}
};

#endif  // SRC_STATES_E24_H_
