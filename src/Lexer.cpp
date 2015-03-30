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
#include "ErrorHandler.h"
using std::cout;
using std::endl;
using std::smatch;
using std::string;
using std::regex_search;
using std ::smatch;

// Regexs
const char keyword_str[] = "^(const |var |ecrire |lire )";
const char identifier_str[] = "^([a-zA-Z][a-zA-Z0-9]*)";
const char number_str[] =  "^([0-9]*\\.?[0-9]+)";
const char single_operators_str[] = "^(\\+|-|\\*|\\/|\\(|\\)|;|=|,)";
const char affectation_str[] = "^(:=)";

const std::regex keyword(keyword_str);
const std::regex identifier(identifier_str);
const std::regex number(number_str);
const std::regex single_operators(single_operators_str);
const std::regex affectation(affectation_str);

int Lexer::find_first_not_of(string str) {
  string::iterator it;
  int index = 0;
  for (it = str.begin(); it < str.end(); it++, index++) {
    switch ( str.at(index) ) {
      case ' ':
        this->column++;
        break;
      case '\t':
        break;
      case '\n':
        this->line++;
        this->column = 0;
        break;
      case '\r':
        break;
      case '\f':
        break;
      case '\v':
      default:
        return index;
        break;
    }
  }
  return -1;
}
string& Lexer::ltrim(string& s) {
  s.erase(0, find_first_not_of(s));
  return s;
}


Lexer::Lexer(string inString) : inputString(inString) {
  this->currentToken = new ASTTokenNode(TokenType::INVALID_SYMBOL);
  this->line = 0;
  this->column = 0;
  this->column_next_incrementation = 0;
}

bool Lexer::has_next() {
  // remove spaces before analyzing
  // we remove left spaces and not right to handle cases like "const "
  ltrim(inputString);
  if ( inputString.length() <= 0 ) {
    currentToken = new ASTTokenNode(TokenType::ENDOFFILE);
    return false;
  }
  return true;
}

ASTTokenNode* Lexer::top() {
  return currentToken;
}

void Lexer::shift() {
  if ( !has_next() )
    return;

  this->column += this->column_next_incrementation;

  std::smatch m;
  if ( !analyze(inputString, m) ) {
    ErrorHandler::getInstance().LexicalError(this->getLine(), this->getColumn(), inputString.at(0));
    ErrorHandler::getInstance().outputErrors();
    currentToken = new ASTTokenNode(TokenType::INVALID_SYMBOL);
    inputString.erase(0, 1);    // not sure
    return;
  }
  this->column_next_incrementation = (int)m.length();
  inputString  = m.suffix().str();
}


bool Lexer::analyze(string s, smatch &m) {
  if ( std::regex_search(inputString, m, keyword) ) {
    std::string currentTokenValue = m.str();
    switch (currentTokenValue[0]) {
      case 'c':
        currentToken = new ASTTokenNode(TokenType::CONST);
        break;
      case 'v':
        currentToken = new ASTTokenNode(TokenType::VAR);
        break;
      case 'e':
        currentToken = new ASTTokenNode(TokenType::WRITE);
        break;
      case 'l':
        currentToken = new ASTTokenNode(TokenType::READ);
        break;
      default:
      #warning "symbole non reconnu"
        return false;
    }
  } else if ( std::regex_search(inputString, m, identifier) ) {
    std::string currentTokenValue = m.str();
    currentToken = new ASTTokenNode(TokenType::ID, currentTokenValue);
  } else if ( std::regex_search(inputString, m, number) ) {
    std::string currentTokenValue = m.str();
    currentToken = new ASTTokenNode(TokenType::VAL, currentTokenValue);
  } else if ( std::regex_search(inputString, m, single_operators) ) {
    std::string currentTokenValue = m.str();
    switch (currentTokenValue[0]) {
      case '+':
        currentToken = new ASTTokenNode(TokenType::ADD, "+");
        break;
      case '-':
        currentToken = new ASTTokenNode(TokenType::SUB, "-");
        break;
      case '*':
        currentToken = new ASTTokenNode(TokenType::MUL, "*");
        break;
      case '/':
        currentToken = new ASTTokenNode(TokenType::DIV, "/");
        break;
      case '(':
        currentToken = new ASTTokenNode(TokenType::PO);
        break;
      case ')':
        currentToken = new ASTTokenNode(TokenType::PF);
        break;
      case ';':
        currentToken = new ASTTokenNode(TokenType::PV);
        break;
      case '=':
        currentToken = new ASTTokenNode(TokenType::EQ);
        break;
      case ',':
        currentToken = new ASTTokenNode(TokenType::V);
        break;
      default:
        #warning "symbole non reconnu"
        return false;
    }
  } else if ( std::regex_search(inputString, m, affectation) ) {
    currentToken = new ASTTokenNode(TokenType::AFF);
  } else {
    #warning "symbole non reconnu"
    return false;
  }
return true;
}


int Lexer::getLine() {
  return this->line+1;
}
int Lexer::getColumn() {
  return this->column+1;
}
