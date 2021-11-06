#pragma once

#include "exprNode.h"
#include <math.h>

class sinNode : public exprNode {
public:
    sinNode();
    sinNode(exprNode* input);
    float eval(float variable);
};