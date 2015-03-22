//
//  ASTEnumAssignNode.h
//  lut-lang
//
//  Created by Robin Ricard on 22/03/15.
//  Copyright (c) 2015 INSA Lyon. All rights reserved.
//

#ifndef SRC_ASTENUMASSIGNNODE_H_
#define SRC_ASTENUMASSIGNNODE_H_

#include "ASTNode.h"
#include "ASTNode.h"
#include "ASTTokenNode.h"

/**
 * @class
 * Defines an enumeration of const assignments
 */
class ASTEnumAssignNode : public ASTNode {
public:
  /**
   * @constructor
   * @param identifier The const identifier
   * @param value The assigned value
   * @param next The next declaration in the enum
   */
  explicit ASTEnumAssignNode(ASTTokenNode* identifier,
                             ASTTokenNode* value,
                             ASTEnumAssignNode* next = NULL);
  
  /**
   * @return The variable identifier
   */
  ASTTokenNode* getIdentifier();
  
  /**
   * @return The assigned value
   */
  ASTTokenNode* getValue();

  
  /**
   * @return Next enum element or Null
   */
  ASTEnumAssignNode* getNext();
  
  virtual bool analyze();
  virtual void exec();
  
private:
  ASTTokenNode* identifier;
  ASTTokenNode* value;
  ASTEnumAssignNode* next;
};

#endif  // SRC_ASTENUMASSIGNNODE_H_
