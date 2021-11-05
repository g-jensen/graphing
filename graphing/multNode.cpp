#include "multNode.h"

multNode::multNode() {

}

multNode::multNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float multNode::eval() {
    return left->eval() * right->eval();
}