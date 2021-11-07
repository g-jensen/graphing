#include "exponentNode.h"

exponentNode::exponentNode() {

}

exponentNode::exponentNode(exprNode* left, exprNode* right) : exprNode(left, right) {
}

float exponentNode::eval(float variable) {
    return pow(left->eval(variable),right->eval(variable));
}