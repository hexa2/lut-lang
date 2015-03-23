//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.    
//
#ifndef SRC_STATES_E9_H_
#define SRC_STATES_E9_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E9 : public State {
    public:
        E9();
        bool transition(Automaton *automaton, ASTTokenNode *t);
        inline int stateNumber(){return 9;}
};
    
#endif  // SRC_STATES_E9_H_