//
//  automaton.h
//  lut-lang
//
//  Created by Kevin Antoine on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//



#ifndef SRC_AUTOMATON_H_
#define SRC_AUTOMATON_H_

#include <map>
#include <stack>
#include <string>
#include "State.h"
#include "ASTTokenNode.h"
#include "Action.h"
// #include "Types.h"
#include "Lexer.h"

using std::map;
using std::stack;


class Automaton {
 public:
    Automaton::Automaton();
    explicit Automaton(std::string filepath) : m_lexer(new Lexer(filepath)) {}
    bool Exists(State::Id s, ASTTokenNode t);
    bool Accepts(Lexer * lexer);
 protected:
    Action::Transitions transitions;
    stack<ASTTokenNode> * stackASTTokenNodes;
    stack<State::Id> * stackStates;
};

#endif  // SRC_AUTOMATON_H_
