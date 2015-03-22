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
#include "ASTTokenNode.h"
#include "Lexer.h"
#include "State.h"

using std::map;
using std::stack;


class Automaton {
public:
  explicit Automaton(std::string filepath);
  bool accepts();
  
  void decalage(ASTTokenNode* t, State* s);
  void reduce(int i);
  stack<ASTTokenNode*> stackASTTokenNodes;
  stack<State*> stackStates;
protected:
 	Lexer * lexer;

};

#endif  // SRC_AUTOMATON_H_
