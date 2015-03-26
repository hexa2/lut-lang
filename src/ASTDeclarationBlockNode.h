//
//  ASTDeclarationBlockNode.h
//  lut-lang
//
//  Created by Robin Ricard on 20/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTDECLARATIONBLOCKNODE_H_
#define SRC_ASTDECLARATIONBLOCKNODE_H_

#include "ASTNode.h"
#include "ASTTokenNode.h"
#include "ASTEnumDeclNode.h"
#include "ASTEnumAssignNode.h"

/**
 * @class
 * Defines a declaration block
 */
class ASTDeclarationBlockNode : public ASTNode {
 public:
  /**
   * @constructor
   * @param varIdentifier The variable identifier
   * @param enumVars The next variables to enum
   * @param next The next declaration in the block
   */
  explicit ASTDeclarationBlockNode(ASTTokenNode* varIdentifier,
                                   ASTEnumDeclNode* enumVars = NULL,
                                   ASTDeclarationBlockNode* next = NULL);

  /**
   * @constructor
   * @param constIdentifier The constant identifier
   * @param constValue The constant value
   * @param enumConsts The next constants to enum
   * @param next The next declaration in the block
   */
  explicit ASTDeclarationBlockNode(ASTTokenNode* constIdentifier,
                                   ASTTokenNode* constValue,
                                   ASTEnumAssignNode* enumConsts = NULL,
                                   ASTDeclarationBlockNode* next = NULL);

  /**
   * @return The variable identifier or Null
   */
  ASTTokenNode* getVarIdentifier();

  /**
   * @return The next variables to enum or Null
   */
  ASTEnumDeclNode* getEnumVars();

  /**
   * @return The const identifier or Null
   */
  ASTTokenNode* getConstIdentifier();

  /**
   * @return The const assignment value or Null
   */
  ASTTokenNode* getConstValue();

  /**
   * @return The next consts to enum or Null
   */
  ASTEnumAssignNode* getEnumConsts();

  /**
   * @return Next enum element or Null
   */
  ASTDeclarationBlockNode* getNext();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* varIdentifier;
  ASTEnumDeclNode* enumVars;
  ASTTokenNode* constIdentifier;
  ASTTokenNode* constValue;
  ASTEnumAssignNode* enumConsts;
  ASTDeclarationBlockNode* next;
};



#endif  // SRC_ASTDECLARATIONBLOCKNODE_H_
