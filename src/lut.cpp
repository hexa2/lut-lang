#include <string.h>
#include <iostream>

#define OPT_TRANSFORM "-o"
#define OPT_PRINT "-p"
#define OPT_STATIC "-a"
#define OPT_EXEC "-e"

using namespace std;

int main(int argc, char* argv[]) {
  bool transformEnabled = false;
  bool printEnabled = false;
  bool staticEnabled = false;
  bool execEnabled = false;
  char* fileName = NULL;

  for(int i = 1; i < argc; i++) {
    char* arg = argv[i];
    if(strcmp(arg, OPT_TRANSFORM)) {
      transformEnabled = true;
    } else if(strcmp(arg, OPT_PRINT)) {
      printEnabled = true;
    } else if(strcmp(arg, OPT_STATIC)) {
      staticEnabled = true;
    } else if(strcmp(arg, OPT_EXEC)) {
      execEnabled = true;
    } else {
      fileName = arg;
    }
  }

  if(fileName == NULL) {
    cerr << "No input file provided";
    return 1;
  }

  // LEXER
  // PARSER
  if(transformEnabled) {
    // TRANSFORM
  }
  if(printEnabled) {
    // PRINT
  }
  if(staticEnabled) {
    // STATIC
  }
  if(execEnabled) {
    // EXEC
  }

  return 0;
}
