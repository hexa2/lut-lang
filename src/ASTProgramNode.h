//
//  ASTProgramNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTPROGRAMNODE_H_
#define SRC_ASTPROGRAMNODE_H_

#include <cstdint>
using std::int64_t;

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
                 ASTInstructionBlockNode* instructions = NULL,
                 TokenType type = TokenType::P);

  /**
   * @return The declaration block
   */
  ASTDeclarationBlockNode* getDeclarations();

  /**
   * @return The instruction block
   */
  ASTInstructionBlockNode* getInstructions();

  virtual bool analyze(analyze_table* table);
  virtual int64_t exec(exec_table* table);
  virtual void print();

 private:
  ASTDeclarationBlockNode* declarations;
  ASTInstructionBlockNode* instructions;
};

#endif  // SRC_ASTPROGRAMNODE_H_
