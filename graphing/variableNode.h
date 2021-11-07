#pragma once

#include "exprNode.h"

class variableNode : public exprNode {
public:
    variableNode();
    float eval(float input);
};