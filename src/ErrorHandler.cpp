//
//  ErrorHandler.cpp
//  lut-lang
//
//  Created by Karim Benhmida on 30/03/2015.
//  Copyright (c) 2015 Karim Benhmida. All rights reserved.
//

#include "ErrorHandler.h"
#include <iostream>

void ErrorHandler::DoubleDeclaration(string nomVariable){
  errorsQueue->push("la variable " + nomVariable + " est deja declaree");
}

void ErrorHandler::DoubleDeclarationConst(string nomConstante){
  errorsQueue->push("la constante " + nomConstante + " est deja declaree");
}

void ErrorHandler::NonDeclared() {
  errorsQueue->push("la variable a n'a pas ete declaree.");
}

void ErrorHandler::LexicalError(int line, int col, char character) {
  errorsQueue->push("Erreur lexicale ("+ std::to_string(line) +":"+ std::to_string(col) +") caractere "+ character);
}

void ErrorHandler::outputErrors() {
  while(!errorsQueue->empty()){
    std::cerr << errorsQueue->front() << std::endl;
    errorsQueue->pop();
  }
}