/* Copyright 2015 H4314, MIT License */
#include <iostream>
#include <string>
#include "Automaton.h"

#include "CLIParser.h"

using std::cout;
using std::endl;


void test() {
  // Test affectation variable
  Automaton *automate = new Automaton ("var b; b:=8;");
  cout << " // Test affectation variable : ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;

  // Test variables multiples
  automate = new Automaton ("var b, coucou, micheline;");
  cout << " // Test variables multiples : ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;

  // Test constante et affectation
  automate = new Automaton ("const coucou=10;");
  cout << " // Test constante et affectation : ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;

  // Test constantes multiples et affectation
  automate = new Automaton ("const b=2012, coucou=42, micheline=1664;");
  cout << " // Test constantes multiples et affectations: ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;

  // Test ecriture simple
  automate = new Automaton ("ecrire b;");
  cout << " // Test ecriture simple : ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;

  // Test ecriture complexe
  automate = new Automaton ("ecrire ((4-2)+b);");
  cout << " // Test ecriture complexe : ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;

  // Test lecture simple
  automate = new Automaton ("lire b;");
  cout << " // Test lecture simple : ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;

  // Test affectation variable avec expression
  automate = new Automaton ("b := (4+2);");
  cout << " // Test affectation variable avec expression : ";
  if (automate->analyze()) {
    cout << "Ca marche" << endl;
  } else {
    cout << "Marche pas" << endl;
  }
  delete automate;
}
int main(int argc, char* argv[]) {
  test();
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
