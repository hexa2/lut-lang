/* Copyright 2015 H4314, MIT License */
#include <iostream>
#include <string>

#include "CLIParser.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  CLIParser* cliParser = new CLIParser(argc, argv);
  string inputFile = cliParser->getInputFile();

  if (cliParser->transformIsEnabled()) {
    cout << "Transform (optimize) input" << endl;
    // TRANSFORM
  }
  if (cliParser->printIsEnabled()) {
    cout << "Print (transformed?) input" << endl;
    // PRINT
  }
  if (cliParser->staticIsEnabled()) {
    cout << "Analyze statically" << endl;
    // STATIC
  }
  if (cliParser->execIsEnabled()) {
    cout << "Execute" << endl;
    // EXEC
  }

  return 0;
}
