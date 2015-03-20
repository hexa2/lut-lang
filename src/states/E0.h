//
//  action.h
//  lut-lang
//
//  Created by Kevin Antoine on 15/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_STATES_E0_H_
#define SRC_STATES_E0_H_

#include "../state.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E0 : public State {
  public:
    E0();
    bool transition(Automaton & automaton, ASTTokenNode * t);
};

#endif // SRC_STATES_E0_H_