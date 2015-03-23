//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#ifndef SRC_STATES_E40_H_
#define SRC_STATES_E40_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E40 : public State {
 public :
    E40();
    bool transition(Automaton *automaton, ASTTokenNode *t);
    inline int stateNumber(){return 40;}
};

#endif  // SRC_STATES_E40_H_
