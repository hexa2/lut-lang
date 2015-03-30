/* Copyright 2015 H4314, MIT License */
#include <iostream>
#include <string>
#include "Automaton.h"

#include "CLIParser.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {
  CLIParser* cliParser = new CLIParser(argc, argv);
  string inputFile = cliParser->getInputFile();

  Automaton *automaton = new Automaton(inputFile);
  if (cliParser->transformIsEnabled()) {
    cout << "Transform (optimize) input" << endl;
    // TRANSFORM
  }
  if (cliParser->printIsEnabled()) {
    automaton->print();
  }
  if (cliParser->staticIsEnabled()) {
    if (!automaton->analyze()) {
#warning add analyze failed message
      return 1;
    }
  }
  if (cliParser->execIsEnabled()) {
    automaton->execute();
  }

  return 0;
}
