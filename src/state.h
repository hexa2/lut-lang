//
//  automaton.h
//  lut-lang
//
//  Created by Kevin Antoine on 11/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include <iostream>
#include <string>

using std::string;

class State {
 public:
    explicit State(std::string name);
    virtual ~State();
    void print() const;
    virtual bool transition(Automaton * automaton, Symbole * s) = 0;
 protected:
    string name;
};

#endif  // SRC_STATE_H_
