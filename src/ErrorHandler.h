//
//  ErrorHandler.h
//  lut-lang
//
//  Created by Karim Benhmida on 30/03/2015.
//  Copyright (c) 2015 Karim Benhmida. All rights reserved.
//

#ifndef __lut_lang__ErrorHandler__
#define __lut_lang__ErrorHandler__

#include <stdio.h>
#include <queue>
#include <string>
using std::string;
using std::queue;


class ErrorHandler{
public:
  static ErrorHandler& getInstance()
  {
    static ErrorHandler instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
  }
  
  void DoubleDeclaration(string nomVariable);
  void DoubleDeclarationConst(string nomConstante);
  void NonDeclared();
  
  
  void outputErrors();
private:
  ErrorHandler() { this->errorsQueue = new queue<string>(); };
  queue<string> *errorsQueue;
  
};

#endif /* defined(__lut_lang__ErrorHandler__) */
