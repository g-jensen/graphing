#include "divideNode.h"

divideNode::divideNode() {

}

divideNode::divideNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float divideNode::eval(float variable) {
    return left->eval(variable) / right->eval(variable);
}