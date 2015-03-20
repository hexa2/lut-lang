//
//  CLIParser.h
//  lut-lang
//
//  Created by Karim Benhmida on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef CLIPARSER_H_
#define CLIPARSER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class CLIParser {
 public:
  CLIParser(int argc, char* argv[]);
  string getInputFile();
  bool transformIsEnabled();
  bool printIsEnabled();
  bool staticIsEnabled();
  bool execIsEnabled();
 protected:
  string readFile(string fileName);
  bool transformEnabled;
  bool printEnabled;
  bool staticEnabled;
  bool execEnabled;
  string* fileName;
};
#endif  // CLIPARSER_H_
