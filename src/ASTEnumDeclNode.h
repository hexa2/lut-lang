// Copyright 2015 H4314

#ifndef SRC_ASTENUMDECLNODE_H_
#define SRC_ASTENUMDECLNODE_H_

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
   * @param identifier The variable identifier
   * @param next The next declaration in the enum
   */
  explicit ASTEnumDeclNode(ASTTokenNode* identifier,
                           ASTEnumDeclNode* next = NULL);

  /**
   * @return The variable identifier
   */
  ASTTokenNode* getIdentifier();

  /**
   * @return Next enum element or Null
   */
  ASTEnumDeclNode* getNext();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* identifier;
  ASTEnumDeclNode* next;
};


#endif  // SRC_ASTENUMDECLNODE_H_
