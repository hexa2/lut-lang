//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include <stack>
#include "src/Automaton.h"

Automaton::Automaton() {
    transitions[State::E0][Token::P] = new ActionAccept();
    transitions[State::E1][Token::P] = new ActionAccept();
}

bool Automaton::Exists(State s, Token t) {
    return transitions.find(s) != transition.end()
            && transitions[s].find(t) != transition.end();
}

bool Automaton::Accepts(Lexer * lexer) {
    stackStates.push(State::E0);
    bool epsilon = true;
    while (!stackStates.empty()) {
        State s = stackStates.pop();
        Token t = lexer->pop();
        if (!this->Exists(s, t)) {
            return false;
        }
        transitions[s][t]->transition(transition, & stackStates, &epsilon);
        if (epsilon) { }
    }
    return true;
}
