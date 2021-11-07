#pragma once

#include "exprNode.h"

class multNode : public exprNode {
public:
    multNode();
    multNode(exprNode* left, exprNode* right);
    float eval(float variable);
};