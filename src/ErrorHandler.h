//
//  ErrorHandler.h
//  lut-lang
//
//  Created by Karim Benhmida on 30/03/2015.
//  Copyright (c) 2015 Karim Benhmida. All rights reserved.
//

#ifndef SRC_ERRORHANDLER_H_
#define SRC_ERRORHANDLER_H_

#include <stdio.h>
#include <queue>
#include <string>
using std::string;
using std::queue;


class ErrorHandler{
 public:
  static ErrorHandler& getInstance() {
    static ErrorHandler instance;  // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
  }

  void DoubleDeclaration(string nomVariable);
  void DoubleDeclarationConst(string nomConstante);
  void NonDeclared();
  void LexicalError(int line, int col, char character);
  void SyntaxErrorSymbole(int line, int col, string symbol);

  void outputErrors();

 private:
  ErrorHandler() {
    this->errorsQueue = new queue<string>();
  }
  queue<string> *errorsQueue;
};

#endif  // SRC_ERRORHANDLER_H_
