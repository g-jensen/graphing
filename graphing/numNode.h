#pragma once

#include "exprNode.h"

class numNode : public exprNode {
public:
    numNode();
    numNode(float val);
    float eval(float variable);
protected:
    float val;
};