//
//  Lexer.cpp
//  lut-lang
//
//  Created by Mehdi Kitane on 13/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#include "Lexer.h"
#include <string>
#include <regex>
#include <iostream>

using std::cout;
using std::endl;
using std::smatch;
using std::string;
using std::regex_search;
using std ::smatch;
// Regexs
const std::regex keyword("^(const |var |ecrire |lire )");
const std::regex identifier("^([a-zA-Z][a-zA-Z0-9]*)");
const std::regex number("^([-+]?[0-9]*\\.?[0-9]+)");
const std::regex single_operators("^(\\+|-|\\*|\\/|\\(|\\)|;|=|,)");
const std::regex affectation("^(:=)");


Lexer::Lexer(string inString) : inputString(inString) {
}

bool Lexer::has_next() {
  // remove spaces before analyzing
  // we remove left spaces and not right to handle cases like "const "
  ltrim(inputString);
  return inputString.length() > 0;
}

ASTTokenNode* Lexer::top() {
  if ( currentToken.length() > 0 ) {
    cout<< "top is " << currentToken << endl;
    return NULL;
  }
  return NULL;
}

void Lexer::shift() {
  if ( !has_next() )
    return;

  std::smatch m;
  if ( !analyze(inputString, m) ) {
    cout <<"cant shift" <<endl;
    currentToken = "";
    currentTokenValue = "";
    inputString.erase(0, 1);    // not sure
    return;
  }
  inputString  = m.suffix().str();
}


bool Lexer::analyze(string s, smatch &m) {
  if ( std::regex_search(inputString, m, keyword) ) {
    currentTokenValue = m.str();
    switch (currentTokenValue[0]) {
      case 'c':
        currentToken = "const ";
        break;
      case 'v':
        currentToken = "var ";
        break;
      case 'e':
        currentToken = "ecrire ";
        break;
      case 'l':
        currentToken = "lire ";
        break;
      default:
        return false;
    }
  } else if ( std::regex_search(inputString, m, identifier) ) {
    currentTokenValue = m.str();
    currentToken = "id";
  } else if ( std::regex_search(inputString, m, number) ) {
    currentTokenValue = m.str();
    currentToken = "number";
  } else if ( std::regex_search(inputString, m, single_operators) ) {
    currentTokenValue = m.str();
    switch (currentTokenValue[0]) {
      case '+':
        currentToken = "+";
        break;
      case '-':
        currentToken = "-";
        break;
      case '*':
        currentToken = "*";
        break;
      case '/':
        currentToken = "/";
        break;
      case '(':
        currentToken = "(";
        break;
      case ')':
        currentToken = ")";
        break;
      case ';':
        currentToken = ";";
        break;
      case '=':
        currentToken = "=";
        break;
      case ',':
        currentToken = ",";
        break;
      default:
        return false;
    }
  } else if ( std::regex_search(inputString, m, affectation) ) {
    currentTokenValue = m.str();
    currentToken = ":=";
  } else {
    return false;
  }

  return true;
}


void test() {
  Lexer a = Lexer("const a = 5.34  ; \n const b = -2.5 ; ç const b = 5");

  while ( a.has_next() ) {
    a.shift();
    a.top();
  }
}
