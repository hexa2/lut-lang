//
//  automaton.cpp
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
#include <stack>
#include "Automaton.h"

Automaton::Automaton() {
    // transitions[State::E1][ASTTokenNode] = new ActionAccept();
    // transitions[State::E0][ASTTokenNode] = new ActionAccept();
}

bool Automaton::Exists(State::Id s, ASTTokenNode t) {
    // return transitions.find(s) != transition.end()
    // && transitions[s].find(t) != transition.end();
    return true;
}

bool Automaton::Accepts(Lexer * lexer) {
    // stackStates->push(State::E0);
    // bool epsilon = true;
    // while (!stackStates->empty()) {
    //     State s = stackStates->pop();
    //     ASTTokenNode t = lexer->pop();
    //     if (!this->Exists(s, t)) {
    //        return false;
    //     }
    // transitions[s][t]->transition(& transition,
    // & stackStates, &epsilon);
    //     if (epsilon) { }
    // }
    return true;
}
