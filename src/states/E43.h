//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#ifndef SRC_STATES_E43_H_
#define SRC_STATES_E43_H_

#include "../State.h"
#include "../ASTNode.h"
#include "../Automaton.h"

class E43 : public State {
 public :
    E43();
    bool transition(Automaton *automaton, ASTNode *t);
    inline int stateNumber(){return 43;}
};

#endif  // SRC_STATES_E43_H_
