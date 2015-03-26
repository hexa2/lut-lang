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
   * @param enumVars The prev variables to enum
   * @param prev The prev declaration in the block
   */
  explicit ASTDeclarationBlockNode(ASTTokenNode* varIdentifier,
                                   ASTEnumDeclNode* enumVars = NULL,
                                   ASTDeclarationBlockNode* prev = NULL);

  /**
   * @constructor
   * @param constIdentifier The constant identifier
   * @param constValue The constant value
   * @param enumConsts The prev constants to enum
   * @param prev The prev declaration in the block
   */
  explicit ASTDeclarationBlockNode(ASTTokenNode* constIdentifier,
                                   ASTTokenNode* constValue,
                                   ASTEnumAssignNode* enumConsts = NULL,
                                   ASTDeclarationBlockNode* prev = NULL);

  /**
   * @return The variable identifier or Null
   */
  ASTTokenNode* getVarIdentifier();

  /**
   * @return The prev variables to enum or Null
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
   * @return The prev consts to enum or Null
   */
  ASTEnumAssignNode* getEnumConsts();

  /**
   * @return prev enum element or Null
   */
  ASTDeclarationBlockNode* getPrev();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTTokenNode* varIdentifier;
  ASTEnumDeclNode* enumVars;
  ASTTokenNode* constIdentifier;
  ASTTokenNode* constValue;
  ASTEnumAssignNode* enumConsts;
  ASTDeclarationBlockNode* prev;
};



#endif  // SRC_ASTDECLARATIONBLOCKNODE_H_
