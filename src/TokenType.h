//
//  TokenType.h
//  lut-lang
//
//  Created by Mehdi Kitane on 22/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef lut_lang_TokenType_h
#define lut_lang_TokenType_h

enum class SymbolType {
  
  //Non Terminal Symbols
  P,
  D,
  L1,
  L2,
  I,
  E,
  T,
  F,
  opA,
  opM,
  
  //Terminal Symbols
  VAR,
  CONST,
  ID,
  VAL,
  PV, //Semi Colon
  V, //Comma
  AFF,
  EQ,
  ADD,
  SUB,
  MUL,
  DIV,
  PO, //Open With (
  PF, //Close with )
  WRITE,
  READ,
  
  //End
  $
};

#endif
