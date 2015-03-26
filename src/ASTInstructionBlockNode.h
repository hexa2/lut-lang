//
//  ASTInstructionBlockNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTINSTRUCTIONBLOCKNODE_H_
#define SRC_ASTINSTRUCTIONBLOCKNODE_H_

#include <cstdint>
using std::int64_t;

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
   * @param prev The prev instruction
   */
  ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                          ASTInstructionBlockNode* prev = NULL);

  /**
   * @constructor
   * Read variable constructor
   * @param identifier The variable identifier
   * @param prev The prev instruction
   */
  ASTInstructionBlockNode(ASTTokenNode* identifier,
                          ASTInstructionBlockNode* prev = NULL);

  /**
   * @constructor
   * Assignment constructor
   * @param expression The expression to assign
   * @param identifier The variable identifier to be assigned
   * @param prev The prev instruction
   */
  ASTInstructionBlockNode(ASTFirstLevelExpressionNode* expression,
                          ASTTokenNode* identifier,
                          ASTInstructionBlockNode* prev = NULL);

  /**
   * @return An expression used for either assignment or output or Null
   */
  ASTFirstLevelExpressionNode* getExpression();

  /**
   * @return An identifier used for either reading input or assignment or Null
   */
  ASTTokenNode* getIdentifier();

  /**
   * @return The prev instruction or Null
   */
  ASTInstructionBlockNode* getPrev();

  virtual bool analyze(analyze_table* table);
  virtual int64_t exec(exec_table* table);
  virtual void print();

 private:
  ASTFirstLevelExpressionNode* expression;
  ASTTokenNode* identifier;
  ASTInstructionBlockNode* prev;
};

#endif  // SRC_ASTINSTRUCTIONBLOCKNODE_H_
