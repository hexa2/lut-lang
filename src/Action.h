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
#include "Automaton.h"
#include "ASTTokenNode.h"
// #include "Types.h"
using std::map;
using std::stack;


class Automaton;
	
class Action {
 public:
    // typedef map<State, map<ASTTokenNode, Action *> > Transitions;
    virtual ~Action() {}
};

class ActionAccept : public Action{
 public:
    ActionAccept();
    bool transition(Automaton * automaton, bool * epsilon);
};

class ActionShift : public Action{
 public:
    ActionShift();
    bool transition(Automaton * automaton, bool * epsilon);
};

class ActionReduce : public Action{
 public:
    ActionReduce();
    bool transition(Automaton * automaton, bool * epsilon);
};

#endif  // SRC_ACTION_H_
