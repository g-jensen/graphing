#include "cosNode.h"

cosNode::cosNode() {

}

cosNode::cosNode(exprNode* input) : exprNode(input, nullptr) {
}

float cosNode::eval(float variable) {
    return cos(left->eval(variable));
}