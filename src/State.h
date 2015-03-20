//
//  states.h
//  lut-lang
//
//  Created by Kevin Antoine on 11/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//


#ifndef SRC_STATE_H_
#define SRC_STATE_H_

Class State {
    enum Id {
    E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10
    };
    explicit State(State::Id id) : m_id(id) { }
    operator const State::Id();
    State::Id m_id;
    virtual bool transition(Automaton & automaton, ASTTokenNode * t) = 0;
};



#endif  // SRC_STATE_H_
