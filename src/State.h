//
//  states.h
//  lut-lang
//
//  Created by Kevin Antoine on 11/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//


#ifndef SRC_STATE_H_
#define SRC_STATE_H_


class Automaton;
class ASTTokenNode;

class State {
 public:
    State() { }
    virtual bool transition(Automaton & automaton, ASTTokenNode * t) = 0;
};



#endif  // SRC_STATE_H_
