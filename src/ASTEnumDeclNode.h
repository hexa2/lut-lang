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
   * @param prev The prev declaration in the enum
   */
  explicit ASTEnumDeclNode(ASTTokenNode* identifier,
                           ASTEnumDeclNode* prev = NULL,
                           TokenType type = TokenType::L1);

  /**
   * @return The variable identifier
   */
  ASTTokenNode* getIdentifier();

  /**
   * @return prev enum element or Null
   */
  ASTEnumDeclNode* getPrev();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* identifier;
  ASTEnumDeclNode* prev;
};


#endif  // SRC_ASTENUMDECLNODE_H_
