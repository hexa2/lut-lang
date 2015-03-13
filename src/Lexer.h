//
//  Lexer.h
//  lut-lang
//
//  Created by Mehdi Kitane on 13/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef __lut_lang__Lexer__
#define __lut_lang__Lexer__

#include <stdio.h>
#include "ASTTerminalSymbol.h"
#include <stack>
#include <string>
class Lexer {
public:
    Lexer(std::string *inputString);
    
    ASTTerminalSymbol peak();
    ASTTerminalSymbol pop();
    bool hasNext();
    
    
protected :
    std::string *inputString;
    std::stack<ASTTerminalSymbol> *stackSymbols;
    
};

#endif /* defined(__lut_lang__Lexer__) */
