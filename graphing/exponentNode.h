#pragma once

#include "exprNode.h"
#include <tgmath.h>

class exponentNode : public exprNode {
public:
    exponentNode();
    exponentNode(exprNode* left, exprNode* right);
    float eval(float variable);
};