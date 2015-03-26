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

/**
 * @class
 * CLI parser and file reader
 */
class CLIParser {
 public:
  /**
   * @constructor
   * @param argc Arguments count
   * @param argv Arguments values
   */
  CLIParser(int argc, char* argv[]);

  /**
   * @return Returns input file content in a string if file exists
   *
   */
  string getInputFile();

  /**
   * @return Returns true if transform option is enabled
   *
   */
  bool transformIsEnabled();

  /**
   * @return Returns true if print option is enabled
   *
   */
  bool printIsEnabled();

  /**
   * @return Returns true if static option is enabled
   *
   */
  bool staticIsEnabled();

  /**
   * @return Returns true if exec option is enabled
   *
   */
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
