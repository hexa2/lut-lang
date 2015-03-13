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
#include <regex>
#include <string>
#include "ASTTokenNode.h"

using std::string;

class Lexer {
 public:
  // Sets the input source to be a stream
  explicit Lexer(string inString);

  // Returns true if there is something else to read with next(&type)
  bool has_next();

  // Returns the next token
  ASTTokenNode* top();

  // Moves to the next token
  void shift();


 protected :
  std::string inputString;
  std::string currentToken;
  std::string currentTokenValue;

  bool analyze(string s, std::smatch &m);
  inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v") {
    s.erase(0, s.find_first_not_of(t));
    return s;
  }
};

#endif  // SRC_LEXER_H_
