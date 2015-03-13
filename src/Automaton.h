//
//  automaton.h
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include <map>
#include "src/State.h"
#include "src/Token.h"


#ifndef SRC_AUTOMATON_H_
#define SRC_AUTOMATON_H_


#include <stack>
typedef std::map<State, map<Token, Action *> Transitions;

class Automaton {
 public:
    Automaton();
    bool Exists(Transitions * transitions, State s, Token t);
    bool Accepts(Lexer * lexer, State s, Token t);
 protected:
    Transitions transitions;
    stack<Token> * stackTokens;
    stack<State> * stackStates;
};

#endif  // SRC_AUTOMATON_H_
