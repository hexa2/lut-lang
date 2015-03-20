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
const char keyword_str[] = "^(const |var |ecrire |lire )";
const char identifier_str[] = "^([a-zA-Z][a-zA-Z0-9]*)";
const char number_str[] =  "^([-+]?[0-9]*\\.?[0-9]+)";
const char single_operators_str[] = "^(\\+|-|\\*|\\/|\\(|\\)|;|=|,)";
const char affectation_str[] = "^(:=)";

const std::regex keyword(keyword_str);
const std::regex identifier(identifier_str);
const std::regex number(number_str);
const std::regex single_operators(single_operators_str);
const std::regex affectation(affectation_str);


Lexer::Lexer(string inString) : inputString(inString) {
}

bool Lexer::has_next() {
  // remove spaces before analyzing
  // we remove left spaces and not right to handle cases like "const "
  ltrim(inputString);
  return inputString.length() > 0;
}

ASTTokenNode* Lexer::top() {
  if ( currentToken.getSymbol().length() > 0 ) {
    return &currentToken;
  }
  return NULL;
}

void Lexer::shift() {
  if ( !has_next() )
    return;

  std::smatch m;
  if ( !analyze(inputString, m) ) {
    cout <<"cant shift" <<endl;
    currentToken = ASTTokenNode();
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
        currentToken = ASTTokenNode(keyword_str , "const");
        break;
      case 'v':
        currentToken = ASTTokenNode(keyword_str , "var");
        break;
      case 'e':
        currentToken = ASTTokenNode(keyword_str , "ecrire");
        break;
      case 'l':
        currentToken = ASTTokenNode(keyword_str , "lire");
        break;
      default:
        return false;
    }
  } else if ( std::regex_search(inputString, m, identifier) ) {
    currentTokenValue = m.str();
    currentToken = ASTTokenNode(identifier_str , currentTokenValue);
  } else if ( std::regex_search(inputString, m, number) ) {
    currentTokenValue = m.str();
    currentToken = ASTTokenNode(number_str , currentTokenValue);
  } else if ( std::regex_search(inputString, m, single_operators) ) {
    currentTokenValue = m.str();
    switch (currentTokenValue[0]) {
      case '+':
        currentToken = ASTTokenNode(single_operators_str , "+");
        break;
      case '-':
        currentToken = ASTTokenNode(single_operators_str , "-");
        break;
      case '*':
        currentToken = ASTTokenNode(single_operators_str , "*");
        break;
      case '/':
        currentToken = ASTTokenNode(single_operators_str , "/");
        break;
      case '(':
        currentToken = ASTTokenNode(single_operators_str , "(");
        break;
      case ')':
        currentToken = ASTTokenNode(single_operators_str , ")");
        break;
      case ';':
        currentToken = ASTTokenNode(single_operators_str , ";");
        break;
      case '=':
        currentToken = ASTTokenNode(single_operators_str , "=");
        break;
      case ',':
        currentToken = ASTTokenNode(single_operators_str , ",");
        break;
      default:
        return false;
    }
  } else if ( std::regex_search(inputString, m, affectation) ) {
    currentTokenValue = m.str();
    currentToken = ASTTokenNode(affectation_str , ":=");
  } else {
    return false;
  }

  return true;
}


void test() {
  Lexer a = Lexer("const a = 5.34  ; \n const b = -2.5 ; ç const b = 5");

  while ( a.has_next() ) {
    a.shift();
    if ( a.top() ) {
      cout<< "top is " << a.top()->getSymbol() << endl;
    }
  }
}
