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

bool ActionAccept::transition(const Transitions &  transitions,
       std::stack<State::Id> stackStates, bool * epsilon) {
    *epsilon = false;
    return true;
}

ActionShift::ActionShift() { }

bool ActionShift::transition(const Transitions &  transitions,
       std::stack<State::Id> stackStates, bool * epsilon) {
    *epsilon = false;
    return true;
}

ActionReduce::ActionReduce() { }

bool ActionReduce::transition(const Transitions &  transitions,
       std::stack<State::Id> stackStates, bool * epsilon) {
    *epsilon = false;
    return true;
}
