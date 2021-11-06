#include "addNode.h"

addNode::addNode() {

}

addNode::addNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float addNode::eval(float variable) {
    return left->eval(variable) + right->eval(variable);
}