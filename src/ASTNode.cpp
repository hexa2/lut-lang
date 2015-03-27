// Copyright 2015 H4314
#include "ASTNode.h"

#include <string>


ASTNode::ASTNode(TokenType type) : type(type){
}

TokenType ASTNode::getTokenType(){
  return this->type;
}
