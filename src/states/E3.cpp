//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E3.h"
#include "../State.h"
#include "../TokenType.h"

E3::E3() : State() { }

bool E3::transition(Automaton *automaton, ASTNode *t) {
    return true;
}
