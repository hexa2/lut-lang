//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#ifndef SRC_STATES_E10_H_
#define SRC_STATES_E10_H_

#include "../State.h"
#include "../ASTNode.h"
#include "../Automaton.h"

class E10 : public State {
 public :
    E10();
    bool transition(Automaton *automaton, ASTNode *t);
    inline int stateNumber(){return 10;}
};

#endif  // SRC_STATES_E10_H_
