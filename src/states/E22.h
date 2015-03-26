//
//  action.h
//  lut-lang
//
//  Created by Kevin Antoine on 15/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_STATES_E22_H_
#define SRC_STATES_E22_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E22 : public State {
 public :
    E22();
    bool transition(Automaton *automaton, ASTTokenNode *t);
    inline int stateNumber(){return 22;}
};

#endif  // SRC_STATES_E22_H_
