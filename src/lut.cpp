/* Copyright 2015 H4314, MIT License */
#include <iostream>
#include <string>
#include "Automaton.h"

#include "CLIParser.h"
#include "ErrorHandler.h"
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {
  CLIParser* cliParser = new CLIParser(argc, argv);
  string inputFile = cliParser->getInputFile();

  Automaton *automaton = new Automaton(inputFile);
  if (!automaton->build_program()) {
    ErrorHandler::getInstance().outputErrors();
    return 0;
  }

  if (cliParser->transformIsEnabled()) {
    // TRANSFORM AND OPTIMIZE
    automaton->transform();
  }
  if (cliParser->printIsEnabled()) {
    automaton->print();
  }
  if (cliParser->staticIsEnabled()) {
    if (!automaton->analyze()) {
      ErrorHandler::getInstance().outputErrors();
      return 0;
    }
  }
  if (cliParser->execIsEnabled()) {
    automaton->execute();
  }
  ErrorHandler::getInstance().outputErrors();
  
  return 0;
}
