/* Copyright 2015 H4314, MIT License */
#include <iostream>
#include <string>

#define OPT_TRANSFORM "-o"
#define OPT_PRINT "-p"
#define OPT_STATIC "-a"
#define OPT_EXEC "-e"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {
  bool transformEnabled = false;
  bool printEnabled = false;
  bool staticEnabled = false;
  bool execEnabled = false;
  string* fileName = NULL;

  for (int i = 1; i < argc; i++) {
    string* arg = new string(argv[i]);
    if (arg->compare(OPT_TRANSFORM) == 0) {
      transformEnabled = true;
      delete arg;
    } else if (arg->compare(OPT_PRINT) == 0) {
      printEnabled = true;
      delete arg;
    } else if (arg->compare(OPT_STATIC) == 0) {
      staticEnabled = true;
      delete arg;
    } else if (arg->compare(OPT_EXEC) == 0) {
      execEnabled = true;
      delete arg;
    } else {
      fileName = arg;
    }
  }

  if (fileName == NULL) {
      string errorMessage = "Erreur, veuillez specifier des arguments\n\
  Utilisation :\n\
    ../lut [-p] [-a] [-e] [-o] source.lt\n\
      [-p] affiche le code source reconnu\n\
      [-a] analyse le programme de maniere statique\n\
      [-e] execute interactivement le programme\n\
      [-o] optimise les expressions et instructions\n";
      
    cerr << errorMessage << endl;
    return 0;
  }

  // LEXER
  // PARSER
  if (transformEnabled) {
    cout << "Transform (optimize) input" << endl;
    // TRANSFORM
  }
  if (printEnabled) {
    cout << "Print (transformed?) input" << endl;
    // PRINT
  }
  if (staticEnabled) {
    cout << "Analyze statically" << endl;
    // STATIC
  }
  if (execEnabled) {
    cout << "Execute" << endl;
    // EXEC
  }

  return 0;
}
