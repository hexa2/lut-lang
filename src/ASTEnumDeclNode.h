// Copyright 2015 H4314

#ifndef _LUT_LANG_ASTENUMDECLNODE_H_
#define _LUT_LANG_ASTENUMDECLNODE_H_

#include "ASTNode.h"
#include "ASTTokenNode.h"

/**
 * @class
 * Defines an enumeration of variable declarations
 */
class ASTEnumDeclNode : public ASTNode {
 public:
  /**
   * @constructor
   * @param varName The variable name token
   * @param identifier The variable assigned identifier
   */
  ASTEnumDeclNode(ASTTokenNode* varName, ASTTokenNode* identifier);
  
  /**
   * @constructor
   * @param varName The variable name token
   * @param identifier The variable assigned identifier
   * @param next The next declaration in the enum
   */
  ASTEnumDeclNode(ASTTokenNode* varName, ASTTokenNode* identifier,
                  ASTEnumDeclNode* next);
  
  /**
   * @return The variable name token
   */
  ASTTokenNode* getVarName();
  
  /**
   * @return The variable assigned identifier
   */
  ASTTokenNode* getIdentifier();
  
  /**
   * @return Next enum element or Null
   */
  ASTEnumDeclNode* getNext();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* varName;
  ASTTokenNode* identifier;
  ASTEnumDeclNode* next;
};


#endif //_LUT_LANG_ASTENUMDECLNODE_H_
