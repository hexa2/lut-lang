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
#include "TokenType.h"
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


Lexer::Lexer(string inString) : inputString(inString), currentToken(TokenType::INVALID_SYMBOL) {
}

bool Lexer::has_next() {
  // remove spaces before analyzing
  // we remove left spaces and not right to handle cases like "const "
  ltrim(inputString);
  return inputString.length() > 0;
}

ASTTokenNode* Lexer::top() {
  if ( currentToken.getTokenType() != TokenType::INVALID_SYMBOL ) {
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
    currentToken = ASTTokenNode(TokenType::INVALID_SYMBOL);
    inputString.erase(0, 1);    // not sure
    return;
  }
  inputString  = m.suffix().str();
}


bool Lexer::analyze(string s, smatch &m) {
  if ( std::regex_search(inputString, m, keyword) ) {
    std::string currentTokenValue = m.str();
    switch (currentTokenValue[0]) {
      case 'c':
        currentToken = ASTTokenNode(TokenType::CONST); 
        break;
      case 'v':
        currentToken = ASTTokenNode(TokenType::VAR);
        break;
      case 'e':
        currentToken = ASTTokenNode(TokenType::WRITE);
        break;
      case 'l':
        currentToken = ASTTokenNode(TokenType::READ);
        break;
      default:
        return false;
    }
  } else if ( std::regex_search(inputString, m, identifier) ) {
    std::string currentTokenValue = m.str();
    currentToken = ASTTokenNode(TokenType::ID, currentTokenValue);
  } else if ( std::regex_search(inputString, m, number) ) {
    std::string currentTokenValue = m.str();
    currentToken = ASTTokenNode(TokenType::VAL, currentTokenValue);
  } else if ( std::regex_search(inputString, m, single_operators) ) {
    std::string currentTokenValue = m.str();
    switch (currentTokenValue[0]) {
      case '+':
        currentToken = ASTTokenNode(TokenType::ADD);
        break;
      case '-':
        currentToken = ASTTokenNode(TokenType::SUB);
        break;
      case '*':
        currentToken = ASTTokenNode(TokenType::MUL);
        break;
      case '/':
        currentToken = ASTTokenNode(TokenType::DIV);
        break;
      case '(':
        currentToken = ASTTokenNode(TokenType::PO);
        break;
      case ')':
        currentToken = ASTTokenNode(TokenType::PF);
        break;
      case ';':
        currentToken = ASTTokenNode(TokenType::PV);
        break;
      case '=':
        currentToken = ASTTokenNode(TokenType::EQ);
        break;
      case ',':
        currentToken = ASTTokenNode(TokenType::V);
        break;
      default:
        return false;
    }
  } else if ( std::regex_search(inputString, m, affectation) ) {
    currentToken = ASTTokenNode(TokenType::AFF);
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
      cout<<"something";
    }
  }
}
