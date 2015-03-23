//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#ifndef SRC_STATES_E20_H_
#define SRC_STATES_E20_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E20 : public State {
 public :
    E20();
    bool transition(Automaton *automaton, ASTTokenNode *t);
    inline int stateNumber(){return 20;}
};

#endif  // SRC_STATES_E20_H_
