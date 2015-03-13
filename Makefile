# gcc settings
CC = g++
CFLAGS = -DDEBUG -g -Wall -O3
LNFLAGS =

# src
BIN_SRC = lut.cpp
SRC = lexer.cpp ASTTerminalIdentifierNode.cpp

# obj
BIN_OBJ = $(BIN_SRC:%.cpp=bin/%)
OBJ = $(SRC:%.cpp=objects/%.o)

# phonies
.PHONY: clean test

all: build

clean:
	rm -rf bin/ objects/

test:
	cd tests; sh mktest.sh

build: $(BIN_OBJ)

# patterns
bin/%: objects/%.o $(OBJ)
	mkdir -p `dirname $@`
	$(CC) -o $@ $^ $(LNFLAGS)

objects/%.o: src/%.cpp
	mkdir -p `dirname $@`
	$(CC) -c $(CFLAGS) -o $@ $<
