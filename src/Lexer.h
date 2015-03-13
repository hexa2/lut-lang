//
//  Lexer.h
//  lut-lang
//
//  Created by Mehdi Kitane on 13/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_LEXER_H_
#define SRC_LEXER_H_

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include "ASTTerminalSymbol.h"

using std::string;
using std::stringstream;

class Lexer {
 public:
  // Sets the input source to be a stream
  // If shift is set, it will automatically shift once upon construction
  explicit Lexer(stringstream * inStream);

  // Returns true if there is something else to read with next(&type)
  bool has_next() const;

  // Returns the next token **without** moving to the next token
  ASTTerminalSymbol top();

  // Moves to the next token
  void shift();

 protected :
  stringstream *inputStream;
  void analyze();
};

#endif  // SRC_LEXER_H_
