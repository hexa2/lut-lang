//
//  action.h
//  lut-lang
//
//  Created by Kevin Antoine on 13/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_

#include <stack>
#include <map>
#include "State.h"
#include "ASTTokenNode.h"
// #include "Types.h"
using std::map;
using std::stack;

class Action {
 public:
    typedef map<State::Id, map<ASTTokenNode, Action *> > Transitions;
    virtual ~Action() {}
};

class ActionAccept : public Action{
 public:
    ActionAccept();
    bool transition(const Transitions & transitions,
            stack<State::Id> stackStates, bool * epsilon);
};

class ActionShift : public Action{
 public:
    ActionShift();
    bool transition(const Transitions & transitions,
            stack<State::Id> stackStates, bool * epsilon);
};

class ActionReduce : public Action{
 public:
    ActionReduce();
    bool transition(const Transitions & transitions,
            stack<State::Id> stackStates, bool * epsilon);
};

#endif  // SRC_ACTION_H_
