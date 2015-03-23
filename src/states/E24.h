//
//  action.h
//  lut-lang
//
<<<<<<< HEAD
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
=======
//  Created by Mehdi Kitane on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

>>>>>>> 9b0624d56118d69be55a91f187e56db1948ef7b7
#ifndef SRC_STATES_E24_H_
#define SRC_STATES_E24_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E24 : public State {
<<<<<<< HEAD
 public :
    E24();
    bool transition(Automaton *automaton, ASTTokenNode *t);
    inline int stateNumber(){return 24;}
=======
public:
  E24();
  bool transition(Automaton *automaton, ASTTokenNode *t);
  inline int stateNumber(){return 24;}
>>>>>>> 9b0624d56118d69be55a91f187e56db1948ef7b7
};

#endif  // SRC_STATES_E24_H_
