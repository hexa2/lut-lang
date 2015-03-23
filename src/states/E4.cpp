//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E4.h"
#include "E5.h"
#include "E15.h"
#include "E14.h"
#include "E11.h"
#include "E12.h"
#include "E13.h"
#include "../State.h"
#include "../TokenType.h"

E4::E4() : State() { }

bool E4::transition(Automaton *automaton, ASTTokenNode *t) {
    switch ( t->getTokenType() ) {
        case TokenType::D:
            return true;
        case TokenType::E:
          automaton->decalage(t, new E5());
            return true;
        case TokenType::T:
          automaton->decalage(t, new E15());
            return true;
        case TokenType::F:
          automaton->decalage(t, new E14());
            return true;
        case TokenType::ID:
          automaton->decalage(t, new E11());
            return true;
        case TokenType::VAL:
          automaton->decalage(t, new E12());
            return true;
        case TokenType::PO:
          automaton->decalage(t, new E13());
            return true;
        default:
            return false;
    }
    return false;
}
