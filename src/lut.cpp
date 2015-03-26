/* Copyright 2015 H4314, MIT License */
#include <iostream>
#include <string>
#include "Automaton.h"

#define OPT_TRANSFORM "-o"
#define OPT_PRINT "-p"
#define OPT_STATIC "-a"
#define OPT_EXEC "-e"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {
    
    
    //Test affectation variable
    Automaton *automate = new Automaton ("var b; b:=8;");
    cout << " // Test affectation variable : ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
    
    //Test variables multiples
    automate = new Automaton ("var b, coucou, micheline;");
    cout << " // Test variables multiples : ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
    
    //Test constante et affectation
    automate = new Automaton ("const coucou=10;");
    cout << " // Test constante et affectation : ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
    
    //Test constantes multiples et affectation
    automate = new Automaton ("const b=2012, coucou=42, micheline=1664;");
    cout << " // Test constantes multiples et affectations: ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
    
    //Test ecriture simple
    automate = new Automaton ("ecrire b;");
    cout << " // Test ecriture simple : ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
    
    //Test ecriture complexe
    automate = new Automaton ("ecrire (4/2)*b;");
    cout << " // Test ecriture complexe : ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
    
    //Test lecture simple
    automate = new Automaton ("lire b;");
    cout << " // Test lecture simple : ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
  
    //Test affectation variable avec expression
    automate = new Automaton ("b := 4+2;");
    cout << " // Test affectation variable avec expression : ";
    if( automate->analyze()){
        cout<<"Ca marche"<<endl;
    }else{
        cout<<"Marche pas"<<endl;
    }
    delete automate;
    
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
    cerr << "No input file provided" << endl;
    return 1;
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
