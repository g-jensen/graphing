#pragma once

#include "exprNode.h"
#include <math.h>

class tanNode : public exprNode {
public:
    tanNode();
    tanNode(exprNode* input);
    float eval(float variable);
};