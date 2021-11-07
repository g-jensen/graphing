#pragma once

class exprNode {
public:
    exprNode();
    exprNode(exprNode* left, exprNode* right);
    ~exprNode();
    virtual float eval(float variable) = 0;
protected:
    exprNode* left;
    exprNode* right;
};