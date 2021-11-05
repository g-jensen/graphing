#pragma once

#include "exprNode.h"

class addNode : public exprNode {
public:
    addNode();
    addNode(exprNode* left, exprNode* right);
    float eval();
};