//
//  action.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include <stack>
#include "src/Action.h"

ActionAccept::ActionAccept() { }

bool ActionAccept::transition(const Transitions &  transitions,
       Stack<State> stackStates, bool * epsilon) {
    *epsilon = false;
    return true;
}
