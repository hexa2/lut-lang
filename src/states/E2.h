//
//  action.h
//  lut-lang
//
<<<<<<< HEAD
//  Created by Valentin Comte on 23/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//
=======
//  Created by Kevin Antoine on 15/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

>>>>>>> 9b0624d56118d69be55a91f187e56db1948ef7b7
#ifndef SRC_STATES_E2_H_
#define SRC_STATES_E2_H_

#include "../State.h"
#include "../ASTTokenNode.h"
#include "../Automaton.h"

class E2 : public State {
<<<<<<< HEAD
 public :
=======
 public:
>>>>>>> 9b0624d56118d69be55a91f187e56db1948ef7b7
    E2();
    bool transition(Automaton *automaton, ASTTokenNode *t);
    inline int stateNumber(){return 2;}
};

<<<<<<< HEAD
#endif  // SRC_STATES_E2_H_
=======
#endif  //  SRC_STATES_E2_H_
>>>>>>> 9b0624d56118d69be55a91f187e56db1948ef7b7
