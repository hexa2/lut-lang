//
//  states.h
//  lut-lang
//
//  Created by Kevin Antoine on 11/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//


#ifndef SRC_STATE_H_
#define SRC_STATE_H_

struct State {
    enum StateName {
    E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10
    };
    explicit State(State::StateName name) : m_name(name) { }
    operator State::StateName();
};


#endif  // SRC_STATE_H_
