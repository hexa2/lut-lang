//
//  automaton.h
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include <map>
#include "State.h"
#include "AstTokenNode.h"


#ifndef SRC_AUTOMATON_H_
#define SRC_AUTOMATON_H_


#include <stack>
typedef std::map<State, map<AstTokenNode, Action *> Transitions;

class Automaton {
 public:
    Automaton();
    bool Exists(Transitions * transitions, State s, AstTokenNode t);
    bool Accepts(Lexer * lexer, State s, AstTokenNode t);
 protected:
    Transitions transitions;
    stack<AstTokenNode> * stackAstTokenNodes;
    stack<State> * stackStates;
};

#endif  // SRC_AUTOMATON_H_
