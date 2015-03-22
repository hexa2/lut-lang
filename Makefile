# gcc settings
CC = g++
CFLAGS = -DDEBUG -g -Wall -O3 -std=c++0x
LNFLAGS =

# src
BIN_SRC = lut.cpp
SRC = Lexer.cpp ASTTokenNode.cpp ASTEnumDeclNode.cpp ASTEnumAssignNode.cpp ASTDeclarationBlockNode.cpp ASTMultiplicativeOperation.cpp ASTAdditiveOperation.cpp ASTFirstLevelExpressionNode.cpp ASTSecondLevelExpressionNode.cpp ASTThirdLevelExpressionNode.cpp ASTInstructionBlockNode.cpp ASTProgramNode.cpp Automaton.cpp Action.cpp State.cpp

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

