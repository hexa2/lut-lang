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

/**
 * @class
 * Defines an enumeration of variable declarations
 */
class Lexer {
 public:
  /**
   * @constructor
   * @param inString The string that will be parsed
   */
  explicit Lexer(string inString);

  /**
   * @return Returns true if there is something else to read in the string
   *
   */
  bool has_next();

  /**
   * @return the last token parsed
   *
   */
  ASTTokenNode* top();

  /**
   * Moves to the next token
   */
  void shift();

  int getLine();
  int getColumn();

 protected :
  int line;
  int column;
  int column_next_incrementation;
  std::string inputString;
  ASTTokenNode *currentToken;

  bool analyze(string s, std::smatch &m);
  int find_first_not_of(string str);
  string& ltrim(string& s);
};

#endif  // SRC_LEXER_H_
