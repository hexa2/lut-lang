//
//  action.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include "Action.h"
#include <stack>

ActionAccept::ActionAccept() { }

bool ActionAccept::transition(Automaton * automaton, bool * epsilon) {
    *epsilon = false;
    return true;
}

ActionShift::ActionShift() { }

bool ActionShift::transition(Automaton * automaton, bool * epsilon) {
    *epsilon = false;
    return true;
}

ActionReduce::ActionReduce() { }

bool ActionReduce::transition(Automaton * automaton, bool * epsilon) {
    *epsilon = false;
    return true;
}
