//
//  ASTInstructionBlockNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTINSTRUCTIONBLOCKNODE_H_
#define SRC_ASTINSTRUCTIONBLOCKNODE_H_

#include "ASTNode.h"
#include "ASTFirstLevelExpressionNode.h"
#include "ASTTokenNode.h"

/**
 * @class
 * An instruction line
 */
class ASTInstructionBlockNode : public ASTNode {
 public:
  /**
   * @constructor
   * Write expression constructor
   * @param expression The expression to write
   * @param next The next instruction
   */
  ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                          ASTInstructionBlockNode* next = NULL);

  /**
   * @constructor
   * Read variable constructor
   * @param identifier The variable identifier
   * @param next The next instruction
   */
  ASTInstructionBlockNode(ASTTokenNode* identifier,
                          ASTInstructionBlockNode* next = NULL);

  /**
   * @constructor
   * Assignment constructor
   * @param expression The expression to assign
   * @param identifier The variable identifier to be assigned
   * @param next The next instruction
   */
  ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                          ASTTokenNode* identifier,
                          ASTInstructionBlockNode* next = NULL);

  /**
   * @return An expression used for either assignment or output or Null
   */
  ASTFirstLevelExpressionNode* getExpression();

  /**
   * @return An identifier used for either reading input or assignment or Null
   */
  ASTTokenNode* getIdentifier();

  /**
   * @return The next instruction or Null
   */
  ASTInstructionBlockNode* getNext();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTFirstLevelExpressionNode* expression;
  ASTTokenNode* identifier;
  ASTInstructionBlockNode* next;
};

#endif  // SRC_ASTINSTRUCTIONBLOCKNODE_H_
