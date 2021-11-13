#pragma once

#include "exprNode.h"

class subtractNode : public exprNode {
public:
    subtractNode();
    subtractNode(exprNode* left, exprNode* right);
    float eval(float variable);
};