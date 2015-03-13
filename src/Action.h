//
//  action.h
//  lut-lang
//
//  Created by Kevin Antoine on 13/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_

class Action {
 public:
    virtual ~Action();
};

class ActionAccept : public Action{
 public:
    transition(const Transitions & transitions,
            Stack<State> stackStates, bool * epsilon);
};

class ActionShift : public Action{
 public:
    transition(const Transitions & transitions,
            Stack<State> stackStates, bool * epsilon);
};

class ActionReduce : public Action{
 public:
    transition(const Transitions & transitions,
            Stack<State> stackStates, bool * epsilon);
};

#endif  // SRC_ACTION_H_
