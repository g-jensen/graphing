#pragma once

#include "exprNode.h"
#include <math.h>

class cosNode : public exprNode {
public:
    cosNode();
    cosNode(exprNode* input);
    float eval(float variable);
};