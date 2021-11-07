#include "tanNode.h"

tanNode::tanNode() {

}

tanNode::tanNode(exprNode* input) : exprNode(input, nullptr) {
}

float tanNode::eval(float variable) {
    return tan(left->eval(variable));
}