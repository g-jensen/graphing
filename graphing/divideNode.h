#pragma once

#include "exprNode.h"

class divideNode : public exprNode {
public:
    divideNode();
    divideNode(exprNode* left, exprNode* right);
    float eval();
};