//
//  action.h
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#ifndef SRC_STATES_E13_H_
#define SRC_STATES_E13_H_

#include "../State.h"
#include "../ASTNode.h"
#include "../Automaton.h"
#include "../TokenType.h"


class E13 : public State {
 public :
    E13();
    bool transition(Automaton *automaton, ASTNode *t);
    inline int stateNumber(){return 13;}
};

#endif  // SRC_STATES_E13_H_
