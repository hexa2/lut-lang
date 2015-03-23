//
<<<<<<< HEAD
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E21.h"
#include "../State.h"
#include "../TokenType.h"

E21::E21() : State() { }

bool E21::transition(Automaton *automaton, ASTTokenNode *t) {
    ASTTokenNode token = ASTTokenNode(TokenType::D);
    switch ( t->getTokenType() ) {
        case TokenType::D:
            // automaton->decalage(t, new E1());
            return true;
        case TokenType::P:
        case TokenType::L1:
        case TokenType::L2:
        case TokenType::I:
        case TokenType::E:
        case TokenType::T:
        case TokenType::F:
        case TokenType::opA:
        case TokenType::opM:

        case TokenType::VAR:
        case TokenType::CONST:
        case TokenType::ID:
        case TokenType::VAL:
        case TokenType::PV:
        case TokenType::V:
        case TokenType::AFF:
        case TokenType::EQ:
        case TokenType::ADD:
        case TokenType::SUB:
        case TokenType::MUL:
        case TokenType::DIV:
        case TokenType::PO:
        case TokenType::PF:
        case TokenType::WRITE:
        case TokenType::READ :
        case TokenType::INVALID_SYMBOL:
        case TokenType::ENDOFFILE :
            //  Reduce
            token = ASTTokenNode(TokenType::D);
            automaton->stackStates.top()->transition(automaton, &token);
            return true;
        default:
            return false;
    }
    return false;
=======
//  automaton.cpp
//  lut-lang
//
//  Created by Mehdi Kitane on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "../State.h"
#include "../TokenType.h"
#include "E21.h"
#include "E22.h"
E21::E21() : State() { }

bool E21::transition(Automaton *automaton, ASTTokenNode *t) {

  switch ( t->getTokenType() ) {
    case TokenType::ID:
      automaton->decalage(t, new E22());
      return true;
    default:
      return false;
  }
  return false;
>>>>>>> 9b0624d56118d69be55a91f187e56db1948ef7b7
}
