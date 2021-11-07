#include "exprNode.h"

exprNode::exprNode() {

}

exprNode::exprNode(exprNode* left, exprNode* right) : left(left), right(right) {
}

exprNode::~exprNode() {
    delete left;
    delete right;
}