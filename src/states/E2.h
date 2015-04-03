//
//  E2.h
//  lut-lang
//  Created by Kevin Antoine on 15/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_STATES_E2_H_
#define SRC_STATES_E2_H_

#include "../State.h"
#include "../ASTNode.h"
#include "../Automaton.h"

class E2 : public State {
 public:
    E2();
    bool transition(Automaton *automaton, ASTNode *t);
    inline int stateNumber(){return 2;}
};

#endif  // SRC_STATES_E2_H_
