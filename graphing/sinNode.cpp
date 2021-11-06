#include "sinNode.h"

sinNode::sinNode() {

}

sinNode::sinNode(exprNode* input) : exprNode(input,nullptr) {
}

float sinNode::eval(float variable) {
    return sin(left->eval(variable));
}