# gcc settings
CC = g++
CFLAGS = -DDEBUG -g -Wall -O3 -std=c++0x -lboost_regex
LNFLAGS = -lboost_regex

# src
BIN_SRC = lut.cpp
SRC = Lexer.cpp Automaton.cpp CLIParser.cpp ASTNode.cpp ASTTokenNode.cpp ASTEnumDeclNode.cpp ASTEnumAssignNode.cpp ASTDeclarationBlockNode.cpp ASTMultiplicativeOperation.cpp ASTAdditiveOperation.cpp ASTFirstLevelExpressionNode.cpp ASTSecondLevelExpressionNode.cpp ASTThirdLevelExpressionNode.cpp ASTInstructionBlockNode.cpp ASTProgramNode.cpp states/E0.cpp states/E1.cpp states/E2.cpp states/E3.cpp states/E4.cpp states/E5.cpp states/E6.cpp states/E7.cpp states/E8.cpp states/E9.cpp states/E10.cpp states/E11.cpp states/E12.cpp states/E13.cpp states/E14.cpp states/E15.cpp states/E16.cpp states/E17.cpp states/E18.cpp states/E19.cpp states/E20.cpp states/E21.cpp states/E22.cpp states/E23.cpp states/E24.cpp states/E25.cpp states/E26.cpp states/E27.cpp states/E28.cpp states/E29.cpp states/E30.cpp states/E31.cpp states/E32.cpp states/E33.cpp states/E34.cpp states/E35.cpp states/E36.cpp states/E37.cpp states/E38.cpp states/E39.cpp states/E40.cpp states/E41.cpp states/E42.cpp states/E43.cpp states/E44.cpp ErrorHandler.cpp

# obj
BIN_OBJ = $(BIN_SRC:%.cpp=bin/%)
OBJ = $(SRC:%.cpp=objects/%.o)

# phonies
.PHONY: clean test

all: build

clean:
	rm -rf bin/ objects/

tests/lut: bin/lut
	rm -f ./tests/lut
	ln -s ../bin/lut ./tests/lut
	chmod +x tests/lut

test: tests/lut
	cd tests; sh mktest.sh

build: $(BIN_OBJ)

# patterns
bin/%: objects/%.o $(OBJ)
	mkdir -p `dirname $@`
	$(CC) -o $@ $^ $(LNFLAGS)

objects/%.o: src/%.cpp
	mkdir -p `dirname $@`
	$(CC) -c $(CFLAGS) -o $@ $<

