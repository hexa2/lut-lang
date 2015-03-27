//
            //  automaton.cpp
//  lut-lang
//
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.

#include "E32.h"
#include "../State.h"
#include "../TokenType.h"
#include "../ASTDeclarationBlockNode.h"
E32::E32() : State() { }

bool E32::transition(Automaton *automaton, ASTNode *t) {
    ASTDeclarationBlockNode token = ASTDeclarationBlockNode(NULL);
    switch ( t->getTokenType() ) {
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
            //  Reduction N°3 - 7 Level Pop - "D->D const id eq val L2 pv"
          for ( int i = 0 ; i < 7 ; i++ ) {
            automaton->getStackASTNodes()->pop();
            automaton->getStackStates()->pop();
          }
          if ( !automaton->getStackStates()->top()->transition(automaton, &token))
            return false;
          if ( !automaton->getStackStates()->top()->transition(automaton, t))
            return false;
          return true;
        default:
            return false;
    }
    return false;
}
