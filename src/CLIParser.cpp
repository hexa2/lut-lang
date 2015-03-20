#include "CLIParser.h"

#define OPT_TRANSFORM "-o"
#define OPT_PRINT "-p"
#define OPT_STATIC "-a"
#define OPT_EXEC "-e"

#define ERR_NOARGS "Erreur, veuillez specifier des arguments\n"\
"  Utilisation :\n"\
"    ../lut [-p] [-a] [-e] [-o] source.lt\n"\
"      [-p] affiche le code source reconnu\n"\
"      [-a] analyse le programme de maniere statique\n"\
"      [-e] execute interactivement le programme\n"\
"      [-o] optimise les expressions et instructions\n"

#define ERR_READFILE "Erreur a l'ouverture du fichier "

CLIParser::CLIParser(int argc, char* argv[])
{
  transformEnabled = false;
  printEnabled = false;
  staticEnabled = false;
  execEnabled = false;
  fileName = NULL;
  
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
}

string CLIParser::getInputFile() {
  if (fileName == NULL) {
    cerr << ERR_NOARGS << endl;
    exit(1);
  }
  
  string inputFile = readFile(*fileName);
  
  if (inputFile.empty()) {
    exit(1);
  }
  
  return inputFile;
}

string CLIParser::readFile(string fileName)
{
  ifstream fileStream(fileName.c_str());
  if (fileStream.fail()) {
    cerr << ERR_READFILE << fileName << endl;
    exit(1);
  }
  
  stringstream buffer;
  buffer << fileStream.rdbuf();
  
  return buffer.str();
}

bool CLIParser::transformIsEnabled()
{
  return transformEnabled;
}

bool CLIParser::printIsEnabled()
{
  return  printEnabled;
}

bool CLIParser::staticIsEnabled()
{
  return staticEnabled;
}

bool CLIParser::execIsEnabled()
{
  return execEnabled;
}
