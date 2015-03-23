//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#ifndef SRC_STATES_E34_H_
#define SRC_STATES_E34_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E34 : public State {
 public :
    E34();
    bool transition(Automaton *automaton, ASTTokenNode *t);
    inline int stateNumber(){return 34;}
};

#endif  // SRC_STATES_E34_H_
