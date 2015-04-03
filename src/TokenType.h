//
//  TokenType.h
//  lut-lang
//
//  Created by Mehdi Kitane on 22/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_TOKENTYPE_H_
#define SRC_TOKENTYPE_H_

enum class TokenType {
// -------Non Terminal Symbols-----

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

// -----Terminal Symbols-----

  VAR,
  CONST,
  ID,
  VAL,
  // PV = Semi Colon
  PV,
  // V = Comma
  V,
  AFF,
  EQ,
  ADD,
  SUB,
  MUL,
  DIV,
  // Open With (
  PO,
  // Close with )
  PF,
  WRITE,
  READ,
  ENDOFFILE,
  INVALID_SYMBOL
};

#endif  //  SRC_TOKENTYPE_H_
