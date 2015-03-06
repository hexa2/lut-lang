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

That's all, folks and guys !
