#include "multNode.h"

multNode::multNode() {

}

multNode::multNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float multNode::eval(float variable) {
    return left->eval(variable) * right->eval(variable);
}