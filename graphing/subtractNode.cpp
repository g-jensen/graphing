#include "subtractNode.h"

subtractNode::subtractNode() {

}

subtractNode::subtractNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float subtractNode::eval(float variable) {
    return left->eval(variable) - right->eval(variable);
}