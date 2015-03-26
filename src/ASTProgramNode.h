//
//  ASTProgramNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTPROGRAMNODE_H_
#define SRC_ASTPROGRAMNODE_H_

#include "ASTNode.h"
#include "ASTDeclarationBlockNode.h"
#include "ASTInstructionBlockNode.h"

class ASTProgramNode : public ASTNode {
 public:
  /**
   * @constructor
   * @param declarations The declaration block
   * @param instructions The instruction block
   */
  ASTProgramNode(ASTDeclarationBlockNode* declarations = NULL,
                 ASTInstructionBlockNode* instructions = NULL);

  /**
   * @return The declaration block
   */
  ASTDeclarationBlockNode* getDeclarations();

  /**
   * @return The instruction block
   */
  ASTInstructionBlockNode* getInstructions();

  virtual bool analyze();
  virtual void exec();

 private:
  ASTDeclarationBlockNode* declarations;
  ASTInstructionBlockNode* instructions;
};

#endif  // SRC_ASTPROGRAMNODE_H_
