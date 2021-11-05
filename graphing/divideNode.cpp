#include "divideNode.h"

divideNode::divideNode() {

}

divideNode::divideNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float divideNode::eval() {
    return left->eval() / right->eval();
}