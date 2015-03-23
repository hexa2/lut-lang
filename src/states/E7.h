//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.    
//
#ifndef SRC_STATES_E7_H_
#define SRC_STATES_E7_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E7 : public State {
    public:
        E7();
        bool transition(Automaton *automaton, ASTTokenNode *t);
        inline int stateNumber(){return 7;}
};
    
#endif  // SRC_STATES_E7_H_