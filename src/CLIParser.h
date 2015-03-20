//
//  CLIParser.h
//  lut-lang
//
//  Created by Karim Benhmida on 06/03/2015.
//  Copyright (c) 2015 H4314. All rights reserved.
//

#ifndef SRC_CLIPARSER_H_
#define SRC_CLIPARSER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::fstream;
using std::stringstream;
using std::ifstream;
using std::cerr;
using std::endl;

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
#endif  // SRC_CLIPARSER_H_
