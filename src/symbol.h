//
//  symbol.h
//  lut-lang
//
//  Created by Kevin Antoine on 08/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_SYMBOL_H_
#define SRC_SYMBOL_H_

class Symbol {
 protected:
    int ident;
 public:
    explicit Symbol(int id) : ident(id) {}
    virtual ~Symbol() {}
    void print();
    operator int() const {return ident;}
};

#endif  // SRC_SYMBOL_H_
