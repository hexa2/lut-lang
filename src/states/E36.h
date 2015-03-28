//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#ifndef SRC_STATES_E36_H_
#define SRC_STATES_E36_H_

#include "../State.h"
#include "../ASTNode.h"
#include "../Automaton.h"

class E36 : public State {
 public :
    E36();
    bool transition(Automaton *automaton, ASTNode *t);
    inline int stateNumber(){return 36;}
};

#endif  // SRC_STATES_E36_H_
