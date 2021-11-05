#include "addNode.h"

addNode::addNode() {

}

addNode::addNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float addNode::eval() {
    return left->eval() + right->eval();
}