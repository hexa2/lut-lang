lut-lang
========

[![Circle CI](https://circleci.com/gh/hexa2/lut-lang/tree/master.svg?style=svg)](https://circleci.com/gh/hexa2/lut-lang/tree/master)

Lutin Language Interpreter

Installation
------------

```
git clone git@github.com:hexa2/lut-lang.git
cd lut-lang
make
make test # test your code
python cpplint.py src/* # check styleguide
```

Usage
-----

```
./bin/lut <LUT-FILE> \
  -o # Optimize/Transform code \
  -p # Print transformed code \
  -a # Static Analysis \
  -e # Execute/interpret code
```

Terminal symbols
-------

 + `var` : variable
 + `const` : constant
 + `id` : variable name
 + `val` : positive value


Non terminal symbols
------

 + `P` : Program
 + `D` : DeclarationBlock
 + `L1` : EnumDecl
 + `L2` : EnumAssign
 + `I` : InstructionBlock
 + `E` : FirstLevelExpression
 + `T` : SecondLevelExpression
 + `F` : ThirdLevelExpression
 + `opA` : AdditiveOperation
 + `opM` : MultiplicativeOperation

Grammar Rules
-------

 + 1: `P -> D I`
 + 2: `D -> D var id L1 ;`
 + 3: `D -> D const id = val L2 ;`
 + 4: `D -> eps`
 + 5: `L1 -> L1 , id`
 + 6: `L1 -> eps`
 + 7: `L2 -> L2 , id`
 + 8: `L2 -> eps`
 + 9: `I -> I = E ;`
 + 10: `I -> I li id ;`
 + 11: `I id := E ;`
 + 12: `I -> eps`
 + 13: `E -> E opA T`
 + 14: `E -> T`
 + 15: `T -> T opM F`
 + 16: `T -> F`
 + 17: `F -> id`
 + 18: `F -> val`
 + 19: `F -> ( E )`
 + 20: `opA -> +`
 + 21: `opA -> -`
 + 22: `opM -> *`
 + 23: `opM -> /`

That's all, folks and guys !
