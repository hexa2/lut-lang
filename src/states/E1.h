//
//  action.h
//  lut-lang
//
//  Created by Kevin Antoine on 15/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_STATES_E1_H_
#define SRC_STATES_E1_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E1 : public State {
 public:
    E1();
    bool transition(Automaton *automaton, ASTTokenNode *t);
    inline int stateNumber(){return 1;}
};

#endif  //  SRC_STATES_E1_H_
