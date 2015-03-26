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
using std::string;

/**
 * @class
 * Defines an enumeration of variable declarations
 */
class Automaton {
 public:
   /**
   * @constructor
   * @param string String representing the file 
   */
    explicit Automaton(string inputString);
    bool analyze();
   /**
   * @param ASTTokenNode t push t in Automaton stackToken
   * @param State s push s in Automaton stackState
   */
    void decalage(ASTTokenNode* t, State* s);

    stack<ASTTokenNode*> *getStackASTTokenNodes();

   stack<State*> *getStackStates();
   
   void setAccepted(bool acc);
  
   void reduce( ASTTokenNode tokenToReduce, int redNb);

 protected:
  stack<ASTTokenNode*> stackASTTokenNodes;
  stack<State*> stackStates;
  bool accepted;
  Lexer * lexer;
};

#endif  // SRC_AUTOMATON_H_
